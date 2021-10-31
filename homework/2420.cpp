#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <fstream>
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned char uint8_t;
typedef int int32_t;
using namespace std;
const int MAXN = 400;
struct BitMapFileHeader {
    uint16_t bfType;      // 2�ֽڣ��ļ����ͣ�magic number����һ��Ϊ0x4D42��
    uint32_t bfSize;      // 4�ֽڣ�BMP�ļ��Ĵ�С����λΪ�ֽڣ���
    uint16_t bfReserved1; // 2�ֽڣ�������һ������Ϊ0��
    uint16_t bfReserved2; // 2�ֽڣ�������һ������Ϊ0��
    uint32_t bfOffBits;   // 4�ֽڣ�λͼ���ݣ��������飩�ĵ�ַƫ�ƣ�Ҳ������ʼ��ַ��
}filehead;
struct BitMapInfoHeader {
    uint32_t biSize;          // 4�ֽڣ���Ϣͷ�Ĵ�С����40��
    int32_t biWidth;          // 4�ֽڣ����з���������������Ϊ��λ˵��ͼ��Ŀ�ȣ�
    int32_t biHeight;         // 4�ֽڣ����з���������������Ϊ��λ˵��ͼ��ĸ߶�;
    uint16_t biPlanes;        // 2�ֽڣ�ΪĿ���豸˵����ɫƽ�������ܱ�����Ϊ1��
    uint16_t biBitCount;      // 2�ֽڣ�˵��������/��������ֵ��1��2��4��8��16��24��32��
    uint32_t biCompression;   // 4�ֽڣ�˵��ͼ���ѹ�����ͣ���õľ���0��BI_RGB������ʾ��ѹ����
    uint32_t biSizeImages;    // 4�ֽڣ�˵��λͼ���ݵĴ�С������BI_RGB��ʽʱ����������Ϊ0��
    int32_t biXPelsPerMeter;  // 4�ֽڣ����з�����������ʾˮƽ�ֱ��ʣ���λ������/�ף�
    int32_t biYPelsPerMeter;  // 4�ֽڣ����з�����������ʾ��ֱ�ֱ��ʣ���λ������/�ף�
    uint32_t biClrUsed;       // 4�ֽڣ�˵��λͼʹ�õĵ�ɫ���е���ɫ��������Ϊ0˵��ʹ�����У�
    uint32_t biClrImportant;  // 4�ֽڣ�˵����ͼ����ʾ����ҪӰ�����ɫ��������Ϊ0˵������Ҫ��
}datahead;
struct Pixel {
    uint8_t blue;
    uint8_t red;
    uint8_t green;
}data[MAXN + 5][MAXN + 5];
inline int square(int x) {
	return x * x;
}
inline int dis(int x1, int y1, int x2, int y2) {
	return square(x1 - x2) + square(y1 - y2); 
}
inline void col(int x, int y) {
	data[x][y] = {255, 255, 255};
}
int main() {
	filehead = {0x4D42, 400 * 400 * 3 + 54, 0, 0, 54};
	datahead = {40, 400, 400, 1, 24, 0, 400 * 400 * 3, 1000, 1000, 0, 0}; 
	ifstream in("input.txt");
	int x, y, r;
	in >> x >> y >> r;
	for (int i = 0; i < MAXN; i++)
		for (int j = 0; j < MAXN; j++)
			if(dis(i, j, x, y) < r * r)
				col(i, j);
	in.close();
	ofstream out("output.bmp", ios::binary);
	out.write(reinterpret_cast<char*>(&filehead.bfType), sizeof(filehead.bfType));
	out.write(reinterpret_cast<char*>(&filehead.bfSize), sizeof(filehead.bfSize));
	out.write(reinterpret_cast<char*>(&filehead.bfReserved1), sizeof(filehead.bfReserved1));
	out.write(reinterpret_cast<char*>(&filehead.bfReserved2), sizeof(filehead.bfReserved2));
	out.write(reinterpret_cast<char*>(&filehead.bfOffBits), sizeof(filehead.bfOffBits));
	out.write(reinterpret_cast<char*>(&datahead.biSize), sizeof(datahead.biSize));
	out.write(reinterpret_cast<char*>(&datahead.biWidth), sizeof(datahead.biWidth));
	out.write(reinterpret_cast<char*>(&datahead.biHeight), sizeof(datahead.biHeight));
	out.write(reinterpret_cast<char*>(&datahead.biPlanes), sizeof(datahead.biPlanes));
	out.write(reinterpret_cast<char*>(&datahead.biBitCount), sizeof(datahead.biBitCount));
	out.write(reinterpret_cast<char*>(&datahead.biCompression), sizeof(datahead.biCompression));
	out.write(reinterpret_cast<char*>(&datahead.biSizeImages), sizeof(datahead.biSizeImages));
	out.write(reinterpret_cast<char*>(&datahead.biXPelsPerMeter), sizeof(datahead.biXPelsPerMeter));
	out.write(reinterpret_cast<char*>(&datahead.biYPelsPerMeter), sizeof(datahead.biYPelsPerMeter));
	out.write(reinterpret_cast<char*>(&datahead.biClrUsed), sizeof(datahead.biClrUsed));
	out.write(reinterpret_cast<char*>(&datahead.biClrImportant), sizeof(datahead.biClrImportant));
	for (int j = 0; j < MAXN; j++)
		for (int i = 0; i < MAXN; i++) {
			out.write(reinterpret_cast<char*>(&data[i][j].blue), sizeof(data[i][j].blue));
			out.write(reinterpret_cast<char*>(&data[i][j].red), sizeof(data[i][j].red));
			out.write(reinterpret_cast<char*>(&data[i][j].green), sizeof(data[i][j].green));
		}
	out.close();
	return 0;
}
