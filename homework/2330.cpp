#include <iostream>  
#include <cstring> 
#include <algorithm>
#include <cstdio>
#include <fstream>
#include <iomanip>
using namespace std;
int cnt[12];
int main() {
	ifstream in;
	ofstream out;
	char s[100];
	int score;
	in.open("input.txt");
	while (in >> s) {
		in >> score;
		cnt[score / 10]++;
	}
	in.close();
	cnt[9] += cnt[10];
	out.open("output.txt");
	for (int i = 0; i < 10; i++) {
		cnt[i] = min(cnt[i], 10);
		for(int j = 0; j < cnt[i]; j++)
			out << "@";
		for(int j = cnt[i]; j < 10; j++) 
			out << ".";
		out << endl; 
	}
	out.close();
	return 0;
}
