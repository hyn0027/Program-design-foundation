#include <iostream>  
#include <cstring> 
#include <algorithm>
#include <cstdio>
using namespace std;
inline bool check(char c){
	if(c >= 'a' && c <= 'z')	return true;
	if(c >= 'A' && c <= 'Z')	return true;
	if(c >= '0' && c <= '9')	return true;
	return false;
}
inline char down(char c){
	if(c >= 'A' && c <= 'Z')	return c + 'a' - 'A';
	return c;
} 
inline bool same(char a, char b){
	a = down(a), b = down(b);
	return (a == b);
}
int main(){
	char s[110];
	int len, l, r;
	bool flag = 1;
	cin.getline(s, 101);
	len = strlen(s);
	l = 0;
	r = len - 1;
	while(!check(s[l]) && l < r)	l++;
	while(!check(s[r]) && l < r)	r--;
	while(l < r){
		if(!same(s[l], s[r])){
			flag = 0;
			break;
		}
		l++, r--;
		while(!check(s[l]) && l < r)	l++;
		while(!check(s[r]) && l < r)	r--;
	}
	printf("%d\n", flag);
	return 0;
}
