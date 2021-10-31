#include <iostream>  
#include <cstring> 
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	bool a, b, c, d, e, f;
	for(int i = 1, sum; i < 7; i++){
		a = (i != 1);
		b = ((i == 1) || (i == 3));
		f = (i == 6);
		c = ((a == 0) && (b == 0));
		d = ((c == 0) && (f == 0));
		e = ((a == 1) && (d == 1) && (b == 0) && (c == 0) && (f == 0));
		sum = a + b + c + d + e + f;
		if(sum == 3)	printf("%c\n", 'A' + i - 1);
	}
	return 0;
}
