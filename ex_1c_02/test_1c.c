#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdlib.h>
#define PI 3.141592654
//<Surname: Yu> <First name: Xuesong> <M3SC>
// gcc lin_root2.c quad_roots2.c rcubic_roots3.c test_1c.c rquartic_roots.c

int lin_root(double *a,double *r);
int quad_roots(double *a,double *rr);
int rcubic_roots(double *a,double *r);
int rquartic_roots(double *a, double *root);

//test for quad.
/*int main(void){
	double a[3],r[3],a2[3],one=1,py=-0.29999999999999716;
	int q;
	//printf("a2 a1 a0");
	a[0]=750;
	a[1]=2530;
	a[2]=100.3;
	a2[0]=-a[0]/py;
	a2[1]=a[2]+py;
	a2[2]=one;
	printf("a= %g %g %g\n",a2[0],a2[1],a2[0]);
	q=quad_roots(a2,r);
	printf("%e %e %d",r[1],r[2],q);
	return(0);
	}*/
	


//test for rcub.
/*int main(void){
	double a[3],r[4];
	int c;
	printf("a2 a1 a0");
	scanf("%lf %lf %lf", &a[2],&a[1],&a[0]);
	c=rcubic_roots(a,r);
	printf("%.16e %.16e %.16e %d",r[1],r[2],r[3],c);
}
*/

//test for rquartic
int main(void){
	double a[4],r[5];
	int f;
	printf("a3 a2 a1 a0");
	scanf("%lf %lf %lf %lf",&a[3],&a[2],&a[1],&a[0]);
	f=rquartic_roots(a,r);
	printf("%.16e %.16e %.16e %.16e %d",r[1],r[2],r[3],r[4],f);
	return 0;
}
/*
int main(void){
double x=15*PI/8,y;
y=cos(x);
printf("%e\n %e",y,sin(x));

return 0;
}*/