#include <iostream>  
#include <cstring> 
#include <algorithm>
#include <cstdio>
using namespace std;
bool vis[1 << 6], found;//from right to left 0right 1left
int t[6] = {1, 3, 6, 8, 12}, step[500][2], cnt;
char name[6] = "ABCDE";
inline void out() {
	for (int i = 0; i < cnt; i++) {
		if (step[i][1] == -1)
			printf("%c ", name[step[i][0]]);
		else
			printf("%c%c ", name[step[i][0]], name[step[i][1]]);
	}
	printf("\n");
	return;
}
inline bool pd(int sta, int i) {
	if (!((sta & (1 << i)) >> i) && !((sta & (1 << 5)) >> i))
		return true;
	if (((sta & (1 << i)) >> i) && ((sta & (1 << 5)) >> i))
		return true;
	return false;
}
void search(int sta, int time) {
	if (time > 30)
		return;
	if (sta == (1 << 6) - 1) {
		out();
		found = true;
		return;
	}
	if (vis[sta])
		return;
	vis[sta] = 1;
	for (int i = 0; i < 5; i++) {
		if (pd(sta, i)) {
			step[cnt++][0] = i;
			search((sta ^ (1 << i)) ^ (1 << 5), time + t[i]);
			step[--cnt][0] = -1;
			if (found)
				return;
			for (int j = 0; j < 5; j++) {
				if (j == i || !pd(sta, j))
					continue;
				step[cnt][0] = i;
				step[cnt++][1] = j;
				search(((sta ^ (1 << i)) ^ (1 << j)) ^ (1 << 5), time + max(t[i], t[j]));
				step[--cnt][0] = -1;
				step[cnt][1] = -1;
				if (found)
					return;
			}
		}
	}
	return;
}
int main() {
	memset(step, -1, sizeof(step));
	search(0, 0);
	return 0;
}
