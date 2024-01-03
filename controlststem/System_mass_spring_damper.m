%==========================================================================
% eDrives Embed
% Oscillating mechan. System with mass, spring and damper
% The differential equation is:  
%       m/d*d^2/dt^2(y) + d/c*dy/dt + y = -m*g/c
%
% This results in the transfer function:  
%               y(s)         -m*g/c
%       G(s) =  ----  =  -------------------    with: H(s) = Step function
%               H(s)     m/c*s^2 + d/c*s + 1
%==========================================================================
clear;              % Clean up workspace
clc;                % Clear Command Window
 
m = 0.2; % Mass [kg]
c = 10;  % Spring stiffness [N/m]
d = 0.5; % Damping constant [Ns/m]
g = 9.81; % acceleration due to gravity [m/s/s]

 
% Coefficients of the Numerator
num = [-m*g/c];     
% Coefficients of the denominator
den = [m/c,d/c,1]; 
 
% Form the transfer function from the coefficients of the numerator and denominator
sys = tf(num,den);
 
% Simulation of the step response (unit step)
[Y,T,X] = step(sys);
 
% Plot the result of the simulation
plot(T,Y);          % Plot result Ua(t) = Y(T) 
grid on;                    % Switch on grid
xlabel('time t [ms]');      % Labelling the X-axis
ylabel('position y [m]');   % Labelling the Y-axis
title('Spring pendulum');       % Title
axis([0 4.5 -0.35 0])       % Axis scaling 0<=x<=4.5, -0.35<=y<=0
