theta=linspace(-pi,pi,400);
r1=5;
r2=55;

x1=r1*cos(theta(1:100));
y1=r1*sin(theta(1:100));

x2=r2*cos(theta(101:200));
y2=r2*sin(theta(101:200));

x3=r1*cos(theta(201:300));
y3=r1*sin(theta(201:300));

x4=r2*cos(theta(301:400));
y4=r2*sin(theta(301:400));

plot(x1,y1,'r',x2,y2,'b',x3,y3,'g',x4,y4,'m');
hold on;

plot([x1(end) x2(1)],[y1(end) y2(1)]);
plot([x2(end) x3(1)],[y2(end) y3(1)]);
plot([x3(end) x4(1)],[y3(end) y4(1)]);
plot([x4(end) x1(1)],[y4(end) y1(1)]);

