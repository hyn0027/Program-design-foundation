#include <algorithm> 
#include <cstring>
#include <cstdio>
#include <iostream>
#include <ctime> 

using namespace std;

const int MAXN = 1e3 + 5;

int cube[8][11];

inline void rotate(int e) {
	int temp0[4][4], temp1[4][4];
	for (int i = 1; i < 10; i++)
		temp0[(i - 1) / 3][(i - 1) % 3] = cube[e][i];
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			temp1[i][j] = temp0[2 - j][i];
	for (int i = 1; i < 10; i++)
		cube[e][i] = temp1[(i - 1) / 3][(i - 1) % 3];
	return; 
}

inline void execute(char c) {
	int temp[8][11];
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 10; j++)
			temp[i][j] = cube[i][j];
	int num;
	if (c == 'R' || c == 'L' || c == 'B' || c == 'F' || c == 'U' || c == 'D')
		num = 1;
	else if (c == 'r' || c == 'l' || c == 'b' || c == 'f' || c == 'u' || c == 'd') {
		num = 3;
		c = c + 'A' - 'a';
	}
	for (int k = 0; k < num; k++){
		if (c == 'R') {
			for (int i = 3; i < 10; i = i + 3) {
				temp[1][i] = cube[6][i];
				temp[5][i] = cube[1][i];
				temp[2][i - 2] = cube[5][12 - i];
				temp[6][i] = cube[2][10 - i];
			}
			rotate(4);
			for (int i = 0; i < 7; i++)
				if (i != 4)
					for (int j = 0; j < 10; j++)
							cube[i][j] = temp[i][j];
		}
		else if (c == 'L') {
			for (int i = 1; i <= 7; i = i + 3) {
				temp[1][i] = cube[5][i];
				temp[6][i] = cube[1][i];
				temp[5][i] = cube[2][10 - i];
				temp[2][i + 2] = cube[6][8 - i];
			} 
			rotate(3);
			for (int i = 0; i < 7; i++)
				if (i != 3)
					for (int j = 0; j < 10; j++)
						cube[i][j] = temp[i][j];
		}
		else if (c == 'B') {
			for (int i = 3; i <= 9; i = i + 3) {
				temp[4][i] = cube[6][10 - i / 3];
				temp[6][i / 3 + 6] = cube[3][i - 2];
				temp[3][i - 2] = cube[5][4 - i / 3];
				temp[5][i / 3] = cube[4][i];
			}
			rotate(2);
			for (int i = 0; i < 7; i++)
				if (i != 2)
					for (int j = 0; j < 10; j++)
						cube[i][j] = temp[i][j];
		}
		else if (c == 'F') {
			for (int i = 1; i <= 3; i++) {
				temp[6][i] = cube[4][10 - 3 * i];
				temp[3][i * 3] = cube[6][i];
				temp[5][6 + i] = cube[3][12 - 3 * i];
				temp[4][3 * i - 2] = cube[5][6 + i];
			}
			rotate(1);
			for (int i = 0; i < 7; i++)
				if (i != 1)
					for (int j = 0; j < 10; j++)
						cube[i][j] = temp[i][j];
		}
		else if (c == 'U') {
			for (int i = 1; i <= 3; i++) {
				temp[1][i] = cube[4][i];
				temp[4][i] = cube[2][i];
				temp[2][i] = cube[3][i];
				temp[3][i] = cube[1][i];
			}
			rotate(5);
			for (int i = 0; i < 7; i++)
				if (i != 5)
					for (int j = 0; j < 10; j++)
						cube[i][j] = temp[i][j];
		}
		else if (c == 'D') {
			for (int i = 7; i <= 9; i++) {
				temp[1][i] = cube[3][i];
				temp[4][i] = cube[1][i];
				temp[2][i] = cube[4][i];
				temp[3][i] = cube[2][i];
			}
			rotate(6);
			for (int i = 0; i < 7; i++)
				if (i != 6)
					for (int j = 0; j < 10; j++)
						cube[i][j] = temp[i][j];
		}
	}
	return;
}

int main() {
	//using op.in to rotate a random cube
	//output to data.in
	srand(time(0));
	for (int i = 1; i < 7; i++)
		for (int j = 1; j < 10; j++)
			cube[i][j] = i;
	char op[MAXN];
	scanf("%s", op);
	int l = strlen(op);
	for (int i = 0; i < l; i++)
		execute(op[i]);
	char col[7] = "BGORYW";
	for (int i = 1; i < 7; i++) {
		for (int j = 1; j < 10; j++)
			printf("%c", col[cube[i][j] - 1]);
		printf("\n");
	}
	return 0;
}
