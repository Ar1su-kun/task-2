#include<stdio.h>


int main(){
	double x;
	double a;
	double res = 0;

	scanf("%lf", &x);

	while (scanf("%lf", &a) != EOF){
        res = res * x + a;
	}
	printf("%.10g\n", res);
	return 0;
}
