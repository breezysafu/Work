xa=1:1:6;
ya=1:1:6;
[mx,my]=meshgrid(xa,ya);
disp([mx,my]);
mz=zeros(6,6);
mz([1 1 2 1 1 1 2 2 5 5 6 6 5 5 6 6],[1 2 1 2 6 5 5 6 6 5 6 5 2 1 1 2])=10;
disp(mz);
stem3(mx,my,mz);
mesh(mx,my,mz);