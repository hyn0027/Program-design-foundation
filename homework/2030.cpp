#include <iostream>  
#include <cstring> 
#include <algorithm>
#include <cstdio>
using namespace std;
const int MAXN = 1e3 + 5;
int s[MAXN][MAXN], n, f[MAXN][MAXN];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
			scanf("%d", &s[i][j]);
	for (int i = 0; i < n; i++)
		f[n - 1][i] = s[n - 1][i];
	for (int i = n - 2; i >= 0; i--)
		for (int j = 0; j <= i; j++)
			f[i][j] = max(f[i + 1][j], f[i + 1][j + 1]) + s[i][j];
	printf("%d\n", f[0][0]);
	return 0;
}
