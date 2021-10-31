#include <iostream>  
#include <cstring> 
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	int sum = 0, cnt = 0;
	for(int i = 0, a; i < 6; i++){
		scanf("%d", &a);
		if(a % 3 == 0 && (a & 1))
			sum += a, cnt++;
	}
	if(cnt == 0)	cnt++;
	printf("%.4lf\n", (double)sum / cnt);
	return 0;
}
