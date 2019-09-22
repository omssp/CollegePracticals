clear all

num = [1 2 1]
den = [1 -1 0.356]
[r, p, k] = residuez(num, den)
disp('Residues')
disp(r)
disp('Poles')
disp(p)
disp('Constants')
disp(k)

zplane(num, den)
xlabel('real')
ylabel('imaginary')
title('Pole zero plot of H(z)= (1+2*z^-1 + z^-2) / (1 - z^-1 + 0.356*z^-2)')
figure
num = [18  0   0   0]
den = [18   3   -4   -1]
[r, p, k] = residuez(num, den)
disp('Residues')
disp(r)
disp('Poles')
disp(p)
disp('Constants')
disp(k)
zplane(num, den)
xlabel('real')
ylabel('imaginary')
title('Pole zero plot of H(z)= 18z^3/ (18z^3 + 3z^2 - 4z - 1)')
figure(2)