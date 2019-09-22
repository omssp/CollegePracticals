clc
clear all
close all

x = input('Enter the sequence of x(n) : ')
x1 = fft(x)
subplot(2, 2, 1)
stem(imag(x1))
title('Imaginary DFT')
disp('DFT')
disp(x1)
subplot(2, 2, 2)
stem(real(x1))
title('Real DFT')

y = ifft(x1)
subplot(2, 2, 3)
stem(imag(y))
title('Rmaginary IDFT')
disp('IDFT')
disp(y)
subplot(2, 2, 4)
stem(real(y))
title('Real IDFT')