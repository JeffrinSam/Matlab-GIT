%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% eDrives Embed
% file exercise_control1_e.m
%
% Exercise to lecture MATLAB Simulink - Control System Toolbox LTI Systems
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

echo on;
format compact;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Creation of LTI-models
V   = 1 ;                                   % 3a) TF-model
T1  = 0.01 ; 
pt1 =  tf(V,[T1 1])

Ti  = 0.1 ;                                 % 3b) ZPK-model
int = zpk([],0,1/Ti)

Vr  = 2 ;                                   % 3c) SS-model
Tr  = 0.005 ;
reg = ss([-1/Tr],[Vr/Tr],[1],0)
% reg = tf([Vr/Tr],[1 1/Tr])                % TF-model alternatively 
                                          

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Discrete-time LTI-models
Ts   = 0.1 ;                                % 4a) TF-model
dpt1 = c2d(pt1,Ts)
dint = c2d(int,Ts)
dreg = c2d(reg,Ts)

dsystf   = tf([2 1 0],[1 1 2],-1)           % 4b) DSP-Format
dsysfilt = filt([2 1],[1 1 2],-1)

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Working with LTI-model
plant   = pt1 * int                         % 5a) old: plant = series(int,pt1,1,1) 
forward = plant * reg                       % 5b) 
pre     = tf(1)                             % 5c) 
sensor    = tf(1)
sys     = feedback(forward,sensor,-1)*pre     % 5d)

step(plant,forward,sys,0:0.0005:0.3);       % 5e) display
legend('plant','forward','sys','Location','NorthWest')

Tm      = 0.05                              % 5f)
V       = 1
sensor    = tf(1,[Tm 1])
sys2    = feedback(forward,sensor,-1)*pre     % 5g)

step(sys,sys2,0:0.0005:0.3);                % 5h) step response
legend('sys','sys2','Location','NorthWest')

Tm      = 0.008                             % 5i)
sensor3   = tf(1,[Tm 1])
sys3    = feedback(forward,sensor3,-1)*pre     
step(sys,sys2,sys3,0:0.0005:0.3);           
legend('sys','sys2','sys3','Location','NorthWest')
