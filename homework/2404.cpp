#include <iostream>  
#include <cstring> 
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	int x;
	scanf("%d", &x);
	if(x % 100 == 0)
		if(x % 400 == 0)
			printf("YES\n");
		else
			printf("NO\n");
	else if(x % 4 == 0)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
