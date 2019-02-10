#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <complex.h>
#include <float.h>
int main(void){
	double *y;
    double alpha, beta, p, pr, rr1, rr2;
	double three,two,twoseven,zero,one,nine,eleven;
	int n;
	zero=0;
	two=2;
	three=3;
	twoseven=27;
	one=1;
	nine=9;
	eleven=11;
y=(double *)malloc(one*90);
p=-0.5424850;
              if(p>eleven/three) {y[0]=sqrt(p);}
		      else if (p<-1.92) {y[0]=-one/p;}
			  else {y[0]=one+p/three-p*p*p/(nine*nine);} //decide y0 base on p
			 
			  for (n=0;n<4;n=n+1){
				  y[n+1]=y[n]-(y[n]*y[n]*y[n]-p*y[n]-one)/(three*y[n]*y[n]-p);}//iterate three times
		      
			  n=3;
			  while ((y[n+1]!=y[n])||(fabs(y[n+1]-y[n])<fabs(y[n]-y[n-1]))){
				  n=n+1;
				  y[n+1]=y[n]-(y[n]*y[n]*y[n]-p*y[n]-1)/(three*y[n]*y[n]-p);}
				  pr=y[n+1];
				  
printf("y[%d]=%e \n",0, y[0]);
printf("y[%d]=%e \n",1, y[1]);
printf("y[%d]=%e \n",2, y[2]);	
printf("y[%d]=%e \n",3, y[3]);	
printf("y[%d]=%e \n",4, y[4]);	
printf("y[%d]=%e \n",5, y[5]);
printf("y[%d]=%e \n",6, y[6]);
printf("y[%d]=%e \n",7, y[7]);
printf("y[%d]=%e \n",8, y[8]);
printf("pr=%e \n",pr);

free(y);	
return 0;}