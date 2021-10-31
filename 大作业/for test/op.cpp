#include <algorithm> 
#include <cstring>
#include <cstdio>
#include <iostream>
#include <ctime> 

using namespace std;

char s[20] = "fblrudFBLRUD";

int main() {
	//give out operations
	//output to op.in
	srand(time(0));
	int op = rand() % 1000 + 1;
	while(op--)
		printf("%c", s[rand() % 12]);
	return 0;
}
