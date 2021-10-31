#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXN = 1e3 + 10;
int n, m, f[MAXN], a[MAXN];
int main() {
	memset(f, -1, sizeof(f));
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0, b; i < n; i++){
		scanf("%d", &b);
		f[a[i]] = max(f[a[i]], b);
	}
	for (int i = 1; i <= m; i++) {
		if (i % 2 == 0 && f[i / 2] != -1)
			f[i] = max(f[i], f[i / 2] * 2 + 233);
		for (int j = 1; j <= i / 2; j++)
			if (f[j] != -1 && f[i - j] != -1)
				f[i] = max(f[i], f[j] + f[i - j]);
	}
	printf("%d\n", f[m]);
	return 0;
}
