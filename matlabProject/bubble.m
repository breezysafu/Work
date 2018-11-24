theta=linspace(-pi,pi,400);
r1=5;
for k=1:1:40;
x1=r1*k*cos(theta);
y1=r1*k*sin(theta);

plot(x1,y1,'b');
axis([-400 400 -400 400]);
pause(0.2);
%hold on
end
