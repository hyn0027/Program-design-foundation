#include <iostream>  
#include <cstring> 
#include <algorithm>
#include <cstdio>
#include <fstream>
#include <iomanip>
using namespace std;
const int maxn = 1000000 + 5;
int n, s[maxn], *t[10], cnt[10], l;
inline int find(int x) {
	int ret = 0;
	while (x) {
		x /= 10;
		ret++;
	}
	return ret;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &s[i]);
		l = max(l, find(s[i]));
	}
	for (int i = 0, div = 1; i < l; i++, div *= 10) {
		memset(cnt, 0, sizeof(cnt));
		for (int j = 0, dig; j < n; j++) {
			dig = s[j] / div % 10;
			cnt[dig]++;
		}
		for (int j = 0; j < 10; j++)
			t[j] = new int[cnt[j] + 5];
		memset(cnt, 0, sizeof(cnt));
		for (int j = 0, dig; j < n; j++) {
			dig = s[j] / div % 10;
			t[dig][cnt[dig]++] = s[j];
		}
		n = 0;
		for (int j = 0; j < 10; j++)
			for (int k = 0; k < cnt[j]; k++)
				s[n++] = t[j][k];
		for (int j = 0; j < 10; j++)
			delete t[j];
		for (int j = 0; j < n; j++)
			printf("%d ", s[j]);
		printf("\n");
	}
	return 0;
}
