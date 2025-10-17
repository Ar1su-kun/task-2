#include<stdio.h>
/* Task 1 number 19 */
int main(){
	double x = 132.132132; 	/* 0 <= x < 255 */
	double y = -245;			/* y < 0 */
	double z = 310.345; 	/* z >= 255 */
	unsigned char o;
	o = (char)x;			/* o = trunc(x) */
	printf("%d\n", o);
	o = (char)y;			/* o = (2**N + trunc(y)) % 2**N */
	printf("%d\n", o);
	o = (char)z;			/* o = (trunc(y)) % 2**N */
	printf("%d\n", o);
	return 0;
}
