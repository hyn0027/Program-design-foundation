#include <algorithm> 
#include <cstring>
#include <cstdio>
#include <iostream>
#include <fstream> 

using namespace std;

bool flag[200];

inline bool check(char *s) {
	for (int i = 1; i < 9; i++)
		if (s[i] != s[0])
			return false;
	return true;
}

int main() {
	char s[20];
	for (int i = 0; i < 6; i++){
		scanf("%s", s);
		if (check(s)) {
			flag[s[0]] = 1;
		}
		else {
			printf("-1\n");
			return 0;
		}
	}
	if (flag['B'] && flag['G'] && flag['O'] && flag['R'] && flag['Y'] && flag['W'])
		printf("1\n");
	else
		printf("-1\n"); 
	return 0;
}
