i=imread('gray-ombre-hair.jpg');
figure;
subplot(1,2,1);imshow(i);
subplot(1,2,2);imhist(i);
imh=imadjust(i,[0.3,0.6],[0.0,1.0]);
imh1=histeq(i);
figure;
subplot(2,2,1);imshow(imh);title('stretched');
subplot(2,2,2);imhist(imh);
subplot(2,2,3);imshow(imh1);title('hist eq');
subplot(2,2,4);imhist(imh1);



