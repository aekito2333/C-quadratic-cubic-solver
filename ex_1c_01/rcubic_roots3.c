#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>
#include <limits.h>
//<Surname: Yu> <First name: Xuesong> <M3SC>
int quad_roots(double *a,double *rr);
int rcubic_roots(double *a,double *r){
	double a2[3], rr[3];
	double alpha, beta, p,p2,pr,pr1,pr2,y,y0,y1,y2,py;
	double three=3,two=2,twoseven=27,zero=0,one=1,nine=9,eleven=11;
	int q,n;
	beta=-a[2]/three;
	alpha=cbrt(a[1]*a[2]/three-two*a[2]*a[2]*a[2]/twoseven-a[0]);
	p=-one/(alpha*alpha)*(a[1]-(a[2]*a[2])/three);
	py=cbrt(-one/two);
	
	if (fabs(a[2])<10e-13&&fabs(a[1])<10e-13) {pr=cbrt(-a[0]);  
	                             r[1]=pr;r[2]=pr*(-one/two);r[3]=fabs(pr*sqrt(three)/two);
	                             return 0;}//one real two complex                            
	
	else if (fabs(a[0]-a[1]*a[2])<10e-13) {pr=sqrt(fabs(a[1])); 
	                        
							if (a[1]>zero){r[1]=-a[2];r[2]=zero;r[3]=fabs(pr); return 0;}//one real two complex
	                        else{if(-a[2]<-pr){r[1]=pr;r[2]=-pr;r[3]=fabs(a[2]);}
								else if(-a[2]>pr){r[1]=-a[2];r[2]=pr;r[3]=-pr;}
								else{r[1]=pr;r[2]=-a[2];r[3]=-pr;}
	                            if (r[1]==r[2]||r[1]==r[3]||r[2]==r[3]){return 2;}
								else {return 31;}
	                          }}//three real roots 		
								
	else if (a[0]!=zero && fabs(a[1]-one/three*a[2]*a[2])<10e-13 && fabs(a[0]-one/twoseven*a[2]*a[2]*a[2])<10e-13){
		                                            pr=-a[2]/three; r[1]=pr; r[2]=pr; r[3]=pr;return 1;}//triple root     
   
    else if (fabs(py*py*py+p*py-one)<10e-13 && fabs(three*py*py+p)<10e-13){p2=-three*cbrt(one/two)*cbrt(one/two);
		                             
							   if (fabs(p-p2)<10e-13){pr1=alpha*py+beta;//repeated
		                                                   pr2=alpha*one/(py*py)+beta;
		                                                   if (pr1>pr2) {r[1]=pr1;r[2]=pr1;r[3]=pr2;}
														   else {r[1]=pr2;r[2]=pr1;r[3]=pr1;}
	                                                       return 2;}}//repeated real roots 
														   
	else if (fabs(a[0])<10e-13||fabs(alpha)<10e-13) {if(fabs(alpha)<10e-13){pr=zero;
	                                              q=quad_roots(a,rr);}
	                                 
									   else       {pr=-a[2]/three;//find a real root
									              a2[0]=a[1]-two*a[2]*a[2]/nine;
												  a2[1]=two*a[2]/three;
												  a2[2]=one;
												  //a2={a[1]-two*a[2]*a[2]/nine,two*a[2]/three,one};
	                                              q=quad_roots(a2,rr);}
									 
									 if (q==0)   {r[1]=pr;r[2]=rr[1];r[3]=fabs(rr[2]);return 0;}//a pair of imaginary roots
	                                 else if (q==1) {if(pr>rr[1]) {r[1]=pr;r[2]=rr[1];r[3]=rr[2];return 2;}
					                                 else if(pr<rr[1]) {r[1]=rr[1];r[2]=rr[2];r[3]=pr;return 2;}//a pair of repeated real roots
					                                 else {r[1]=rr[1];r[2]=rr[2];r[3]=pr; return 1;}}//triple root
					                 else if (q==2) {if(pr>rr[1]) {r[1]=pr;r[2]=rr[1];r[3]=rr[2]; return 32;}
					                                 else if (pr<rr[2]) {r[1]=rr[1];r[2]=rr[2];r[3]=pr; return 33;}
					                                 else if (pr==rr[1]||pr==rr[2]) {r[1]=rr[1];r[2]=pr;r[3]=rr[2];return 2;}//two repeated roots
	                                                 else {r[1]=rr[1];r[2]=pr;r[3]=rr[2];return 34;}}}//three distinct real roots											
													
	else{if(p>(11/3)) {y=sqrt(p);}//correct
		 else if (p<-1.92) {y=-one/p;}//correct
		 else {y=one+p/three-p*p*p/(nine*nine);} //decide y[0] base on p//correct
			  
			  for (n=0;n<4;n=n+1){
				  y1=y-(y*y*y-p*y-one)/(three*y*y-p);}//iterate 3 times
		          y=y1;//y=y1 records the last output
				  
				  
			  while ((fabs(y2-y1)>10e-13)||fabs(y2-y1)<fabs(y1-y0)){
				  y0=y1;//y[0]
				  y1=y0-(y0*y0*y0-p*y0-one)/(three*y0*y0-p);//y[1]
				  y2=y1-(y1*y1*y1-p*y1-one)/(three*y1*y1-p);}//y[2]
		          
				  py=alpha*y2+beta;//find a root-working
				
		     a2[0]=-a[0]/py;
			 a2[1]=a[2]+py;
			 a2[2]=one;  
			 //printf("py=%g, a2= %g %g %g",py,a2[2],a2[1],a2[0]);
	         q=quad_roots(a2,rr);//in terms y
			 //printf("q=%d, rr= %g %g",q,rr[1],rr[2]);
	    
			  
	//solve quadratic
	pr=py;
	
	     if (q==0)      {r[1]=pr;r[2]=rr[1];r[3]=fabs(rr[2]);r[0]=q;return 0;}//a pair of imaginary roots
	     
		 else if (q==1) {if(pr>rr[1]) {r[1]=pr;r[2]=rr[1];r[3]=rr[2];r[0]=q;return 2;}
					     else if(pr<rr[1]) {r[1]=rr[1];r[2]=rr[2];r[3]=pr;r[0]=q;return 2;}//a pair of repeated real roots
					     else {r[1]=rr[1];r[2]=rr[2];r[3]=pr;r[0]=q; return 1;}}//triple root
					       
		 else if (q==2) {r[0]=q;
		                 if (fabs(pr-rr[1])<10e-13||fabs(pr-rr[2])<10e-13) {if (rr[1]>rr[2]){r[1]=rr[1];r[2]=pr;r[3]=rr[2];}
		                                        else if (rr[2]>rr[1]) {r[1]=rr[2];r[2]=pr;r[3]=rr[1];}
		                }
												
			            else if(pr>rr[1]&&pr>rr[2]) {if(rr[1]>rr[2]){r[1]=pr;r[2]=rr[1];r[3]=rr[2];}
						                         else{r[1]=pr;r[2]=rr[2];r[3]=rr[1];}
						}
					    else if (rr[1]>pr&&rr[1]>rr[2]) {if(pr>rr[2]){r[1]=rr[1];r[2]=pr;r[3]=rr[2];}
						                           else{r[1]=rr[1];r[2]=rr[2];r[3]=pr;}
						}
					    else if (rr[2]>rr[1]&&rr[2]>pr) {if(pr>rr[1]){r[1]=rr[2];r[2]=pr;r[3]=rr[1];}
						                           else{r[1]=rr[2];r[2]=rr[1];r[3]=pr;}
						}
						if (fabs(r[1]-r[2])<10e-13||fabs(r[1]-r[3])<10e-13||fabs(r[2]-r[3])<10e-13)
						{return 2;}
								else {return 35;}	                                                    
}}
}

