#include <iostream>  
#include <cstring> 
#include <algorithm>
#include <cstdio>
using namespace std;
char s[30][30];
int n;
inline void out(int i){
	for(int j = 1; j <= n; j++)
		printf("%c", s[i][j]);
	for(int j = n - 1; j >= 1; j--)
		printf("%c", s[i][j]);
	printf("\n");
	
}
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			s[i][j] = '.';
	for(int i = 1; i <= n; i++){
		s[i][i] = 'A' + i - 1;
		s[i][n] = 'A' + i - 1;
		s[n][i] = 'A' + i - 1;
	}
	for(int i = 1; i <= n; i++)
		out(i);
	for(int i = n - 1; i >= 1; i--)
		out(i);
	return 0;
}
