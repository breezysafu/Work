src=imread('Hydrangeas.jpg');
ref=imread('Koala.jpg');

imgr=src(:,:,1);
imgg=src(:,:,2);
imgb=src(:,:,3);

imgr2=ref(:,:,1);
imgg2=ref(:,:,2);
imgb2=ref(:,:,3);

hnimgr2=imhist(imgr2);
hnimgg2=imhist(imgg2);
hnimgb2=imhist(imgb2);

outr=histeq(imgr,hnimgr2);
outg=histeq(imgg,hnimgg2);
outb=histeq(imgb,hnimgb2);

histsp(:,:,1)=outr;
histsp(:,:,2)=outg;
histsp(:,:,3)=outb;

figure;
subplot(221);imshow(ref);title('refrence image');
subplot(222);imshow(src);title('input image');
subplot(224);imshow(histsp);title('result image');

figure;
subplot(331);plot(hnimgr);title('red input');
subplot(334);plot(hnimgg);title('green input');
subplot(337);plot(hnimgb);title('blue input');
subplot(332);plot(hnimgr2);title('red ref');
subplot(335);plot(hnimgg2);title('green ref');
subplot(338);plot(hnimgb2);title('blue ref');
subplot(333);plot(outr);title('red result');
subplot(336);plot(outg);title('green result');
subplot(339);plot(outb);title('blue result');







