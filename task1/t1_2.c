#include<stdio.h>
/* Task 1 number 10 */

bool f(int x, int* y){
	*y = 1;
	if (x > 0)
		return true;
	else
		return false;
}

int main(){
	int y = 0;
	int x = -3;
	if (true || f(x, &y)) /* f не выполняется => y = 0 */
		printf("%d\n", y);
	
	if (f(x, &y) || true) /* f выполняется => y = 1 */
		printf("%d\n", y);
	
	if (true && f(x, &y)){
		printf("test");
	}
	return 0;}
