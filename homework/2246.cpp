#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXN = 1e6 + 5;
inline int px(char *s) {
	if (s[0] == 'A')
		return 1;
	if (s[0] == 'J')
		return 11;
	if (s[0] == 'Q')
		return 12;
	if (s[0] == 'K')
		return 13;
	if (s[0] == '1' && s[1] == '0')
		return 10;
	return s[0] - '0'; 
}
struct Poker {
	int nex, bef;
	char color[10], num[5];
	friend bool operator <(Poker a, Poker b) {
		return px(a.num) > px(b.num);
	}
}s[MAXN];
int head, tail, cnt, size;
int main() {
	int t;
	scanf("%d", &t);
	char d[20];
	while(t--) {
		scanf("%s", d);
		if (strcmp(d, "Append") == 0) {
			scanf("%s%s", s[cnt].color, s[cnt].num);
			size++;
			if (size == 1) {
				head = tail = cnt;
				s[cnt].nex = s[cnt].bef = -1;
			}
			else {
				s[cnt].nex = tail;
				s[tail].bef = cnt;
				tail = cnt;
				s[cnt].bef = -1;
			}
			cnt++;
		}
		else if (strcmp(d, "Extract") == 0) {
			scanf("%s", d);
			int c = cnt;
			for (int i = head; i != -1; i = s[i].bef)
				if (strcmp(s[i].color, d) == 0) {
					s[cnt] = s[i];
					s[cnt].bef = head;
					s[head].nex = cnt;
					head = cnt;
					s[cnt].nex = -1;
					cnt++;
					if(i != tail) {
						s[s[i].bef].nex = s[i].nex;
						s[s[i].nex].bef = s[i].bef;
					}
					else{
						tail = s[i].nex;
						s[tail].bef = -1;
					}
				}
			if(c != cnt) {
				int bef = s[c].bef;
				sort(s + c, s + cnt);
				for (int i = c; i < cnt; i++) {
					s[i].bef = i - 1;
					s[i].nex = i + 1;
				}
				s[c].bef = bef;
				s[cnt - 1].nex = -1;
			}
		}
		else if (strcmp(d, "Revert") == 0) {
			for (int i = head; i != -1; i = s[i].bef)
				s[i].nex = s[i].bef;
			s[tail].nex = -1;
			for (int i = head, j = -1; i != -1; i = s[i].nex) {
				s[i].bef = j;
				j = i;
			}
			swap(head, tail);
		}
		else if (strcmp(d, "Pop") == 0) {
			if (size > 1) {
				head = s[head].bef;
				s[head].nex = -1;
				size--;
			}
			else {
				size = 0;
				head = tail = -1;
			}
		}
	}
	if (size == 0)
		printf("null");
	else
		printf("%s %s\n", s[head].color, s[head].num);
	return 0;
}
