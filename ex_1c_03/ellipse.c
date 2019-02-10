#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdlib.h>
#define PI  3.141592654
//<Surname: Yu> <First name: Xuesong> <M3SC>
// gcc lin_root2.c quad_roots2.c rcubic_roots2.c ellipse.c rquartic_roots.c

int lin_root(double *a,double *r);
int quad_roots(double *a,double *rr);
int rcubic_roots(double *a,double *r);
int rquartic_roots(double *a, double *root);

int main(void){
	double b,d,d1,d2,two=2,t,zero=0,one=1;
	double a[4],r[5],phi[5];
	int q;
	printf("Xuesong Yu 00821031 M3SC \n \n ");
	printf("\n TIME : %s",__TIME__);
	printf("\n DATE : %s",__DATE__);
	
	double X=0.375,Y=0.5,step=0.05;
	for (b=0.05;b<1.0;b=b+step) {
	b=0.4245797599366;
	a[3]=(two*X+two-two*b*b)/(b*Y);
	a[2]=zero;
	a[1]=(two*X-two+two*b*b)/(b*Y);
	a[0]=-one; 
	q=rquartic_roots(a,r);
	if (q==4||q==3||q==1){printf("%.2lf %lf %lf %lf %lf %d \n",b,r[1],r[2],r[3],r[4],q);
	 phi[1]=two*atan(r[1])/PI*180;
	 phi[2]=two*atan(r[2])/PI*180;
	 phi[3]=two*atan(r[3])/PI*180;
	 phi[4]=two*atan(r[4])/PI*180;}	                 				   
	else if (q==2){printf("%.2lf %lf %lf %lf %lf %d \n",b,r[1],r[2],zero,zero,q);
	 phi[1]=two*atan(r[1])/PI*180;
	 phi[2]=two*atan(r[2])/PI*180;
	 phi[3]=0;
	 phi[4]=0;}
	else if (q==0){printf("%.2lf %lf %lf %lf %lf %d \n",b,zero,zero,zero,zero,q);
	 phi[1]=0;
	 phi[2]=0;
	 phi[3]=0;
	 phi[4]=0;}
	 //printf("%.2lf %lf %lf %lf %lf \n \n \n",zero,phi[1],phi[2],phi[3],phi[4]); 
	 /*
	 printf("x=%lf y=%lf \n",cos(two*atan(r[1])),b*sin(two*atan(r[1])));
	 printf("x=%lf y=%lf \n",cos(two*atan(r[2])),b*sin(two*atan(r[2])));
	 printf("x=%lf y=%lf \n",cos(two*atan(r[3])),b*sin(two*atan(r[3])));
	 printf("x=%lf y=%lf \n",cos(two*atan(r[4])),b*sin(two*atan(r[4])));*/
	 return 0;}