#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>
#include <complex.h>
int quad_roots(double *a,double *rr);
int rcubic_roots(double *a,double *r);
int rquartic_roots(double *a, double *root){

	double b[3],r[4],a1[3],a2[3],rr1[3],rr2[3],a3[3],a4[3],a5[3],rr3[3],rr4[3],rr5[3];
	double four=4,two=2,one=1,zero=0,e=DBL_EPSILON;
	int q1,q2,q3,q4,q5,c;
	///
	b[0]=four*a[0]*a[2]-a[1]*a[1]-a[0]*a[3]*a[3];
	b[1]=a[1]*a[3]-four*a[0];
	b[2]=-a[2];
	rcubic_roots(b,r);//real root r[1]
	//if (fabs(a[1]-a[3]*r[1]/two+one/two*sqrt(r[1]*r[1]-four*a[0])*sqrt(a[3]*a[3]-four*a[2]+four*r[1]))<e) {
	a1[0]=r[1]/two+sqrt((r[1]/two)*(r[1]/two)-a[0]);
	a1[1]=a[3]/two+sqrt(a[3]*a[3]/four+r[1]-a[2]);
	a1[2]=one;
	a2[0]=r[1]/two-sqrt((r[1]/two)*(r[1]/two)-a[0]);
	a2[1]=a[3]/two-sqrt(a[3]*a[3]/four+r[1]-a[2]);
	a2[2]=one;
	//}
	/*else {
	a1[0]=r[1]/two-sqrt((r[1]/two)*(r[1]/two)-a[0]);
	a1[1]=a[3]/two+sqrt(a[3]*a[3]/four+r[1]-a[2]);
	a1[2]=one;
	a2[0]=r[1]/two+sqrt((r[1]/two)*(r[1]/two)-a[0]);
	a2[1]=a[3]/two-sqrt(a[3]*a[3]/four+r[1]-a[2]);
	a2[2]=one;	
	//}*/
	q1=quad_roots(a1,rr1);
	q2=quad_roots(a2,rr2);
	///move above to different location 
	if (fabs(a[3])<e&&fabs(a[2])<e&&fabs(a[1])<e) {
		                                     if (fabs(a[0])<e){root[1]=zero;root[2]=zero;root[3]=zero;root[4]=zero; return 1;}//x=0 4 times
											 else if (a[0]>zero){root[1]=sqrt(sqrt(a[0]));root[2]=-sqrt(sqrt(a[0]));root[3]=zero;root[4]=sqrt(sqrt(a[0]));return 2;}//unity
											 else if (a[0]<zero){root[1]=sqrt(sqrt(fabs(a[0])));root[2]=-sqrt(sqrt(fabs(a[0])));root[3]=zero;root[4]=sqrt(sqrt(fabs(a[0])));
											                     return 2;}//two real + complex
											 }
											 
	else if (fabs(a[3])<e&&fabs(a[1])<e){
		                             a1[2]=one;
									 a1[1]=a[2];
									 a1[0]=a[0];
									 q1=quad_roots(a1,rr1);
									 if (q1==2){
										        if (rr1[1]>=zero&&rr1[2]>=zero) {root[1]=sqrt(rr1[1]);root[2]=sqrt(rr1[2]);root[3]=-sqrt(rr1[2]);root[4]=-sqrt(rr1[2]); return 4;}//4 distinct real roots
									            else if (rr1[1]>=zero&&rr1[2]<zero) {root[1]=sqrt(rr1[1]);root[2]=-sqrt(rr1[1]);root[3]=zero;root[4]=sqrt(fabs(rr1[2])); return 2;}// 2 real + complex
												else if (rr1[1]<zero&&rr1[2]<zero) {root[1]=zero;root[2]=sqrt(fabs(rr1[2]));root[3]=zero;root[4]=sqrt(fabs(rr1[1]));return 0;}//2 pairs of complex
									           }
									 else if (q1==1) {
										              if (fabs(rr1[1])<e) {root[1]=zero;root[2]=zero;root[3]=zero;root[4]=zero;return 1;}// 0 repeated 4 times
  													  else if (rr1[1]>zero) {root[1]=sqrt(rr1[1]);root[2]=sqrt(rr1[2]);root[3]=-sqrt(rr1[2]);root[4]=-sqrt(rr1[2]); return 3;}//2 pairs on distinct real roots;
													  
													  else if (rr1[1]<zero) {root[1]=zero; root[2]=sqrt(fabs(rr1[1]));root[3]=zero;root[4]=sqrt(fabs(rr1[2]));return 0;}//2 pairs of complex
									                 }
									 else if (q1==0) {
										             rr2[1]=sqrt((rr1[1]+sqrt(rr1[1]*rr1[1]+rr1[2]*rr1[2]))/two);//real
													 rr2[2]=rr1[2]/(two*rr2[1]);//im
													 rr2[3]=sqrt((-rr1[1]+sqrt(rr1[1]*rr1[1]+rr1[2]*rr1[2]))/two);//im 2
													 rr2[4]=rr1[2]/(two*rr2[3]);//real 2
										             if (rr2[1]>rr2[4]){root[1]=rr2[1];root[2]=rr2[2];root[3]=rr2[4];root[4]=rr2[3];return 0;}
													 else {root[1]=rr2[4];root[2]=rr2[3];root[3]=rr2[1];root[4]=rr2[2];return 0;}
										             
									                 }
													 
	                                 }
	else if (fabs(a[0])<e) {
		                  b[0]=a[1];
	                      b[1]=a[2];
	                      b[2]=a[3];
						  c=rcubic_roots(b,r);//zero is a real root
						  if (c==0) {if (r[1]>zero) {root[1]=r[1];root[2]=zero;root[3]=r[2];root[4]=r[3]; return 2;}//two distince real and complex pair
						                else {root[1]=zero;root[2]=r[1];root[3]=r[2];root[4]=r[3]; return 2;}
						               }
                          else if (c==2) {if (r[3]>zero) {root[1]=r[1];root[2]=r[2];root[3]=r[3];root[4]=zero;}//3 distinct real roots
                                          else if (r[1]<zero) {root[1]=zero;root[2]=r[1];root[3]=r[2];root[4]=r[3];}
                                          else if (r[2]>zero) {root[1]=r[1];root[2]=r[2];root[3]=zero;root[4]=r[3];}
                                          else if (r[2]<zero) {root[1]=r[1];root[2]=zero;root[3]=r[2];root[4]=r[3];}										  
						                  return 3;}
						  else if (c==3) {if (fabs(r[1])<e) {root[1]=zero;root[2]=r[1];root[3]=r[2];root[4]=r[3];return 3;}
						                  else if(r[3]>zero) {root[1]=r[1];root[2]=r[2];root[3]=r[3];root[4]=zero;return 4;}
						                  else if (r[1]<zero) {root[1]=zero;root[2]=r[1];root[3]=r[2];root[4]=r[3];return 4;}
										 
										  else if (fabs(r[2])<e) {root[1]=r[1];root[2]=zero;root[3]=r[2];root[4]=r[3];return 3;}
										  else if (fabs(r[3])<e) {root[1]=r[1];root[2]=r[2];root[3]=r[3];root[4]=zero;return 3;}
										  else if (r[2]<zero) {root[1]=r[1];root[2]=zero;root[3]=r[2];root[4]=r[3];return 4;}
										  else if (r[3]<zero) {root[1]=r[1];root[2]=r[2];root[3]=zero;root[4]=r[3];return 4;}
										  }
	                      }
	else if (fabs(a[3])<e&&fabs(a[1])<e){a3[0]=a[0];a3[1]=a[2];a3[2]=one;		                             
									 q3=quad_roots(a,rr3);
									 if (fabs(a[0])<e){//r1=r2=0
										             a4[0]=a[2];a4[1]=zero;a4[2]=one;
													 q4=quad_roots(a4,rr4);
													 if (q4==0) {root[1]=zero;root[2]=zero;root[3]=rr4[1];root[4]=rr4[2];return 2;}
													 else if (q4==1){if(rr4[1]>zero) {root[1]=rr4[1];root[2]=rr4[2];root[3]=zero;root[4]=zero;}
													                 else if (rr4[1]<zero) {root[1]=zero;root[2]=zero;root[3]=rr4[1];root[4]=rr4[2];}
													                 return 3;}
													 else if (q4==2){if(rr4[1]<zero){root[1]=zero;root[2]=zero;root[3]=rr4[1];root[4]=rr4[2];}
													                 else if (rr4[2]>zero) {root[1]=rr4[1];root[2]=rr4[2];root[3]=zero;root[4]=zero;}
																	 else {root[1]=rr4[1];root[2]=zero;root[3]=zero;root[4]=rr4[2];}
													                 return 3;}
									                }
									 else if(q3==2){a4[0]=rr3[1];a4[1]=zero;a4[2]=one; //r1 of the two distinct roots
									               q4=quad_roots(a4,rr4);
											       a5[0]=rr3[2];a5[1]=zero;a5[2]=one; //r2
												   q5=quad_roots(a5,rr5);
											       if (q4==2&&q5==2){
												                 if(rr4[2]>rr5[1]){root[1]=rr4[1];root[2]=rr4[2];root[3]=rr5[1];root[4]=rr5[2];}
			                                                     else if (rr4[1]<rr5[2]){root[1]=rr5[1];root[2]=rr5[2];root[3]=rr4[1];root[4]=rr4[2];}
			                                                     else if (rr4[1]>rr5[1]&&rr4[2]>rr5[2]){root[1]=rr4[1];root[2]=rr5[1];root[3]=rr4[2];root[4]=rr5[2];}
			                                                     else if (rr4[1]>rr5[1]&&rr4[2]<rr5[2]){root[1]=rr4[1];root[2]=rr5[1];root[3]=rr5[2];root[4]=rr4[2];}
			                                                     else if (rr4[1]<rr5[1]&&rr4[2]<rr5[2]){root[1]=rr5[1];root[2]=rr4[1];root[3]=rr5[2];root[4]=rr4[2];}
			                                                     else if (rr4[1]<rr5[1]&&rr4[2]>rr5[2]){root[1]=rr5[1];root[2]=rr4[1];root[3]=rr4[2];root[4]=rr5[2];}
											                     return 4;}
											       else if(q4==0&&q5==0){
												                    if (rr4[1]>rr5[1]) {root[1]=rr4[1];root[2]=rr4[2];root[3]=rr5[1];root[4]=rr5[2];}
																	else if (rr4[1]<rr5[1]) {root[1]=rr5[1];root[2]=rr5[2];root[3]=rr4[1];root[4]=rr4[2];}
											                        return 0;}
												    }
									 }
	else if (q1==0&&q2==0){//4 complex roots
		              if (rr1[1]>rr2[1]){root[1]=rr1[1];root[2]=rr1[2];root[3]=rr2[1];root[4]=rr2[2];}
					  else {root[1]=rr2[1];root[2]=rr2[2];root[3]=rr1[1];root[4]=rr1[2];}
	                  return 0;}
					  
	else if (q1==0||q2==0){//two real roots and a pair of complex roots
		                   if (q1==0){root[1]=rr2[1];root[2]=rr2[2];root[3]=rr1[1];root[4]=rr1[2];}
						   else {root[1]=rr1[1];root[2]=rr1[2];root[3]=rr2[1];root[4]=rr2[2];}
						   return 2;}
    else if (q1==1&&q2==1){//two pairs of distinct real roots 
		              if (fabs(rr1[1]-rr2[1])<e){root[1]=rr1[1];root[2]=rr1[2];root[3]=rr2[1];root[4]=rr2[2]; return 1;}//two paris are equal
					  else if(rr1[1]>rr2[1]){root[1]=rr1[1];root[2]=rr1[2];root[3]=rr2[1];root[4]=rr2[2]; return 3;}// not equal
	                  else if(rr1[1]<rr2[1]){root[1]=rr2[1];root[2]=rr2[2];root[3]=rr1[1];root[4]=rr1[2];return 3;}}
	else if (q1==1||q2==1){
		                  if (q1==1){
							        if (fabs(rr1[1]-rr2[1])<e||fabs(rr1[1]-rr2[2])<e){root[1]=rr2[1];root[2]=rr1[1];root[3]=rr1[2];root[4]=rr2[2];return 1;}
									else if(rr1[1]>rr2[1]){root[1]=rr1[1];root[2]=rr1[2];root[3]=rr2[1];root[4]=rr2[2];return 3;}//three distinct real roots
									else if (rr1[1]<rr2[2]) {root[1]=rr2[1];root[2]=rr2[2];root[3]=rr1[1];root[4]=rr1[2];return 3;}
						            else if (rr1[1]<rr2[1]&&rr1[1]>rr2[2]) {root[1]=rr2[1];root[2]=rr1[1];root[3]=rr1[2];root[4]=rr2[2];return 3;}}//three repeated roots
						            
						  else if (q2==1){
							             if (fabs(rr1[1]-rr2[1])<e||fabs(rr1[2]-rr2[1])<e){root[1]=rr1[1];root[2]=rr2[1];root[3]=rr2[2];root[4]=rr1[2];return 1;}
 										 else if(rr2[1]<rr1[2]){root[1]=rr1[1];root[2]=rr1[2];root[3]=rr2[1];root[4]=rr2[2];return 3;}
										 else if (rr2[1]>rr1[1]){root[1]=rr2[1];root[2]=rr2[2];root[3]=rr1[1];root[4]=rr1[2];return 3;}
						                 else if (rr2[1]<rr1[1]&&rr2[1]>rr1[2]){root[1]=rr1[1];root[2]=rr2[1];root[3]=rr2[2];root[4]=rr1[2];return 3;}}
						   }
    else {
		if (fabs(rr1[1]-rr2[1])<e){
			                if(rr1[2]>rr2[2]){root[1]=rr1[1];root[2]=rr2[1];root[3]=rr1[2];root[4]=rr2[2];}
							else if (rr1[2]<rr2[2]){root[1]=rr1[1];root[2]=rr2[1];root[3]=rr1[2];root[4]=rr2[2];}
							else {root[1]=rr1[1];root[2]=rr2[1];root[3]=rr1[2];root[4]=rr2[2];}
		                    return 3;}
		else if (fabs(rr1[1]-rr2[2])<e){root[1]=rr2[1];root[2]=rr1[2];root[3]=rr2[2];root[4]=rr1[2];return 3;}
		else if (fabs(rr1[2]-rr2[1])<e){root[1]=rr1[1];root[2]=rr1[2];root[3]=rr2[1];root[4]=rr2[2];return 3;}
		else if (fabs(rr1[2]-rr2[2])<e){
			                    if(rr1[1]>rr2[1]){root[1]=rr1[1];root[2]=rr2[1];root[3]=rr1[2];root[4]=rr2[2];}
								else if (rr1[1]<rr2[1]){root[1]=rr2[1];root[2]=rr1[1];root[3]=rr1[2];root[4]=rr2[2];}
								return 3;}
		else {
			  if(rr1[2]>rr2[1]){root[1]=rr1[1];root[2]=rr1[2];root[3]=rr2[1];root[4]=rr2[2];}
			  else if (rr1[1]<rr2[2]){root[1]=rr2[1];root[2]=rr2[2];root[3]=rr1[1];root[4]=rr1[2];}
			  else if (rr1[1]>rr2[1]&&rr1[2]>rr2[2]){root[1]=rr1[1];root[2]=rr2[1];root[3]=rr1[2];root[4]=rr2[2];}
			  else if (rr1[1]>rr2[1]&&rr1[2]<rr2[2]){root[1]=rr1[1];root[2]=rr2[1];root[3]=rr2[2];root[4]=rr1[2];}
			  else if (rr1[1]<rr2[1]&&rr1[2]<rr2[2]){root[1]=rr2[1];root[2]=rr1[1];root[3]=rr2[2];root[4]=rr1[2];}
			  else if (rr1[1]<rr2[1]&&rr1[2]>rr2[2]){root[1]=rr2[1];root[2]=rr1[1];root[3]=rr1[2];root[4]=rr2[2];}
			  return 4;}
}}					
	