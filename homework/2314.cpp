#include <iostream>  
#include <cstring> 
#include <algorithm>
#include <cstdio>
using namespace std;
/*
（1）能被3或者5整除；

（2）小于1000；

（3）在这个数出现之前，没有出现过-1。

（4）当前选中的数字个数小于10个。（即，最多只能选中10个数字）
*/
bool flag = false;
int cnt;
bool check(int a){
	if((a % 3 != 0) && (a % 5 != 0))
		return false;
	if(a >= 1000)
		return false;
	if(flag == true)
		return false;
	return true;
}
void upd(int a){
	if(a == -1)
		flag = true;
	return;
}
int main(){
	int n, sum = 0;
	scanf("%d", &n);
	for(int i = 0, a; i < n; i++){
		scanf("%d", &a);
		if(check(a))
			sum += a, cnt++;
		if(cnt == 10)
			break;
		upd(a);
	}
	printf("%d\n", sum);
	return 0;
}
