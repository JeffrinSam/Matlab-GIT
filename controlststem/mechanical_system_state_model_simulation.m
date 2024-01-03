% eDrives Embed 
% Simulation program for state space model (mechanical system)
clear all
t=0; % Initial time
dt=0.01; % step size
ts=10.0; % Simulation time
n=round( (ts-t)/dt); % number of iterations
%system parameters
k1=6;
k2=8;
m1=3;
m2=4;

d1=50;
d2=40;
A=[0 1 0 0; -k1/m1 -d1/m1 k1/m1 d1/m1; 0 0 0 1; k1/m2 d1/m2 -(k1+k2)/m2 -(d1+d2)/m2];

B=[0; 1/m1; 0; 0];
C=[0 1];
D=[0 0];
X=[0 0 0 0]';
u=5;
for i=1:n;
dx=A*X+B*u;
X=X+dx*dt;
X1(i,:)=[t,X'];
t=t+dt;
end
subplot(2,2,1)
plot(X1(:,1),X1(:,2),'b.')
axis([0 10 0 2])
xlabel('time')
ylabel('X1')
title('Response of state variable X1')
subplot(2,2,2)
plot(X1(:,1),X1(:,3),'r.')
axis([0 10 0 1])
xlabel('time')
ylabel('X2')
title('Response of state variable X2')

subplot(2,2,3)
plot(X1(:,1),X1(:,4),'c.')
axis([0 10 0 2])
xlabel('time')
ylabel('X3')
title('Response of state variable X3')
subplot(2,2,4)
plot(X1(:,1),X1(:,5),'g.')
axis([0 10 0 1])
xlabel('time')
ylabel('X4')
title('Response of state variable X4')