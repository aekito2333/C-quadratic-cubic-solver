#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdlib.h>
//<Surname: Yu> <First name: Xuesong> <M3SC>
int lin_root(double *a,double *r){
	double zero=0;
	if (fabs(a[1])<1e-14 && fabs(a[0])<1e-14) {return 0;}
	else if (fabs(a[1])<1e-14 && fabs(a[0])>1e-14){r[1]=zero; return -1;}
	else {r[0] = -(a[0]/a[1]); return 1;}
}