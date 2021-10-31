#include <iostream>
using namespace std;
bool checkSpecial(int i, int n);

int main() {
    int n;
    cin >> n;
    for (int i = 10000; i < 1000000; i ++) {
        if (checkSpecial(i, n)) {
            cout << i << endl;
        }
    }
    return 0;
}

inline bool sum(int i, int n){
	while(i){
		n -= i % 10;
		i /= 10;
	}
	return (n == 0);
}
inline bool reverse(int x){
	int s[10], cnt = 0;
	while(x){
		s[cnt++] = x % 10;
		x /= 10;
	}
	for(int i = 0; i < cnt; i++)
		if(s[i] != s[cnt - i - 1])	return false;
	return true;
}
bool checkSpecial(int i, int n){
	return sum(i, n) && reverse(i);
}
