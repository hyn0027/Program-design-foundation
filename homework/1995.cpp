#include <iostream>  
#include <cstring> 
#include <algorithm>
#include <cstdio>
using namespace std;
const int MAXN = 20 + 5;
int n, s[MAXN][MAXN], x, y, cnt;
inline void nex() {
	if (y == 0 && x == 0) {
		x++;
		return;
	}
	if (x == n - 1 && y == 0) {
		if (n % 2 == 0)	x--;
		y++;
		return;
	}
	if (x == 0 && y == n - 1) {
		if (n % 2)	y--;
		x++;
		return;
	}
	if ((y == 0 || y == n - 1) && x - 1 >= 0 && s[x - 1][y] != cnt - 1) {
		x++;
		return;
	}
	if ((x == 0 || x == n - 1) && y - 1 >= 0 && s[x][y - 1] != cnt - 1) {
		y++;
		return;
	}
	if (y == 0 || x == n - 1) {
		x--;
		y++;
		return;
	}
	if (x == 0 || y == n - 1) {
		x++;
		y--;
		return;
	}
	if (s[x + 1][y - 1] == 0) {
		x++;
		y--;
		return;
	}
	x--;
	y++;
	return;
}
int main() {
	scanf("%d", &n);
	while (cnt < n * n) {
		s[x][y] = ++cnt;
		nex();
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf("%d ", s[i][j]);
		printf("\n");
	}
	return 0;
}
