#include <iostream>  
#include <cstring> 
#include <algorithm>
#include <cstdio>
using namespace std;
const int MAXN = 1e2 + 5;
int n, a[MAXN]; 
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i = 1, j, cur; i <= n; i++){
		printf("Insert element[%d]:\n  Init:", i);
		for(j = 1; j <= i; j++)
			printf("%d ", a[j]);
		printf("\n");
		cur = a[i];
		j = i - 1;
		for(; j >= 1; j--){
			if(a[j] > cur){
				a[j + 1] = a[j]; 
				printf("  Move back:");
				for(int k = 1; k <= i; k++)
					printf("%d ", a[k]);
				printf("\n");
			}
			else
				break;
		} 
		a[j + 1] = cur;
		printf("  Final:");
		for(j = 1; j <= i; j++)
			printf("%d ", a[j]);
		printf("\n");
	}
	return 0;
}
