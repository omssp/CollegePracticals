clc
clear all
close all

x = input('Enter the sequence of x(n) : ')
y = xcorr(x)

subplot(2, 1, 1)
stem(x)
ylabel('Amplitude --.')
xlabel('(a) n --.')
title('Original signal')

subplot(2, 1, 2)
stem(fliplr(y))
ylabel('Amplitude --.')
xlabel('(a) n --.')
title ('Auto correlated sequence')
disp('The resultant signal is')
fliplr(y)