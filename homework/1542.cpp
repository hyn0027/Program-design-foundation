#include <iostream>  
#include <cstring> 
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	double ans = 1.0 + 1.0 / (1.0 + 1.0 / (1.0 + 1.0 / 5.0));
	printf("%.4lf\n", ans);
	return 0;
}
