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
    uint16_t bfType;      // 2字节，文件类型（magic number），一般为0x4D42；
    uint32_t bfSize;      // 4字节，BMP文件的大小（单位为字节）；
    uint16_t bfReserved1; // 2字节，保留，一般设置为0；
    uint16_t bfReserved2; // 2字节，保留，一般设置为0；
    uint32_t bfOffBits;   // 4字节，位图数据（像素数组）的地址偏移，也就是起始地址。
}filehead;
struct BitMapInfoHeader {
    uint32_t biSize;          // 4字节，信息头的大小，即40；
    int32_t biWidth;          // 4字节，（有符号整数）以像素为单位说明图像的宽度；
    int32_t biHeight;         // 4字节，（有符号整数）以像素为单位说明图像的高度;
    uint16_t biPlanes;        // 2字节，为目标设备说明颜色平面数，总被设置为1；
    uint16_t biBitCount;      // 2字节，说明比特数/像素数，值有1、2、4、8、16、24、32；
    uint32_t biCompression;   // 4字节，说明图像的压缩类型，最常用的就是0（BI_RGB），表示不压缩；
    uint32_t biSizeImages;    // 4字节，说明位图数据的大小，当用BI_RGB格式时，可以设置为0；
    int32_t biXPelsPerMeter;  // 4字节，（有符号整数）表示水平分辨率，单位是像素/米；
    int32_t biYPelsPerMeter;  // 4字节，（有符号整数）表示垂直分辨率，单位是像素/米；
    uint32_t biClrUsed;       // 4字节，说明位图使用的调色板中的颜色索引数，为0说明使用所有；
    uint32_t biClrImportant;  // 4字节，说明对图像显示有重要影响的颜色索引数，为0说明都重要；
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
