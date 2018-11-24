i=imread('rice.tif');
figure,imshow(i);
figure,imhist(i);
t=110;
it=im2bw(i,t/255);
figure,imshow('it');
