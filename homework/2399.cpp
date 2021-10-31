#include <iostream>  
#include <cstring> 
#include <algorithm>
#include <cstdio>
using namespace std;
const int MAXT = 1e3 + 5;
struct book {
	char tp[10], name[15];
	int num;
	friend bool operator <(book a, book b) {
		return a.num < b.num;
	}
}s[MAXT];
int cnt;
int main() {
	int T, mmax, c;
	char dem[15];
	scanf("%d", &T);
	while (T--) {
		scanf("%s", dem);
		if (strcmp(dem, "ENLIST") == 0) {
			scanf("%s %s %d", s[cnt].tp, s[cnt].name, &s[cnt].num);
			cnt++;
		}
		else if (strcmp(dem, "REMOVE") == 0) {
			scanf("%s", dem);
			for (int i = 0; i < cnt; i++)
				if (strcmp(dem, s[i].name) == 0)
					s[i].num = -1;
		}
		else if (strcmp(dem, "REFINE") == 0) {
			scanf("%s", dem);
			mmax = -1;
			for (int i = 0; i < cnt; i++)
				if (strcmp(dem, s[i].tp) == 0)
					mmax = max(mmax, s[i].num);
			c = cnt;
			if (mmax != -1)
				for (int i = 0; i < c; i++)
					if (strcmp(dem, s[i].tp) == 0 && s[i].num == mmax)
						s[cnt++] = s[i];
			for (int i = 0; i < c; i++)
				if (strcmp(dem, s[i].tp) == 0) {
					s[i].num = -1;
				}
		}
		else if (strcmp(dem, "CLEANUP") == 0) {
			scanf("%s", dem);
			for (int i = 0; i < cnt; i++)
				if (strcmp(dem, s[i].tp) == 0)
					s[i].num = -1;
			sort(s, s + cnt);
		}
	}
	int cc = 0;
	for (int i = cnt - 1; i >= 0; i--)
		if (s[i].num != -1) {
			cc++;
			printf("%s %s %d\n", s[i].tp, s[i].name, s[i].num);
			if (cc == 3)
				break;
		}
	if (cc == 0)
		printf("NULL\n");
	return 0;
}
