function growth(yr,x)
old=x(1);
new=x(2);
g=ones(1,length(x)-1);
g(1)=(new-old)/new;
old=new;
for k=3:1:length(x)
    new=x(k);
    g(k-1)=(new-old)/new;
    old=new;
end
plot(yr(2:end),g);
disp(g);
end