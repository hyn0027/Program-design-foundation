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
	char s[MAXL], t[MAXL];
	int ls, lt, ans = -1;
	in.getline(s, 1001);
	in.getline(t, 1001);
	in.close();
	ls = strlen(s);
	lt = strlen(t);
	for (int i = 0; i + lt - 1 < ls; i++) {
		bool flag = true;
		for (int j = 0; j < lt; j++)
			if (s[i + j] != t[j]) {
				flag = false;
				break;
			}
		if (flag) {
			ans = i;
			break;
		}
	}
	out.open("output.txt");
	out << ans << endl;
	out.close();
	return 0;
}
