#include <iostream>  
#include <cstring> 
#include <algorithm>
#include <cstdio>
using namespace std;
const int MAXL = 1e3 + 5;
struct Position {
	int x, y;
}man;
int n;
inline void out() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			if (man.x == i && man.y == j)	printf("H ");
			else	printf("_ ");
		printf("\n");
	}
	printf("\n");
}
inline void work (char c) {
	if (c == 'w')	man.x = max(man.x - 1, 0);
	else if (c == 's')	man.x = min(man.x + 1, n - 1);
	else if (c == 'a')	man.y = max(man.y - 1, 0);
	else if (c == 'd')	man.y = min(man.y + 1, n - 1);
	out();
}
int main() {
	char operation[MAXL], c;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			scanf("%c", &c);
			scanf("%c", &c);
			if(c == 'H') man = {i, j};
		}
	scanf("%s", &operation);
	int l = strlen(operation);
	for(int i = 0; i < l; i++)
		work(operation[i]);
	return 0;
}
