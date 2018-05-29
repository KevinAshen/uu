//
#include<stdio.h>
int main (void)
{
	double i;
	double a,b,c,d,p,q;
	scanf ("%lf %lf %lf %lf",&a,&b,&c,&d);
	for (i=-100;i<101;i+=0.01) {
		if ((a*i*i*i+b*i*i+c*i+d)<=0.0005&&(a*i*i*i+b*i*i+c*i+d)>=-0.0005) {
			printf ("%.2lf ",i);
		}
	}
	return 0;
}
