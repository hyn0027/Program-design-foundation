#include <iostream>  
#include <cstring> 
#include <algorithm>
#include <cstdio>
using namespace std;
int n;
void out(int i){
	for(int j = 0; j < n - i - 1; j++)
		printf(" ");
	for(int j = 0; j < 2 * i + 1; j++)
		printf("*");
	printf("\n");
}
int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		out(i);
	for(int i = n - 2; i >= 0; i--)
		out(i);
	return 0;
}
