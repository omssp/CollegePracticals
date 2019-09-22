clc
clear all
close all

xl = input("Enter the  left limit : ")
xr = input("Enter the right limit : ")

x = xl : 1 : xr

y = input("Enter the sequence : ")

subplot(2, 1, 1)
stem(x, y)
title("Original Signal")
xlabel("x(n)")
ylabel("n")

fx = (xr*-1) : 1 : (xl*-1) 
fy = fliplr(y)

subplot(2, 1, 2)
stem(fx, fy)
title("Folded Signal")
xlabel("x(-n)")
ylabel("-n")