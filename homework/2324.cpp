#include <iostream>  
#include <cstring> 
#include <algorithm>
#include <cstdio>
using namespace std;
bool alive[15];
int res = 10;
inline void nex(int &cur){
	cur = cur % 10 + 1;
}
inline void advance(int &cur){
	nex(cur);
	while(!alive[cur])	nex(cur);
}
int main(){
	memset(alive, 1, sizeof(alive));
	int cur = 10;
	while(res > 1){
		for(int i = 0; i < 6; i++)	advance(cur);
		alive[cur] = 0;
		res--;
	}
	for(int i = 1; i <= 10; i++)
		if(alive[i])	printf("%d\n", i);
	return 0;
}
