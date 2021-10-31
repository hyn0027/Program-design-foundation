#include <iostream>  
#include <cstring> 
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
const double pi = 3.14159265;
int main(){
	double ans = sin(pi / 4) * sin(pi / 4)
			   + sin(pi / 4) * cos(pi / 4)
			   - cos(pi / 4) * cos(pi / 4);
	printf("%.5lf\n", ans);
	return 0;
}
