#include <iostream>  
#include <cstring> 
#include <algorithm>
#include <cstdio>
using namespace std;
struct Node{
	Node *nex, *before;
	int delay;
	char name[7];
}*flag;//insert node
int cnt;//node num
inline void del(Node *cur) {//delete node cur
	if (strcmp(cur -> name, flag -> name) == 0)
		flag = flag -> nex;
	cur -> before -> nex = cur -> nex;
	cur -> nex -> before = cur -> before;
	delete cur;
	cnt--;
	return;
}
int main() {
	int t, m, n;
	char demand[15];
	Node *cur;//current
	scanf("%d", &t);
	while (t--) {
		scanf("%s", demand);
		if (strcmp(demand, "Append") == 0) {
			if (cnt == 0) {
				flag = new Node;
				scanf("%d %s", &flag -> delay, &flag -> name);
				flag -> nex = flag -> before = flag;
			}
			else {
				cur = new Node;
				scanf("%d %s", &cur -> delay, &cur -> name);
				flag -> before -> nex = cur;
				cur -> before = flag -> before;
				cur -> nex = flag;
				flag -> before = cur;
			}
			cnt++;
		}
		else if (strcmp(demand, "Eliminate") == 0) {
			scanf("%d%d", &m, &n);
			cur = flag -> before;
			while (n--) {
				for (int i = 0; i < m; i++)
					cur = cur -> nex;
				cur = cur -> nex;
				del(cur -> before);
				cur = cur -> before;
			}
		}
		else if (strcmp(demand, "Move") == 0) {
			scanf("%d%d", &m, &n);
			if (m == 0)
				while (n--)
					flag = flag -> nex;
			else
				while (n--)
					flag = flag -> before;
		}
		else if (strcmp(demand, "Sort") == 0) {
			for (int i = cnt - 1; i >= 2; i--) {
				cur = flag -> nex;
				for (int j = 1; j < i; j++) {
					if(cur -> delay > cur -> nex -> delay || (cur -> delay == cur -> nex -> delay && strcmp(cur -> name, cur -> nex -> name) > 0)) {
						swap(cur -> delay, cur -> nex -> delay);
						swap(cur -> name, cur -> nex -> name);
					}
					cur = cur -> nex;
				}
			}
			if(flag -> delay <= flag -> before -> delay) {
				while(flag -> delay > flag -> nex -> delay || (flag -> delay == flag -> nex -> delay && strcmp(flag -> name, flag -> nex -> name) > 0)){
					swap(flag -> delay, flag -> nex -> delay);
					swap(flag -> name, flag -> nex -> name);
					flag = flag -> nex;
				}
			}
		}
		else if (strcmp(demand, "Delete") == 0) {
			scanf("%s", demand);
			cur = flag;
			for (int i = 0; i < cnt; i++) {
				if (strcmp(cur -> name, demand) == 0){
					del(cur);
					break;
				}
				cur = cur -> nex;
			}
		}
	}
	scanf("%s", demand);
	if (cnt == 0) {
		printf("-1\n");
		return 0;
	}
	if (strcmp(demand, flag -> name) == 0) {
		printf("0\n");
		return 0;
	}
	cur = flag;
	bool found = false;
	for (int i = 0; i < cnt; i++) {
		if (strcmp(demand, cur -> name) == 0) {
			found = true;
			break;
		}
		cur = cur -> nex;
	}
	if(!found) {
		printf("-1\n");
		return 0;
	}
	int sum = 0;
	cur = flag;
	for (int i = 0; i < cnt; i++) {
		if (strcmp(demand, cur -> name) == 0) {
			printf("%d\n", sum);
			break;
		}
		printf("%s\n", cur -> name);
		sum += cur -> delay;
		cur = cur -> nex;
	}
	return 0;
}
