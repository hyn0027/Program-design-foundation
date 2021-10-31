#include <iostream>  
#include <cstring> 
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
int main(){
	int t, a, b, sum = 0;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &a);
		b = a;
		if(a % 2 == 1)	a %= 3;
		sum += abs(a - b);
		printf("%d ", a);
	}
	printf("\n%d\n", sum);
	return 0;
}
