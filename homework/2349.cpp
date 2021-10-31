#include <iostream>  
#include <cstring> 
#include <algorithm>
#include <cstdio>
using namespace std;
const int INF = 1e9;
int n, m, ans = INF; 
int vis[11][11][2];//from right to left; wolf num in the right; sheep num in the right; man pos0right1left;
inline bool unvalid(int wolf, int sheep) {
	if (wolf < 0 || wolf > n || sheep < 0 || sheep > n)
		return true;
	if (sheep > 0 && wolf > sheep)
		return true;
	if (n - sheep > 0 && wolf < sheep)
		return true;
	return false;
}
void search(int wolf, int sheep, int man, int cnt) {
	cout << sheep << " " << wolf << " " << man << " " << cnt <<endl;
	if (wolf == 0 && sheep == 0 && man == 1) {
		ans = min(ans, cnt);
		return;
	}
	if (unvalid(wolf, sheep))
		return;
	if (vis[wolf][sheep][man] <= cnt)
		return;
	vis[wolf][sheep][man] = cnt;
	for (int w = 1; w <= m; w++) 
		search(wolf + w * (man * 2 - 1), sheep, (man + 1) % 2, cnt + 1);
	for (int s = 1; s <= m; s++) 
		for (int w = 0; w <= s && w + s <= m; w++)
			search(wolf + w * (man * 2 - 1), sheep + s * (man * 2 - 1), (man + 1) % 2, cnt + 1);
}
int main() {
	scanf("%d%d", &n, &m);
	memset(vis, 127, sizeof(vis));
	search(n, n, 0, 0);
	if (ans == INF)
		ans = -1;
	printf("%d\n", ans);
	return 0;
}
