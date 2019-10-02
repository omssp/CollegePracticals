clc;
clear all;
close all;
fs=8000;
n=40;
b=fir1(n,[1200/4000 1800/4000],'bandpass');
freqz(b,1,128,8000);
figure(2)
[h,w]=freqz(b,1,128,8000);
plot(w,abs(h));  % Normalized Magnitude Plot
title('Normalized Magnitude Plot');
grid
figure(3)
zplane(b,1);
title('zplane');