#include <iostream>  
#include <cstring> 
#include <algorithm>
#include <cstdio>
#include <fstream>
using namespace std;
const int MAXL = 1e3 + 5;
int main() {
	ifstream in;
	ofstream out;
	in.open("input.txt");
	char s[MAXL], t[MAXL], c[MAXL];
	int ls, lt;
	in.getline(s, 1001);
	in.getline(t, 1001);
	in.getline(c, 1001);
	in.close();
	ls = strlen(s);
	lt = strlen(t);
	out.open("output.txt");
	bool found = false;
	for (int i = 0; i + lt - 1 < ls; i++) {
		bool flag = true;
		for (int j = 0; j < lt; j++)
			if (s[i + j] != t[j]) {
				flag = false;
				break;
			}
		if (flag) {
			found = true;
			for (int j = 0; j < i; j++)
				out << s[j];
			out << c;
			for (int j = i + lt; j < ls; j++)
				out << s[j];
			break;
		}
	}
	if(!found)	out << s;
	out << endl;
	out.close();
	return 0;
}
