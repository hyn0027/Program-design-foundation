#include <iostream>  
#include <cstring> 
#include <algorithm>
#include <cstdio>
#include <fstream>
using namespace std;
const int MAXN = 1e4 + 10;
int a[MAXN], b[MAXN], c[MAXN * 2], na, nb;
int main() {
	ifstream in;
	ofstream out;
	in.open("input-1.txt");
	in >> na;
	for (int i = 0 ; i < na; i++)
		in >> a[i];
	in.close();
	
	in.open("input-2.txt");
	in >> nb;
	for (int i = 0 ; i < nb; i++)
		in >> b[i];
	in.close();
	
	out.open("output.txt");
	out << na + nb << endl;
	int p1, p2;
	p1 = p2 = 0;
	while (p1 < na && p2 < nb) {
		if (a[p1] < b[p2]) {
			out << a[p1] << endl;
			p1++;
		}
		else {
			out << b[p2] << endl;
			p2++;
		}
	}
	while (p1 < na) {
		out << a[p1] << endl;
		p1++;
	}
	while (p2 < nb) {
		out << b[p2] << endl;
		p2++;
	}
	out.close();
	return 0;
}
