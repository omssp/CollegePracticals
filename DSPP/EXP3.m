clc
clear all
close all

na = input('Enter the  amount to be delayed : ')
nd = input('Enter the amount to be advanced : ')

xl = input('Enter the  left limit : ')
xr = input('Enter the right limit : ')

x = xl : 1 : xr

y = input('Enter the Sequence : ')

subplot( 3, 1, 1 )
stem( x, y )
title('Signal x(n)')

xa = x + na

subplot( 3, 1, 2 )
stem( xa, y )
title(['Advanced Signal x(n + ' int2str(na) ')'])

xd = x - nd

subplot( 3, 1, 3 )
stem( xd, y )
title(['Delayed Signal x(n - ' int2str(nd) ')'])
