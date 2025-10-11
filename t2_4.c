#include<stdio.h>

#define STR_LEN 30

long long power(int a, int b){
	long long res = a;
	if (b == 0)
		return 1;
	for (int i = 1; i < b; i++)
		res *= a;
	return res;
}

double str2double (char str[STR_LEN]){
	int isMantissa = 0;
	int isExponenta = 0;
	int isExponentaPositive = 1;
	double res = 0;
	int mantissaCount = 1;
	int exponentaPower = 0;
	int i = 0;
	for (; i < STR_LEN; i++){
		
		if (str[i] == '\0'){
			break;
		}
		if (str[i] == '.'){
			isMantissa = 1;
			continue;
		}
		if ((str[i] == 'e') || (str[i] == 'E')){
			i++;
			isExponenta = 1;
			break;
		}
		if (!isMantissa){
			res = res * 10 + (str[i] - '0');
		}
		else{
			res += (double)(str[i] - '0') / (double)power(10, mantissaCount);
			mantissaCount++;
		}	
	}
	if (isExponenta){

		if (str[i] == '-'){
			isExponentaPositive = 1;
			i++;
		}
		if (str[i] == '+'){
			i++;
		}
		for (; i < STR_LEN; i++){
			if (str[i] == '\0')
				break;
			exponentaPower = exponentaPower * 10 + (str[i] - '0');
		}
		if (isExponentaPositive)
			res *= power(10, exponentaPower);
		else
			res = res / (double)power(10, exponentaPower);
	}
	return res;
}

int main(){
	char str[STR_LEN];
	while (scanf("%s", str) != EOF){
		printf("%.10g\n", str2double(str));	
	}
	return 0;
}
