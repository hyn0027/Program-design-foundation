#include <iostream>  
#include <cstring> 
#include <algorithm>
#include <cstdio>
using namespace std;
const int MAXN = 25;
int n, ans;
bool column[MAXN], diagonal[2][MAXN];
void dfs(int c) {
	if (c == n + 1) {
		ans++;
		return;
	}
	for (int i = 1; i <= n; i++)
		if (!column[i] && !diagonal[0][c - i + n] && !diagonal[1][c + i]) {
			column[i] = diagonal[0][c - i + n] = diagonal[1][c + i] = 1;
			dfs(c + 1);
			column[i] = diagonal[0][c - i + n] = diagonal[1][c + i] = 0;
		}
	return;
}
int main() {
	scanf("%d", &n);
	dfs(1);
	printf("%d\n", ans);
	return 0;
}
