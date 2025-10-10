#include<stdio.h>

double my_abs(double op){		/*в условии запрещены мат. функции, вот и сделал сам*/
	if (op>=0)
		return op;
	else
		return -op;
}

double horner_root(double num, double eps){
	double x1 = 1;
	double x2 = (x1 + num/x1)/2;
	while (my_abs(x1 - x2) > eps){
		x1 = x2;
		x2 = (x1 + num/x1)/2;
	}
	return x1;
}

int main(){
	double eps;
	double num;

	scanf("%lf", &eps);
	while (scanf("%lf", &num) != EOF) {
		printf("%.10g\n",  horner_root(num, eps));
	}
	return 0;
}
