#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>
#include <complex.h>
//<Surname: Yu> <First name: Xuesong> <M3SC>

int main (void){
    double a2,a1,a0;
	double alpha, beta, p,pr, rr1, rr2;
	double three,two,twoseven,zero,one,nine,eleven;
	double *y;
	int q,n;
	zero=0;
	two=2;
	three=3;
	twoseven=27;
	one=1;
	nine=9;
	eleven=11;
	a2=2;
	a1=5;
	a0=8;
    alpha=cbrt(a1*a2/three-two*a2*a2*a2/twoseven-a0);
	p=-one/(alpha*alpha)*(a1-(a2*a2)/three);
    printf("%e\n",alpha);
	printf("%e\n",p);
}