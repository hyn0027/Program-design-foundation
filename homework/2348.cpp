#include <iostream>  
#include <cstring> 
#include <algorithm>
#include <cstdio>
using namespace std;
bool s[2][2][2][2];//wolf sheep vegetable direction 0 go left 1 go right
int step[100], cnt; //1none 2wolf 3sheep 4vegetable
bool found;
char o[5] = { 0, 0, 'W', 'S', 'V'};
inline void output() {
	for (int i = 0; i < cnt; i++) {
		if (step[i] == 1)
			printf("H ");
		else
			printf("H%c ", o[step[i]]);
	}
	printf("\n");
}
void search(int wolf, int sheep, int vegetable, int direction) {
	if (wolf == 1 && sheep == 1 && vegetable == 1 && direction == 1) {
		output();
		found = true;
		return;
	}
	if (s[wolf][sheep][vegetable][direction])
		return;
	s[wolf][sheep][vegetable][direction] = true;
	if(wolf != sheep && sheep != vegetable) {
		step[cnt++] = 1;
		search(wolf, sheep, vegetable, (direction + 1) % 2);
		if (found)
			return;
		cnt--;
	}
	if ((direction == 0 && wolf == 0 && !(sheep == 0 && vegetable == 0)) || (direction == 1 && wolf == 1 && !(sheep == 1 && vegetable == 1))) {
		step[cnt++] = 2;
		search((wolf + 1) % 2, sheep, vegetable, (direction + 1) % 2);
		if (found)
			return;
		cnt--;
	}
	if ((direction == 0 && sheep == 0) || (direction == 1 && sheep == 1)) {
		step[cnt++] = 3;
		search(wolf, (sheep + 1) % 2, vegetable, (direction + 1) % 2);
		if (found)
			return;
		cnt--;
	}
	if ((direction == 0 && vegetable == 0 && !(wolf == 0 && sheep == 0)) || (direction == 1 && vegetable == 1 && !(wolf == 1 && sheep == 1))) {
		step[cnt++] = 4;
		search(wolf, sheep, (vegetable + 1) % 2, (direction + 1) % 2);
		if (found)
			return;
		cnt--;
	}
	return; 
}
int main() {
	search(0, 0, 0, 0);
	return 0;
}
