#include <iostream>  
#include <cstring> 
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	int s[5];
	for(int i = 0; i < 4; i++)
		scanf("%d", &s[i]); 
	sort(s, s + 4);
	for(int i = 0; i < 3; i++)
		printf("%d ", s[i]);
	printf("%d\n", s[3]); 
	return 0;
}
