#include <iostream>  
#include <cstring> 
#include <algorithm>
#include <cstdio>
using namespace std;
int s[5], cnt[5];
bool check(int i){
	return (s[i] + cnt[i] == 3);
}
void output(){
	for(int i = 1; i < 4; i++){
		for(int j = 1; j < 4; j++)
			if(s[j] == i)
				printf("%c ", 'A' + j - 1);
	}
	printf("\n");
}
int main(){
	for(int i = 1; i < 4; i++){
		s[1] = i;
		for(int j = 1; j < 4; j++){
			if(j == i)	continue;
			s[2] = j;
			s[3] = 6 - i - j;
			cnt[1] = (s[2] > s[1]) + (s[3] == s[1]);
			cnt[2] = (s[1] > s[2]) + (s[1] > s[3]);
			cnt[3] = (s[3] > s[2]) + (s[2] > s[1]);
			if(check(1) && check(2) && check(3))
				output();
		}
	} 
	return 0;
}
