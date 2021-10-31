#include <iostream>  
#include <cstring> 
#include <algorithm>
#include <cstdio>
using namespace std;
char s[110]; 
int main(){
	scanf("%s", &s);
	int len = strlen(s);
	for(int i = len - 1; i >= 0; i--)
		printf("%c", s[i]);
	printf("\n");
	return 0;
}
