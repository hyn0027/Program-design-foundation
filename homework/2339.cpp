#include <iostream>  
#include <cstring> 
#include <algorithm>
#include <cstdio>
using namespace std;
int ans(int n) {//put off n 
	if(n < 3)
		return n;
	return ans(n - 2) * 2 + 1 + ans(n - 1);
}
int main() {
	int n;
	scanf("%d", &n);
	printf("%d\n", ans(n));
	return 0;
}
