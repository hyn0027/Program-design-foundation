#include <iostream>  
#include <cstring> 
#include <algorithm>
#include <cstdio>
using namespace std;
void out_first(int b){
	for(int i = 0; i < b; i++)
		printf("*");
	printf("\n");
	return;
}
void out_second(int b){
	printf("*");
	for(int i = 0; i < b - 2; i++)
		printf(" ");
	printf("*\n");
	return;
}
void out(int a, int b){
	out_first(b);
	for(int i = 0; i < a - 2; i++)
		out_second(b);
	out_first(b);
	return;
}
int main(){
	int a, b;
	scanf("%d%d", &a, &b);
	out(a, b); 
	return 0;
}
