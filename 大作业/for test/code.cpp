#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std; 

int cube[8][11];
char praform[8][200];

void init() {
	praform[1]['u'] = 'u';	
	praform[1]['U'] = 'U';
	praform[1]['f'] = 'f';
	praform[1]['F'] = 'F';
	praform[1]['d'] = 'd';
	praform[1]['D'] = 'D';
	praform[1]['r'] = 'r';
	praform[1]['R'] = 'R';
	praform[1]['l'] = 'l';
	praform[1]['L'] = 'L';
	praform[1]['b'] = 'b';
	praform[1]['B'] = 'B';
	
	praform[2]['u'] = 'u';	
	praform[2]['U'] = 'U';
	praform[2]['f'] = 'b';
	praform[2]['F'] = 'B';
	praform[2]['d'] = 'd';
	praform[2]['D'] = 'D';
	praform[2]['r'] = 'l';
	praform[2]['R'] = 'L';
	praform[2]['l'] = 'r';
	praform[2]['L'] = 'R';
	praform[2]['b'] = 'f';
	praform[2]['B'] = 'F';
	
	praform[3]['u'] = 'u';	
	praform[3]['U'] = 'U';
	praform[3]['f'] = 'l';
	praform[3]['F'] = 'L';
	praform[3]['d'] = 'd';
	praform[3]['D'] = 'D';
	praform[3]['r'] = 'f';
	praform[3]['R'] = 'F';
	praform[3]['l'] = 'b';
	praform[3]['L'] = 'B';
	praform[3]['b'] = 'r';
	praform[3]['B'] = 'R';
	
	praform[4]['u'] = 'u';	
	praform[4]['U'] = 'U';
	praform[4]['f'] = 'r';
	praform[4]['F'] = 'R';
	praform[4]['d'] = 'd';
	praform[4]['D'] = 'D';
	praform[4]['r'] = 'b';
	praform[4]['R'] = 'B';
	praform[4]['l'] = 'f';
	praform[4]['L'] = 'F';
	praform[4]['b'] = 'l';
	praform[4]['B'] = 'L';
	return; 
}

