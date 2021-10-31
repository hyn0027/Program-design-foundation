#include <iostream>  
#include <cstring> 
#include <algorithm>
#include <cstdio>
using namespace std;
int n, s[30][30]; 
int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf("%d", &s[i][j]);
	for(int i = 0; i < n; i++){
		for(int j = n - 1; j >= 0; j--)
			printf("%d ", s[j][i]);
		printf("\n");
	}
	return 0;
}
