#include <iostream>  
#include <cstring> 
#include <algorithm>
#include <cstdio>
using namespace std;
/*
��1���ܱ�3����5������

��2��С��1000��

��3�������������֮ǰ��û�г��ֹ�-1��

��4����ǰѡ�е����ָ���С��10�������������ֻ��ѡ��10�����֣�
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
