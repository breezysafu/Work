a=imread('Desert.jpg');
ad=im2double(a);
x=ad;y=ad;
[r,c]=size(ad);
factor=2;
for i=1:r
    for j=1:c
        x(i,j)=factor*log(1+ad(i,j));
        y(i,j)=factor*ad(i,j)^9;
    end
end
subplot(1,2,1);imshow(ad);title('before');
subplot(1,2,2);imshow(x);title('after');
figure,imshow(y);
