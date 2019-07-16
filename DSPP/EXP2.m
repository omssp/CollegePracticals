clc
clear all
close all

y = [ 0 0 0 0 1 0 0 0 0 ]
x = -4 : 1 : 4
subplot( 3, 2, 1 )
stem( x, y )
xlabel('time')
ylabel('amplitude')
title('Unit Impulse Sequence')

y = [ 0 0 0 0 1 1 1 1 1 ]
x = -4 : 1 : 4
subplot( 3, 2, 2 )
stem( x, y )
xlabel('time')
ylabel('amplitude')
title('Unit Step Sequence')

y = [ 0 0 0 0 0 1 2 3 4 ]
x = -4 : 1 : 4
subplot( 3, 2, 3 )
stem( x, y )
xlabel('time')
ylabel('amplitude')
title('Unit Ramp Squence')

x = -4 : 1 : 4
y = exp( x )
subplot( 3, 2, 4 )
stem( x, y )
xlabel('time')
ylabel('amplitude')
title('Exponential Signal')

x = -4 : 0.2 : 5
y = sin( x )
subplot( 3, 2, 5 )
stem( x, y )
xlabel('time')
ylabel('amplitude')
title('Sine Signal')

x = -4 : 0.2 : 5
y = cos( x )
subplot( 3, 2, 6 )
stem( x, y )
xlabel('time')
ylabel('amplitude')
title('Cosine Signal')