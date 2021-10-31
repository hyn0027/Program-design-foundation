#include <iostream>  
#include <cstring> 
#include <algorithm>
#include <cstdio>
using namespace std;
int f(int x) {
	if (x == 1)
		return 1;
	if (x % 2 == 1)
		return f((x - 1) / 2) + f((x + 1) / 2);
	return f(x / 2);
}
int main() {
	int T, x;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &x);
		printf("%d\n", f(x));
	} 
	return 0;
}
