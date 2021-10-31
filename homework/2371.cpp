#include <iostream>  
#include <cstring> 
#include <algorithm>
#include <cstdio>
using namespace std;
const int MAXN = 1e6 + 5;
bool notprime[MAXN];
int prime[MAXN], cnt;
void init() {
	notprime[1] = true;
	for (int i = 2; i <= 1e6; i++) {
		if (!notprime[i]) 
			prime[cnt++] = i;
		for (int j = 0; j < cnt && i * prime[j] <= 1e6; j++) {
			notprime[i * prime[j]] = true;
			if (i % prime[j] == 0)
				break;
		}
	}
}
int main() {
	init();
	int a, b, ans = 0;
	scanf("%d%d", &a, &b);
	for (int i = a; i + 2 <= b; i++)
		ans += !(notprime[i] || notprime[i + 2]);
	printf("%d\n", ans);
	return 0;
}
