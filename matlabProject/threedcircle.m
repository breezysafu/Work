theta=linspace(-pi,3*pi,400);
r1=5;
x1=r1*cos(theta);
y1=r1*sin(theta);
z1=linspace(1,10,400);
plot3(x1,y1,z1);
hold on
plot3([0 0],[0 0],[1 10]);
z2=linspace(2,11,400);
plot3(x1,y1,z2);
for k=1:1:400
    plot3([x1(k) x1(k)],[y1(k) y1(k)],[z1(k) z2(k)]);
end
for m=1:10:400
    plot3([0 x1(m)],[0 y1(m)],[z1(m) z1(m)]);
end

