clc
clear all
close all

b = input('Enter the coefficients of x(n),x(n-1)---- : ')
a = input('Enter the coefficients of y(n),y(n-1)---- : ')
N = input('Enter the number of samples of imp response : ')

[h, t] = impz(b, a, N)

 subplot(2, 1, 1)
plot(t, h)
title('Plot of impulse response')
ylabel('amplitude')
xlabel('time index----->N')

subplot(2, 1, 2)
stem(t, h)
title('Plot of impulse response')
ylabel('amplitude')
xlabel('time index----->N')
disp(h)
grid on