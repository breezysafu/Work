theta=linspace(-pi,pi,400);
r1=5;
x1=r1*cos(theta);
y1=r1*sin(theta);
r2=55;
x2=r2*cos(theta);
y2=r2*sin(theta);
plot(x1,y1,'r',x2,y2,'b');
axis([-100,100,-100,100]);