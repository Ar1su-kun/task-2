#include<stdio.h>
#include<time.h>

long long iterativeFibonachi(int n){
	long long a = 0;
	long long b = 1;
	if (n == 0)
		return a;
	for (int i = 1; i < n; i++){
		b += a;
		a = b - a;	
	}
	return b;
	
}

long long recursiveFibonachi( int n){
	if (n <= 1)
		return n;
	else
		return recursiveFibonachi(n - 1) + recursiveFibonachi(n - 2);
} 

int main(){
	int n;
	clock_t iterativeStart, iterativeEnd, recursiveStart, recursiveEnd;
	
	while (scanf("%d", &n) != EOF){	
		iterativeStart = clock();
		printf("Iterative way: \t%lld", iterativeFibonachi(n));
		iterativeEnd = clock();
		printf("\tTime: %.10g \tmicrosec\n", 1000000 * ((double) (iterativeEnd- iterativeStart) / CLOCKS_PER_SEC));

		recursiveStart = clock();
		printf("Recursive way:\t%lld", recursiveFibonachi(n));
		recursiveEnd = clock();		
		printf("\tTime: %.10g \tmicrosec\n", 1000000 * ((double) (recursiveEnd- recursiveStart) / CLOCKS_PER_SEC));
			}

	return 0;
}