void input() {
	map<char, int> col;
	char a[8][11], b;
	for (int i = 1; i < 7; i++) {
		for (int j = 1; j < 10; j++)
			scanf("%c", &a[i][j]);
		scanf("%c", &b);
		col[a[i][5]] = i;
	} 
	for (int i = 1; i < 7; i++)
		for (int j = 1; j < 10; j++)
			cube[i][j] = col[a[i][j]];
	return; 
}

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
	if (c == 'R' || c == 'L' || c == 'B' || c == 'F' || c == 'U' || c == 'D'){
		num = 1;
		printf("%c ", c);
	}
	else if (c == 'r' || c == 'l' || c == 'b' || c == 'f' || c == 'u' || c == 'd') {
		num = 3;
		c = c + 'A' - 'a';
		printf("%ci ", c);
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

inline void exchange(int center, char *demand, int len) {
	for (int i = 0; i < len; i++)
		execute(praform[center][demand[i]]);
	return; 
}

inline bool find_step_1() {
	char s[20];
	for(int i = 0; i < 4; i++) {
		if (cube[5][2] == 6) {
			if (cube[2][2] == 1) {
				strcpy(s, "UUFF"); 
				exchange(1, s, 4);
			}
			else if (cube[2][2] == 2) {
				strcpy(s, "BB");
				exchange(1, s, 2);
			}
			else if (cube[2][2] == 3) {
				strcpy(s, "uLL");
				exchange(1, s, 3);
			}
			else {
				strcpy(s, "URR");
				exchange(1, s, 3);
			}
			return true;
		}
		strcpy(s, "U");
		exchange(1, s, 1);
	}
	for (int i = 1; i <= 4; i++){
		if (cube[i][2] == 6) {
			strcpy(s, "FRurf");
			exchange(i, s, 5); 
			return true;
		}
		if (cube[i][4] == 6) {
			strcpy(s, "lUL");
			exchange(i, s, 3);
			return true;
		}
		if (cube[i][6] == 6) {
			strcpy(s, "Rur");
			exchange(i, s, 3);
			return true;
		}
		if (cube[i][8] == 6) {
			strcpy(s, "FF");
			exchange(i, s, 2);
			return true;
		} 
	}
	if (cube[6][2] == 6 && cube[1][8] != 1) {
		strcpy(s, "FF");
		exchange(1, s, 2);
		return true;
	} 
	if (cube[6][4] == 6 && cube[3][8] != 3) {
		strcpy(s, "FF");
		exchange(3, s, 2);
		return true;
	}
	if (cube[6][6] == 6 && cube[4][8] != 4) {
		strcpy(s, "FF");
		exchange(4, s, 2);
		return true;
	}
	if (cube[6][8] == 6 && cube[2][8] != 2) {
		strcpy(s, "FF");
		exchange(2, s, 2);
		return true;
	}
	return false; 
} 

void step1() {
	while (find_step_1()) {}
	return;
}

inline bool find_step_2() {
	char s[20];
	for (int i = 0; i < 4; i++) {
		if (cube[1][1] == 6) {
			if (cube[5][7] == 1) {
				strcpy(s, "FUf");
				exchange(1, s, 3);
			}
			else if (cube[5][7] == 2) {
				strcpy(s, "uuFUf");
				exchange(2, s, 5); 
			} 
			else if (cube[5][7] == 3) {
				strcpy(s, "UFUf");
				exchange(3, s, 4);
			}
			else {
				strcpy(s, "uFUf");
				exchange(4, s, 4);
			}
			return true;
		}
		if (cube[1][3] == 6) {
			if (cube[5][9] == 1) {
				strcpy(s, "fuF");
				exchange(1, s, 3);
			}
			else if (cube[5][9] == 2) {
				strcpy(s, "uufuF");
				exchange(2, s, 5);
			}
			else if (cube[5][9] == 3) {
				strcpy(s, "UfuF");
				exchange(3, s, 4);
			}
			else {
				strcpy(s, "ufuF");
				exchange(4, s, 4);
			}
			return true;
		}
		strcpy(s, "U");
		exchange(1, s, 1);
	}
	for (int i = 1; i <= 4; i++) {
		if (cube[i][7] == 6) {
			strcpy(s, "FUf");
			exchange(i, s, 3);
			return true;
		}
		if (cube[i][9] == 6) {
			strcpy(s, "fuF");
			exchange(i, s, 3);
			return true;
		}
	}
	if (cube[6][1] == 6 && cube[1][7] != 1) {
		strcpy(s, "FUf");
		exchange(1, s, 3);
		return true;
	}
	if (cube[6][3] == 6 && cube[4][7] != 4) {
		strcpy(s, "FUf");
		exchange(4, s, 3);
		return true;
	}
	if (cube[6][7] == 6 && cube[3][7] != 3) {
		strcpy(s, "FUf");
		exchange(3, s, 3);
		return true;
	}
	if (cube[6][9] == 6 && cube[2][7] != 2) {
		strcpy(s, "FUf");
		exchange(2, s, 3);
		return true;
	}
	for (int i = 0; i < 4; i++) {
		if (cube[5][7] == 6) {
			if (cube[6][1] != 6) {
				strcpy(s, "luuL");
				exchange(1, s, 4);
			}
			else if (cube[6][3] != 6) {
				strcpy(s, "Ruur");
				exchange(1, s, 4);
			}
			else if (cube[6][7] != 6) {
				strcpy(s, "UluuL");
				exchange(3, s, 5);
			}
			else {
				strcpy(s, "uuluuL");
				exchange(2, s, 6);
			}
			return true;
		}
		strcpy(s, "U");
		exchange(1, s, 1);
	}
	return false;
} 

void step2() {
	while (find_step_2()) {}
	return;
} 

inline bool find_step_3() {
	int left_col[6] = {0, 3, 4, 2, 1};
	int right_col[6] = {0, 4, 3, 1, 2};
	int up_id[6] = {0, 8, 2, 4, 6}; 
	char s[20];
	for (int t = 0; t < 4; t++) {
		for (int i = 1; i < 5; i++) {
			if (cube[i][2] == i && cube[5][up_id[i]] == left_col[i]) {
				strcpy(s, "ufUFURur");
				exchange(left_col[i], s, 8);
				return true;
			}
			if (cube[i][2] == i && cube[5][up_id[i]] == right_col[i]) {
				strcpy(s, "URurufUF");
				exchange(i, s, 8);
				return true;
			}
		}
		strcpy(s, "U");
		exchange(1, s, 1);
	}
	for (int i = 1; i < 5; i++) {
		if (cube[i][6] != i) {
			strcpy(s, "URurufUF");
			exchange(i, s, 8);
			return true;
		}
	}
	return false;
}

void step3() {
	while (find_step_3()) {} 
	return;
}

void step4() {
	int cnt;
	char s[20];
	while ((cnt = (cube[5][2] == 5) + (cube[5][4] == 5) + (cube[5][6] == 5) + (cube[5][8] == 5)) < 4) {
		if (cnt == 0) {
			strcpy(s, "FRUruf");
			exchange(1, s, 6);
		}
		else {
			while (cube[5][4] != 5) {
				strcpy(s, "U");
				exchange(1, s, 1);
			}
			if (cube[5][2] != 5 && cube[5][6] != 5) {
				strcpy(s, "U");
				exchange(1, s, 1);
			}
			strcpy(s, "FRUruf");
			exchange(1, s, 6);
		}
	}
	return;
}

void step5() {
	int cnt;
	char s[20];
	while ((cnt = (cube[5][1] == 5) + (cube[5][3] == 5) + (cube[5][7] == 5) + (cube[5][9] == 5)) < 4) {
		if (cnt == 0) {
			while (cube[3][3] != 5) {
				strcpy(s, "U");
				exchange(1, s, 1);
			}
		}
		else if (cnt == 1) {
			while (cube[5][7] != 5) {
				strcpy(s, "U");
				exchange(1, s, 1);
			}
		}
		else {
			while (cube[1][1] != 5) {
				strcpy(s, "U");
				exchange(1, s, 1);
			}
		}
		strcpy(s, "RUrURUUr");
		exchange(1, s, 8);
	}
	return;
}

inline bool find_step_6() {
	int cnt = 0, mark = 1;
	for (int i = 1; i < 5; i++) {
		if (cube[i][1] == cube[i][3]) {
			cnt++;
			mark = i;
		}
	}
	if (cnt == 4)
		return false;
	char s[20];
	strcpy(s, "RbRFFrBRFFRR");
	exchange(mark, s, 12);
	return true;
}

void step6() {
	while (find_step_6()) {}
	return;
}

inline bool find_step_7() {
	int mark = 1, cnt = 0, back_id[6] = {0, 2, 1, 4, 3};
	for (int i = 1; i < 5; i++) {
		if (cube[i][1] == cube[i][2]) {
			cnt++;
			mark = i; 
		}
	}
	if (cnt == 4)
		return false;
	char s[20];
	strcpy(s, "RuRURURuruRR");
	exchange(back_id[mark], s, 12);
	return true;
}

void step7() {
	while (find_step_7()) {}
	char s[10];
	while (cube[1][1] != 1) {
		strcpy(s, "U");
		exchange(1, s, 1);
	} 
	return; 
}

void work() {
	step1();
	step2();
	step3();
	step4();
	step5();
	step6();
	step7();
	printf("\n");
	return;
}

int main() {
	init();
	input();
	work();
	return 0; 
} 
