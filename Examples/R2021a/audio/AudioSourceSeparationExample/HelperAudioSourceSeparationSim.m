function [unmixedAudio, mixedAudioMono , audioIndexOut]  = HelperAudioSourceSeparationSim(tuningUIStruct)
% HELPERAUDIOSOURCESEPARATIONSIM implements panned audio source separation
% algorithm. This function instantiates, initializes and steps through the
% System objects used in the algorithm.
%
% You can tune simulation parameters through the UI that appears when
% pannedAudioSourceSeparationApp is executed.

%   Copyright 2014-2019 The MathWorks, Inc.

%#codegen

% Instantiate and initialize System objects and variables. The objects and
% variables are declared persistent so that they are not recreated every
% time the function is called inside the simulation loop.
persistent  reader1 reader2   ...
            runningWindowHistogram panningIndexSpace v epsilon ...
            panValue audioIndex stft istft
       
if isempty(reader1)
    % Audio readers
    reader1 = dsp.AudioFileReader('Filename',...
                                  'Counting-16-44p1-mono-15secs.wav',...
                                  'SamplesPerFrame',256,...
                                  'PlayCount',Inf);
    reader2 = dsp.AudioFileReader('Filename',...
                                  'TrainWhistle-16-44p1-mono-9secs.wav',...
                                  'SamplesPerFrame',256,...
                                  'PlayCount',Inf);           
    % Filter used to estimate histogram over a running window                           
    runningWindowHistogram  = dsp.FIRFilter('Numerator',ones(1,800));
    % Vector used to map histogram indices to panning indices
    panningIndexSpace = linspace(-1,1,100);
    
    % Gaussian window parameters:
    v = 1e-3;       % floor value
    epsilon = 1e-2; % window width

    % Index of audio source to play (1=mixed audio, 2=unmixed speech)
    audioIndex = 1;
    
    % pan value used for the speech source
    panValue = 0.4;
    
    % Create STFT and ISTFT objects
    stft = dsp.STFT(hann(2*256,'periodic'),256,512);
    istft = dsp.ISTFT(hann(2*256,'periodic'),256);
end

if tuningUIStruct.ValuesChanged
    params = tuningUIStruct.TuningValues;
    panValue   = params(1);
    audioIndex = params(2);
end

if tuningUIStruct.Reset
    % Reset objects
    reset(reader1);
    reset(reader2);
    reset(runningWindowHistogram);
end

% Read audio from the two sources
womanCount = reader1();
train      = reader2();

% Pan the sources
traintPan     =     [.8*train .2*train];
womanCountPan = [(1-panValue)*womanCount panValue*womanCount];

% Combine audio
mixedAudioStereo = womanCountPan + traintPan;
mixedAudioMono   = sum(mixedAudioStereo,2);

% Short-time FFT
mixedAudioFFT = stft(mixedAudioStereo);

chan1_FFT     = mixedAudioFFT(:,1);
chan2_FFT     = mixedAudioFFT(:,2);

% Compute frequency-domain correlations
correlations = abs([chan1_FFT chan1_FFT chan2_FFT chan2_FFT] .* conj([chan2_FFT chan1_FFT chan1_FFT chan2_FFT]));
P12          = correlations(:,1);
P11          = correlations(:,2);
P21          = correlations(:,3);
P22          = correlations(:,4);

% Similarity function
Similarity = 2 * P12 ./ (P11 + P22 + eps);

% Partial Similarity function
PY1    = P12 ./ (P11 + eps);
PY2    = P21 ./ (P22 + eps);
PY     = PY1 - PY2;
myMask = 2 * (PY > 0) - 1;

% Panning index
PanningIndex = myMask .* (1-Similarity);

% Detect panning indices
[panningHist,~] = histcounts(PanningIndex,100,'BinLimits',[-1,1], ...
                             'Normalization','probability');
runningPanningHist = runningWindowHistogram(panningHist.');
[~,sortedInd]      = sort(runningPanningHist,2,'descend');
panningVals        = sortedInd(1:2);

% Translate to panning index
val = panningIndexSpace(panningVals);
val = sort(val,2,'descend');

% Extract speech source
% Generate Gaussian Window
gaussianWindow = v + (1-v) * exp(-(PanningIndex - val(1) ).^2 ./ (2 * epsilon) ) + 1j *  zeros(size(PanningIndex));
% Apply Gaussian Window
audioChannels = (chan1_FFT+chan2_FFT) .* gaussianWindow;

% Inverse short-time FFT
unmixedAudio = istft(audioChannels); 

audioIndexOut = audioIndex;