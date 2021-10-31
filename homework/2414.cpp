#include <iostream>  
#include <cstring> 
#include <algorithm>
#include <cstdio>
#include <fstream>
using namespace std;
char cube[8][4][4], cube1[8][4][4];
inline void work() {
	for (int i = 1; i < 4; i++)
		for (int j = 1; j < 4; j++)
			cube1[4][i][j] = cube[4][4 - j][i];
	for (int i = 1; i < 4; i++) {
		cube1[1][i][3] = cube[6][i][3];
		cube1[5][i][3] = cube[1][i][3];
		cube1[2][4 - i][1] = cube[5][i][3];
		cube1[6][i][3] = cube[2][4 - i][1];
	}
	for (int i = 1; i < 7; i++)
		for (int j = 1; j < 4; j++) 
			for (int k = 1; k < 4; k++)
				cube[i][j][k] = cube1[i][j][k];
	return;
}
int main() {
	ifstream in;
	ofstream out;
	in.open("input.txt");
	char operation[3000];
	int rep;
	for (int i = 1; i < 7; i++)
		for (int j = 1; j < 4; j++) 
			for (int k = 1; k < 4; k++)
				in >> cube[i][j][k];
	in.getline(operation, 2005);
	in.getline(operation, 2005);
	in.close();
	for (int i = 1; i < 7; i++)
		for (int j = 1; j < 4; j++) 
			for (int k = 1; k < 4; k++)
				cube1[i][j][k] = cube[i][j][k];
	rep = ((strlen(operation) + 1)/ 2) % 4;
	while(rep--)
		work();
	out.open("output.txt");
	for (int i = 1; i < 7; i++) {
		for (int j = 1; j < 4; j++) 
			for (int k = 1; k < 4; k++)
				out << cube[i][j][k];
		out << endl;
	}
	out.close();
	return 0;
}
