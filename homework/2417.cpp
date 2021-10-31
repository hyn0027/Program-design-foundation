#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
const int MAXN = 1e3 + 5;
const double INF = 1e5;
int main() {
	ifstream in("input", ios::binary);
	int m;
	double average[MAXN], a, sum = 0, mmax = -INF, mmin = INF;
	in.read(reinterpret_cast<char*>(&m), sizeof(m));
	for(int i = 0, n; i < m; i++) {
		in.read(reinterpret_cast<char*>(&n), sizeof(n));
		average[i] = 0;
		for(int j = 0; j < n; j++){
			in.read(reinterpret_cast<char*>(&a), sizeof(double));
			average[i] += a;
		}
		average[i] /= n;
		sum += average[i];
		mmax = max(mmax, average[i]);
		mmin = min(mmin, average[i]);
	}
	in.close();
	sum /= m;
	ofstream out("output.txt");
	out << fixed << setprecision(3) << mmin << endl << mmax << endl << sum << endl;
	return 0;
}
