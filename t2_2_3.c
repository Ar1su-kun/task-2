#include<stdio.h>
int main(){
    double x;
    double a; 
    double res;
    int n;

    scanf("%d", &n);
    scanf("%lf", &x);
    n++;

    res = 0;

    while(scanf("%lf", &a) != EOF){
        res = (res + a/n)*x;
        
        n--;
    }
    printf("%.10g\n", res);
}
