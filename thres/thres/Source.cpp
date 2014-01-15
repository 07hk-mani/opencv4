#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include<iostream>

using namespace cv;
using namespace std;

#define h 280
#define w 320

int main()
{
Mat img=imread("baboon.jpg");
Mat rimg(h,w,CV_8SC3),pro;


//Windows

namedWindow("thres",CV_WINDOW_AUTOSIZE);
namedWindow("input",CV_WINDOW_AUTOSIZE);

//Variables for trackbar
int rv=0;
int gv=0;
int bv=0;

while(1)
{

//Creating the trackbars
createTrackbar("R","thres",&rv,255,0);
createTrackbar("G","thres",&gv,255,0);
createTrackbar("B","thres",&bv,255,0);

resize(img, rimg, rimg.size(), 0,0,INTER_LINEAR );
rimg.copyTo(pro);
int b,r,g;
Mat_<Vec3b>::iterator it = pro.begin<Vec3b>();
// obtain end position
Mat_<Vec3b>::iterator itend = pro.end<Vec3b>();
	// loop over all pixels
	for ( ; it!= itend; ++it) {
		
		b=(*it)[0];
		g=(*it)[1];
		r=(*it)[2];
		
	if((b>bv)&&(g>gv)&&(r>rv))
	{(*it)[0]=255;
		(*it)[1]=255;
         (*it)[2]=255;


	}
	else
		{(*it)[0]=0;
	(*it)[1]=0;
         (*it)[2]=0;
	}
	}
		
	imshow("input",rimg);
		imshow("thres",pro);
int c = cvWaitKey(5);
if( (char)c == 27 )
{
exit(0);
}
}
}