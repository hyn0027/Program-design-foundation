#include <iostream>  
#include <cstring> 
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 15;
int n, ans[maxn];
bool like[maxn][maxn], vis[maxn];
void dfs(int c) {
	if (c == n + 1) {
		for (int i = 1; i <= n; i++)
			printf("%d ", ans[i]);
		printf("\n");
		return;
	}
	for (int i = 1; i <= n; i++)
		if (!vis[i] && like[i][c]) {
			vis[i] = true;
			ans[c] = i;
			dfs(c + 1);
			vis[i] = false;
		}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &like[i][j]);
	dfs(1);
	return 0;
}
