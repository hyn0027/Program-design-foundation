#include <iostream>  
#include <cstring> 
#include <algorithm>
#include <cstdio>
#include <fstream>
#include <iomanip>
using namespace std;
const int INF = 200;
struct Score {
	double mmax, mmin, sum;
}a[7]; 
void init() {
	for(int i = 0; i < 5; i++)
		a[i].mmin = INF;
}
inline void upd(Score &s, double x){
	s.mmax = max(s.mmax, x);
	s.mmin = min(s.mmin, x);
	s.sum += x;
}
int main(){
	ifstream in;
	ofstream out;
	in.open("input.txt");
	int T;
	char s[100];
	double w, x, y, z;
	init();
	in >> T;
	for (int i = 0; i < T; i++) {
		in >> s >> w >> x >> y >> z;
		upd(a[0], w);
		upd(a[1], x);
		upd(a[2], y);
		upd(a[3], z);
		upd(a[4], w + x + y + z);
	}
	in.close();
	out.open("output.txt");
	for(int i = 0; i < 5; i++)
		out << fixed << setprecision(3) << a[i].mmax << " " << a[i].mmin << " " << a[i].sum / T << endl;
	out.close();
	return 0;
}
