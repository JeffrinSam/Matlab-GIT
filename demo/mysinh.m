function y = mysinh(x)
m=sin(2*pi*x);
y=(exp(x)-exp(-x))/2;
subplot(2,1,1);title('expo ofsine');
plot(y);
subplot(2,1,2);
plot(m);

end

