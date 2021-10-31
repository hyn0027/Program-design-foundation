#include <iostream>  
#include <cstring> 
#include <algorithm>
#include <cstdio>
using namespace std;
const int MAXN = 20;
int n, m, s[MAXN][MAXN];
int ans(int x, int y) {
	if (x > n || y > m || y < 0)
		return 0;
	if (s[x][y] == -2)
		return 0;
	if (s[x][y] != -1)
		return s[x][y];
	if (x == n && y == m)
		return s[x][y] = 1;
	return s[x][y] = ans(x + 1, y + 2) + ans(x + 1, y - 2) + ans(x + 2, y + 1) + ans(x + 2, y - 1);
}
int main() {
	memset(s, -1, sizeof(s));
	int k, x, y;
	scanf("%d%d%d", &n, &m, &k);
	while(k--) {
		scanf("%d%d", &x, &y);
		s[x][y] = -2;
	}
	printf("%d\n", ans(0, 0));
	return 0;
}
