#include <iostream>
#include <cstring>
#include <cstdio> 
#include <algorithm>
#include <queue> 

using namespace std;

const int t = 1000; 

int main(){
	for (int i = 1; i <= t; i++) {
		printf("case%d:\n", i);
		system("op > op.in");
		system("data < op.in > data.in");
		system("code < data.in > cube.out");
		system("rotate < cube.out > end.out");
		system("see < end.out > ed.out"); 
		if(system("fc ed.out std.out"))
			break;
	}
	return 0;
}
