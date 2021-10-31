#include <algorithm> 
#include <cstring>
#include <cstdio>
#include <iostream>
#include <fstream> 

using namespace std;

char cube[7][11], s[7][3][3];

inline void work(char &a, char &b, char &c, char &d) {
	swap(a, b);
	swap(a, c);
	swap(a, d);
	return;
}

inline void rot(int f) {
	work(s[f][1][2], s[f][2][3], s[f][3][2], s[f][2][1]);
	work(s[f][1][1], s[f][1][3], s[f][3][3], s[f][3][1]);
	return;
}

inline void rotate(char c) {
	if (c == 'R') {
		rot(4);
		work(s[1][2][3], s[5][2][3], s[2][2][1], s[6][2][3]);
		work(s[1][1][3], s[5][1][3], s[2][3][1], s[6][1][3]);
		work(s[1][3][3], s[5][3][3], s[2][1][1], s[6][3][3]);
	}
	else if (c == 'L') {
		rot(3);
		for(int i = 0; i < 3; i++) {
			work(s[1][2][1], s[5][2][1], s[2][2][3], s[6][2][1]);
			work(s[1][1][1], s[5][1][1], s[2][3][3], s[6][1][1]);
			work(s[1][3][1], s[5][3][1], s[2][1][3], s[6][3][1]);
		}
	}
	else if (c == 'U') {
		rot(5);
		for(int i = 1; i < 4; i++)
			work(s[1][1][i], s[3][1][i], s[2][1][i], s[4][1][i]);
	}
	else if (c == 'D') {
		rot(6);
		for(int i = 1; i < 4; i++)
			work(s[1][3][i], s[4][3][i], s[2][3][i], s[3][3][i]);
	}
	else if (c == 'F') {
		rot(1);
		work(s[5][3][2], s[4][2][1], s[6][1][2], s[3][2][3]);
		work(s[5][3][1], s[4][1][1], s[6][1][3], s[3][3][3]);
		work(s[5][3][3], s[4][3][1], s[6][1][1], s[3][1][3]);
	}
	else if (c == 'B') {
		rot(2);
		for (int i = 0; i < 3; i++) {
			work(s[5][1][2], s[4][2][3], s[6][3][2], s[3][2][1]);
			work(s[5][1][1], s[4][1][3], s[6][3][3], s[3][3][1]);
			work(s[5][1][3], s[4][3][3], s[6][3][1], s[3][1][1]);
		}
	}
}

int main() {
	//rotate using the options
	ifstream in("data.in");
	for (int i = 1; i < 7; i++)
		in >> cube[i];
	in.close();
	for (int i = 1; i < 7; i++) {
		for(int j = 1; j < 4; j++)
			s[i][1][j] = cube[i][j - 1];
		for(int j = 4; j < 7; j++)
			s[i][2][j - 3] = cube[i][j - 1];
		for(int j = 7; j < 10; j++)
			s[i][3][j - 6] = cube[i][j - 1];
	}
	char o[5];
	int l;
	while (scanf("%s", o) != EOF) {
		l = strlen(o);
		if (l == 2)
			l++;
		for (int i = 0; i < l; i++)
			rotate(o[0]);
	}
	for (int i = 1; i < 7; i++) {
		for(int j = 1; j < 4; j++)
			for(int k = 1; k < 4; k++)
				printf("%c", s[i][j][k]);
		printf("\n");
	}
	return 0;
}
