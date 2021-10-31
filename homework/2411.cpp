#include <iostream>  
#include <cstring> 
#include <algorithm>
#include <cstdio>
using namespace std;
inline bool check(char c){
	if(c >= 'a' && c <= 'z')	return true;
	if(c >= 'A' && c <= 'Z')	return true;
	return false;
}
int main(){
	char s[5005], c;
	int cnt = 0;
	while((c = getchar()) != EOF){
		if(c == '\n')	break;
		if(check(c))
			s[cnt++] = c;
		else{
			for(int i = cnt - 1; i >= 0; i--)
				printf("%c", s[i]);
			cnt = 0;
			printf("%c", c);
		}
	}
	for(int i = cnt - 1; i >= 0; i--)
		printf("%c", s[i]);
	printf("\n");
	return 0;
}
