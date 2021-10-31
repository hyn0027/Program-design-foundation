#include <iostream>  
#include <cstring> 
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	int l, r, k;
	scanf("%d%d%d", &l, &r, &k);
	for(int i = 0; i < r - l; i++){
		printf("%c", l + i);
		if(i % k == k - 1)	printf("\n");
	}
	return 0;
}
