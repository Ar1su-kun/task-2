#include<stdio.h>


int main(){
	double x;
	double a;
	double f = 0;
    double d = 0;

	scanf("%lf", &x);

	while (scanf("%lf", &a) != EOF){
        d = d*x + f;
        f = f*x + a;
	}
	printf("%.10g", d);
	return 0;
}
