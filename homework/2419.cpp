#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <iomanip>
using namespace std;
const float INF = 100;
inline float calculate(float w, float h) {
	return w / h / h;
}
int main() {
	ifstream in("input", ios::binary);
	int n;
	char name[8], gender, age;
	float weight, height, B;
	int cnt[2] = {}, BMI[2][4] = {};
	float aver_age[2] = {}, aver_height[2] = {}, male_max = -INF, female_min = INF;
	char male_BMI_max[8], female_BMI_min[8];
	in.read(reinterpret_cast<char*>(&n), sizeof(n));
	for (int i = 0, g; i < n; i++) {
		in.read(reinterpret_cast<char*>(&name), sizeof(name));
		in.read(reinterpret_cast<char*>(&gender), sizeof(gender));
		in.read(reinterpret_cast<char*>(&age), sizeof(age));
		in.read(reinterpret_cast<char*>(&weight), sizeof(weight));
		in.read(reinterpret_cast<char*>(&height), sizeof(height));
		if(gender == 'm')	g = 0;
		else	g = 1;
		cnt[g]++;
		aver_age[g] += age;
		aver_height[g] += height;
		B = calculate(weight, height);
		if (B < 18.5)	BMI[g][0]++;
		else if (B < 24)	BMI[g][1]++;
		else if (B < 28)	BMI[g][2]++;
		else	BMI[g][3]++;
		if (g == 0 && B > male_max) {
			male_max = B;
			strcpy(male_BMI_max, name);
		}
		if (g == 1 && B < female_min) {
			female_min = B;
			strcpy(female_BMI_min, name);
		}
	}
	in.close();
	for (int i = 0; i < 2; i++) {
		aver_age[i] /= cnt[i];
		aver_height[i] /= cnt[i];
	}
	ofstream out("output.txt");
	out << cnt[0] << " " << cnt[1] << endl;
	out << fixed << setprecision(3) << aver_age[0] << " " << aver_age[1] << endl;
	out << aver_height[0] << " " << aver_height[1] << endl;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++)
			out << BMI[i][j] << " ";
		out << endl;
	}
	out << male_BMI_max << endl;
	out << female_BMI_min << endl; 
	return 0;
}
