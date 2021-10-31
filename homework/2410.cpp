#include <iostream>  
#include <cstring> 
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
const int MAXN = 5e4;
char s[MAXN + 5]; 
int cnt[30], total;
inline void add(char c){
	if(c >= 'a' && c <= 'z')
		c += 'A' - 'a';
	if(c >= 'A' && c <= 'Z'){
		cnt[c - 'A']++;
		total++;
	} 
}
int main(){
	cin.getline(s, MAXN);
	int l = strlen(s);
	for(int i = 0; i < l; i++)
		add(s[i]);
	cout << endl;
	for(int i = 0; i < 26; i++)
		printf("%c %.2lf%\n", i + 'a', cnt[i] * 100.0 / total);
	return 0;
}
