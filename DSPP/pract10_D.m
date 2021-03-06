﻿clc;
clear all;
close all;
fs=8000;
n=40;
b=fir1(n,[1500/4000 1550/4000],'stop'); 
freqz(b,1,128,8000)
figure(2)
[h,w]=freqz(b,1,128,8000);
plot(w,abs(h)); % Normalized Magnitude Plot
title('Normalized Magnitude Plot');
grid
figure(3)
zplane(b,1);
title('zplane');