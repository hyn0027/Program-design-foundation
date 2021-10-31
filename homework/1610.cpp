#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXL = 1e7;
char s[MAXL + 5];
int cur;
double cnt() {
	while (s[cur] == ' ')
		cur++;
	if (s[cur] >= '0' && s[cur] <= '9') {
		double ret = 0, mul = 0.1;
		while (s[cur] >= '0' && s[cur] <= '9')
			ret = ret * 10 + s[cur++] - '0';
		if(s[cur] == '.')	cur++;
		while(s[cur] >= '0' && s[cur] <= '9') {
			ret += (double)(s[cur++] - '0') * mul;
			mul /= 10;
		}
		return ret;
	}
	cur++;
	if(s[cur - 1] == '+')
		return cnt() + cnt();
	if(s[cur - 1] == '-')
		return cnt() - cnt();
	if(s[cur - 1] == '*')
		return cnt() * cnt();
	if(s[cur - 1] == '/')
		return cnt() / cnt();
}
int main() {
	cin.getline(s, MAXL);
	printf("%.2lf\n", cnt());
	return 0;
}
