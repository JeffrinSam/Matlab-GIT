function HelperSourceSeparationCodeGeneration
%HELPERSOURCESEPARATIONCODEGENERATION Code generation for source separation
%featured example
%
% Run this function to generate a MEX file for the
% HelperAudioSourceSeparationSim function. This function
% HelperAudioSourceSeparationSim is only in support of
% audioSourceSeparationApp. It may change in a future release.

% Copyright 2016 The MathWorks, Inc.

% Parameters to be tuned
% Pan value
% Audio source index
ParamStruct.TuningValues = [0.3 0];
ParamStruct.ValuesChanged = false;
ParamStruct.Reset = false;
ParamStruct.Pause = false;
ParamStruct.Stop  = false;

codegen -report HelperAudioSourceSeparationSim -args {ParamStruct} -o HelperAudioSourceSeparationSim_mex

