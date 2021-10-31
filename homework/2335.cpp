#include <iostream>  
#include <cstring> 
#include <algorithm>
#include <cstdio>
#include <fstream>
#include <iomanip>
using namespace std;
const int MAXN = 15;
int n, s[MAXN], h;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &s[i]);
		h = max(h, s[i]);
	}
	for (int i = h + 1; i > 0; i--) {
		for (int j = 0; j < n; j++)
			if (s[j] < i)
				printf(".");
			else
				printf("@");
		printf("\n");
	}
	return 0;
}
