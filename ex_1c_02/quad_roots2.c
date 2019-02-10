#include <float.h>
#include <stdio.h>
#include <math.h>
#include <complex.h>
//<Surname: Yu> <First name: Xuesong> <M3SC>

int lin_root(double *a,double *r);
int quad_roots(double *a,double *rr){
	double r[1],b[3];
	double two=2,four=4,zero=0,three=3,modd,r1,r2;
	int l;
    l=lin_root(a,r);
	if (fabs(a[2])<DBL_EPSILON) {lin_root(a,r); 
	         if (l==1){rr[1]=r[0]; rr[2]=zero; return -1;}//r= one real root and 0 fills the space, ordered
			 else if (l==0) {rr[1]=zero;rr[2]=zero; return -2;}//any number is a root
			 else if (l==-1) {rr[1]=zero; rr[2]=zero; return -3;}//inconsistent quadratic function
	         }
	else if (fabs(a[2])>DBL_EPSILON && fabs(a[0])<DBL_EPSILON) {lin_root(a,r); 
	                               if (r[0]>zero) {rr[1]=r[0]; rr[2]=zero;}
			                       else {rr[1]=zero; rr[2]=r[0];}
	                               return 2;}//r= real and 0, ordered
	else if (fabs(a[2])>DBL_EPSILON && fabs(a[0])>DBL_EPSILON) {
		   if (a[2]<1e+250&&a[1]<1e+250&&a[0]<1e+250){
		                            if (fabs(a[1])<DBL_EPSILON) {modd=-four*a[2]*a[0];
										                 if (modd<zero){rr[1]=zero;rr[2]=sqrt(-modd)/(two*a[2]);return 0;}
														 else if (a[2]>zero) {rr[1]=sqrt(fabs(modd))/(two*a[2]);rr[2]=-sqrt(fabs(modd))/(two*a[2]);return 2;}
														 else {rr[1]=-sqrt(fabs(modd))/(two*a[2]);rr[2]=sqrt(fabs(modd))/(two*a[2]);return 2;}
														 }
		
		                            else {modd =a[1]*a[1]-four*a[2]*a[0];//b*b-4ac
									//printf("modd=%g\n",modd);
	                                
		                            if (fabs(modd)<DBL_EPSILON) {rr[1] = (-a[1]+sqrt(fabs(a[2]))*sqrt(fabs(a[1]))*sqrt(fabs(modd)))/(two*a[2]);
	                                                       rr[2] = (-a[1]-sqrt(fabs(a[2]))*sqrt(fabs(a[1]))*sqrt(fabs(modd)))/(two*a[2]); 
				                                          return 1;}//repeated real roots
									else if (modd<zero) {rr[1] = -a[1]/(two*a[2]);
									                     rr[2] = fabs(sqrt(fabs(a[2]))*sqrt(fabs(a[1]))*sqrt(fabs(modd))/(two*a[2])); //+ve imaginary part
									                     return 0;}//imaginary roots 					  
														  
		                            else if (modd>zero) {if (a[1]<zero)
		                                                 {r1 = (-a[1]+sqrt(fabs(a[2]))*sqrt(fabs(a[1]))*sqrt(modd))/(two*a[2]);}
	                                                     else 
		                                                 {r1 = (-a[1]-sqrt(fabs(a[2]))*sqrt(fabs(a[1]))*sqrt(modd))/(two*a[2]);}
		                                                  r2 = (a[0]/a[2])/r1;//find two roots
														 
														 if (r1<r2) {rr[1]=r2; rr[2]=r1;}//ordering rr1>rr2
		                                                 else {rr[1]=r1; rr[2]=r2;}
														 return 2;}//two real roots, ordered
	                                    }}
			else{b[2]=a[2]/(1e+250);
			     b[1]=a[1]/(1e+250);
				 b[0]=a[0]/(1e+250);
				 if (fabs(b[1])<DBL_EPSILON) {modd=-four*b[2]*b[0];
										                 if (modd<zero){rr[1]=zero;rr[2]=sqrt(-modd)/(two*b[2]);return 0;}
														 else if (b[2]>zero) {rr[1]=sqrt(modd)/(two*b[2]);rr[2]=-sqrt(modd)/(two*b[2]);return 2;}
														 else {rr[1]=-sqrt(modd)/(two*b[2]);rr[2]=sqrt(modd)/(two*b[2]);return 2;}
														 }
		
		                            else {modd = ((b[1]/fabs(b[1]))*b[1]/fabs(b[2])-(b[2]/fabs(b[2]))*four*b[0]/fabs(b[1]));
	                                
		                            if (fabs(modd)<DBL_EPSILON) {rr[1] = (-b[1]+sqrt(fabs(b[2]))*sqrt(fabs(b[1]))*sqrt(fabs(modd)))/(two*b[2]);
	                                                       rr[2] = (-b[1]-sqrt(fabs(b[2]))*sqrt(fabs(b[1]))*sqrt(fabs(modd)))/(two*b[2]); 
				                                          return 1;}//repeated real roots
														  
									else if (modd<zero) {rr[1] = -b[1]/(two*b[2]);
									                     rr[2] = fabs(sqrt(fabs(b[2]))*sqrt(fabs(b[1]))*sqrt(fabs(modd))/(two*b[2])); //+ve imaginary part
									                     return 0;}//imaginary roots 					  
														  
		                            else if (modd>zero) {if (b[1]<zero)
		                                                 {r1 = (-b[1]+sqrt(fabs(b[2]))*sqrt(fabs(b[1]))*sqrt(modd))/(two*b[2]);}
	                                                     else 
		                                                 {r1 = (-b[1]-sqrt(fabs(b[2]))*sqrt(fabs(b[1]))*sqrt(modd))/(two*b[2]);}
		                                                  r2 = (b[0]/b[2])/r1;//find two roots
														 
														 if (r1<r2) {rr[1]=r2; rr[2]=r1;}//ordering rr1>rr2
		                                                 else {rr[1]=r1; rr[2]=r2;}
														 return 2;}//two real roots, ordered
									}
			}
}}