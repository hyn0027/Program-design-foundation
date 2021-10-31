#include <iostream>  
#include <cstring> 
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	int a, b;
	scanf("%d%d", &a, &b);
	a = (a / 10) % 10;
	if(a == b)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
