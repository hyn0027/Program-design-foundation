#include <iostream>  
#include <cstring> 
#include <algorithm>
#include <cstdio>
using namespace std;
const int MAXN = 1e2 + 5;
struct Person {
	char name[25];
	int m, d, id;
	friend bool operator <(Person a, Person b) {
		if (a.m != b.m)
			return a.m < b.m;
		if (a.d != b.d)
			return a.d < b.d;
		return a.id < b.id;
	}
}s[MAXN];
int n;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s%d%d", &s[i].name, &s[i].m, &s[i].d);
		s[i].id = i;
	}
	sort(s, s + n);
	for (int i = 0; i < n; i++) {
		if (s[i].m != s[i + 1].m || s[i].d != s[i + 1].d)
			continue;
		printf("%d %d %s", s[i].m, s[i].d, s[i].name);
		while(s[i].m == s[i + 1].m && s[i].d == s[i + 1].d) {
			printf(" %s", s[i + 1].name);
			i++;
		}
		printf("\n");
	}
	return 0;
}
