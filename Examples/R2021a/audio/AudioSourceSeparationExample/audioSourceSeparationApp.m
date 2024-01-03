function scopeHandles = audioSourceSeparationApp(genCode,plotResults,numTSteps)
% PANNEDAUDIOSOURCESEPARATIONAPP Initialize and execute audio panned source
% separation example. The results are displayed using a scope. The function
% returns the handles to the scope and UI objects.
%
% Inputs:
%   genCode      - If true, use generated MEX file for simulation.
%                  Otherwise, use the MATLAB function. false if
%                  unspecified.
%   numTSteps    - Number of times the algorithm is executed in a loop. Inf
%                  if unspecified.
%   plotResults  - If true, the results are displayed on scopes. true if
%                  unspecified.
%
% Outputs:
%   scopeHandles    - If plotResults is true, handle to the visualization
%                     scope

% Copyright 2014-2017 The MathWorks, Inc.

% Default values for inputs
if nargin < 3
    numTSteps = Inf; % Run until user stops simulation. 
end
if nargin < 2
    plotResults = true; % Plot results
end
if nargin == 0
    genCode = false; % Do not generate code. 
end

% Create UI
param = struct([]);

param(1).Name = 'Panning Coefficient';
param(1).InitialValue = 0.4;
param(1).Limits = [0 1];

param(2).Name = 'Audio Output';
param(2).InitialValue = 1;
param(2).Values = {'Mixed Audio (Speech + train whistle)','Unmixed Speech Source'};
param(2).Type = 'dropdown';

tuningUI = HelperCreateParamTuningUI(param, ...
    'Panned Audio Source Separation Example');

if plotResults
    load daudiosourceseparation.mat
    screen = get(0,'ScreenSize');
    outerSize = min((screen(4)-40)/2, 512);
    scope.Position = [8,screen(4)-outerSize+8,outerSize-16,outerSize-92];
    scope.show
end

player = audioDeviceWriter;

% Execute algorithm
count = 1;
while count<numTSteps
    
    S = HelperUnpackUIData(tuningUI);
    
    if S.Stop     % If "Stop Simulation" button is pressed
        break;
    end
    if S.Pause
        continue;
    end
    
    if genCode
        [unmixedAudio,mixedAudioMono,audioIndexOut] = HelperAudioSourceSeparationSim_mex(S);
    else
        [unmixedAudio,mixedAudioMono,audioIndexOut] = HelperAudioSourceSeparationSim(S);
    end

   if plotResults
        % Visualize results
        scope(mixedAudioMono,unmixedAudio);
   end
   % Play selected audio
   if audioIndexOut == 2
       player(unmixedAudio);
   else
       player(mixedAudioMono);
   end
    count = count + 1;
end

% Clean up
if plotResults
    release(scope);
    scopeHandles.hplot = scope;
else
    scopeHandles.hplot = [];
end
clear HelperAudioSourceSeparationSim
clear HelperAudioSourceSeparationSim_mex
  
if ishghandle(tuningUI)  % If parameter tuning UI is open, then close it.
    delete(tuningUI);
    drawnow;
    clear tuningUI
end
clear HelperUnpackUIData

end