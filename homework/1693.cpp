#include <iostream>  
#include <cstring> 
#include <algorithm>
#include <cstdio>
using namespace std;
const int MAXN = 1e5 + 5;
int s[MAXN], t[MAXN];
void m_sort(int l, int r) {
	if (l == r)	return;
	int mid = (l + r) / 2;
	m_sort(l, mid);
	m_sort(mid + 1, r);
	int p1 = l, p2 = mid + 1, p3 = l;
	while (p1 <= mid && p2 <= r) {
		if (s[p1] < s[p2])
			t[p3++] = s[p1++];
		else
			t[p3++] = s[p2++]; 
	}
	while (p1 <= mid) 
		t[p3++] = s[p1++];
	while (p2 <= r)
		t[p3++] = s[p2++];
	for (int i = l; i <= r; i++)
		printf("%d ", s[i] = t[i]);
	printf("\n");
	return;
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &s[i]);
	m_sort(0, n - 1); 
	return 0;
}
