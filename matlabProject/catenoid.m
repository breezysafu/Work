u=linspace(-pi,pi,100);
v=linspace(-pi/2,pi/2,100);
[mu,mv]=meshgrid(u,v);
alpha=pi/3;
mx=cos(alpha)*sinh(mv).*sin(mu)+sin(alpha)*cosh(mv).*cos(mu);
my=-cos(alpha)*sinh(mv).*cos(mu)+sin(alpha)*cosh(mv).*sin(mu);
mz=mu*cos(alpha)+mv*sin(alpha);
mesh(mx,my,mz);