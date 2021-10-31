#include <iostream>  
#include <cstring> 
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
int x, k;
void work(int a, int num){
	if(k == 1){
		printf("%d\n", a + x);
		return;
	}
	if(k == 2){
		printf("%d\n", a * x);
		return;
	}
	if(k == 3){
		if(a == 0)	printf("%d\n", x);
		else	printf("%d%d\n", a, x);
		return;
	}
	if(k == 4){
		if(num % 2 == 0)	a %= x;
		printf("%d\n", a);
		return;
	} 
}
int main(){
	int n, a;
	scanf("%d%d%d", &n, &k, &x);
	for(int i = 0; i < n; i++){
		scanf("%d", &a);
		work(a, i);
	}
	return 0;
}
