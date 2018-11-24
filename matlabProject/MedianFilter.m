i=imread('Desert.jpg');
isp=imnoise(i,'salt & pepper',0.1);
figure,imshow(i);
figure,imshow(isp);

a=fspecial('average');
a1=filter2(a,isp);
figure,imshow(uint8(a1));
med=medfilt2(isp);
i2=ordfilt2(isp,25,ones(5,5));
figure,imshow(i2);
