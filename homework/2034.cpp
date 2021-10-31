#include <iostream>  
#include <cstring> 
#include <algorithm>
#include <cstdio>
using namespace std;
const int MAXN = 1e2 + 5, INF = 2147483647;
int n, s[MAXN]; 
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &s[i]);
	for (int i = 0, min, pos; i < n; i++) {
		min = INF;
		for (int j = i; j < n; j++)
			if (s[j] < min) {
				min = s[j];
				pos = j;
			}
		swap(s[i], s[pos]);
		printf("swap(a[%d], a[%d]):", i, pos);
		for (int j = 0; j < n; j++)
			printf("%d ", s[j]);
		printf("\n");
	}
	return 0;
}
