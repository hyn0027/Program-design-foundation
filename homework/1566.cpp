#include <iostream>
#include <cmath>
using namespace std;
void printPrime(int num);    // 未定义，需要完成

int main() {
    int n, i;
    cin >> n;
    while (n --) {
        cin >> i;
        printPrime(i);
    }
    return 0;
}
void printPrime(int num){
	cout << num << "=";
	//printf("%d=", num);
	bool flag = 0;
	for(int i = 2; i * i <= num; i++){
		if(num % i == 0){
			if(flag)	cout << "*" << i;//printf("*%d", i);
			else{
				cout << i;
				flag = true;
			}
			num /= i;x
			i--;
		}
	}
	if(num != 1){
		if(flag)	cout << "*" << num;
		else		cout << num;
		
	}
	cout << endl;
}
