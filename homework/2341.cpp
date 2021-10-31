#include <iostream>  
#include <cstring> 
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 20;
int h, n, way[maxn];
bool ban[maxn];
int cnt(int goal) {
	if (goal > h)
		return 0;
	if (way[goal] != -1)
		return way[goal];
	if (ban[goal])
		return way[goal] = 0;
	if (goal == h)
		return way[h] = 1;
	return way[goal] = cnt(goal + 1) + cnt(goal + 2) + cnt(goal + 3);
}
int main() {
	memset(way, -1, sizeof(way));
	scanf("%d%d", &h, &n);
	for (int i = 0, a; i < n; i++) {
		scanf("%d", &a);
		ban[a] = 1;
	}
	printf("%d\n", cnt(0));
	return 0;
}
