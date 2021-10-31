#include <iostream>  
#include <cstring> 
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	for(int i = 1, sum; i < 5; i++){
		sum = (i != 1) + (i == 4) + (i == 2) + (i != 4);
		if(sum == 1){
			printf("%c\n", 'A' + i - 1);
			break;
		}
	} 
	return 0;
}
