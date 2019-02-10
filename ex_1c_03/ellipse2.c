#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdlib.h>
#define PI  3.141592654
//<Surname: Yu> <First name: Xuesong> <M3SC>
// gcc lin_root2.c quad_roots2.c rcubic_roots2.c ellipse2.c rquartic_roots.c

int lin_root(double *a,double *r);
int quad_roots(double *a,double *rr);
int rcubic_roots(double *a,double *r);
int rquartic_roots(double *a, double *root);

int main(void){
	double b,d,d1,d2,s,xe,ye,two=2,t,zero=0,one=1,mx=6378137,my=6356752;
	double a[4],r[5],phi[5];
	int q;
	printf("Xuesong Yu 00821031 M3SC \n \n ");
	printf("\n TIME : %s",__TIME__);
	printf("\n DATE : %s",__DATE__);
	
	double xp=4108231,yp=5130128;
	b=my/mx;
	a[3]=(two*xp+two-two*b*b)/(b*yp);
	a[2]=zero;
	a[1]=(two*xp-two+two*b*b)/(b*yp);
	a[0]=-one;
	q=rquartic_roots(a,r);
	/*if (q==4||q==3||q==1){
	 phi[1]=two*atan(r[1])/PI*180;
	 phi[2]=two*atan(r[2])/PI*180;
	 phi[3]=two*atan(r[3])/PI*180;
	 phi[4]=two*atan(r[4])/PI*180;}	                 				   
	else if (q==2){
	 phi[1]=two*atan(r[1])/PI*180;
	 phi[2]=two*atan(r[2])/PI*180;
	 phi[3]=0;
	 phi[4]=0;}
	else if (q==0){
	 phi[1]=0;
	 phi[2]=0;
	 phi[3]=0;
	 phi[4]=0;}*/
	 xe=cos(two*atan(r[1]))*mx;
	 ye=b*sin(two*atan(r[1]))*mx;
	 d=sqrt((xe-xp)*(xe-xp)+(ye-yp)*(ye-yp));
	 s=(ye*xp-yp*xe)/(ye-yp);
	 t=asin((yp-ye)/s)/PI*180;
	 //t=atan(ye/(xe-s))/PI*180;
	 printf("\n distance=%lf latitude=%lf",d,two*atan(r[1])/PI*180);
	 	 
return 0;}