clc;
clear all;
close all;
fs=8000; % sampling frequency
n=50; % order of the filter
w=1200/ (fs/2);
b=fir1(n,w,'low'); % Zeros of the filter
freqz(b,1,128,8000); % Magnitude and Phase Plot of the filter figure(2)
[h,w]=freqz(b,1,128,8000);
subplot(2,1,1);
plot(w,abs(h));% Normalized Magnitude Plot
title('Normalized Magnitude Plot');
grid
subplot(2,1,2);
figure(2)
zplane(b,1); % the plot in lab
title('zplane');
