#include <iostream>  
#include <cstring> 
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	for(int i = 0, sum; i < 4; i++){
		sum = (i != 0) + (i == 1) + ( i != 1) + (i == 2);
		if(sum == 3)
			printf("%c\n", 'A' + i);
	} 
	return 0;
}
