#include <iostream>  
#include <cstring> 
#include <algorithm>
#include <cstdio>
#include <fstream>
using namespace std;
const int MAXL = 1e3 + 5;
struct BitMapFileHeader {
    short bfType;      // 2字节，文件类型（magic number），一般为0x4D42；
    int bfSize;      // 4字节，文件大小；
    short bfReserved1; // 2字节，保留，一般设置为0；
    short bfReserved2; // 2字节，保留，一般设置为0；
    int bfOffBits;   // 4字节，从头到位图数据的偏移；
}a;
struct BitMapInfoHeader {
    int biSize;          // 4字节，信息头的大小，即40；
    int biWidth;          // 4字节，（有符号整数）以像素为单位说明图像的宽度；
    int biHeight;         // 4字节，（有符号整数）以像素为单位说明图像的高度;
    short biPlanes;        // 2字节，为目标设备说明颜色平面数，总被设置为1；
    short biBitCount;      // 2字节，说明比特数/像素数，值有1、2、4、8、16、24、32；
    int biCompression;   // 4字节，说明图像的压缩类型，最常用的就是0（BI_RGB），表示不压缩；
    int biSizeImages;    // 4字节，说明位图数据的大小，当用BI_RGB格式时，可以设置为0；
    int biXPelsPerMeter;  // 4字节，（有符号整数）表示水平分辨率，单位是像素/米；
    int biYPelsPerMeter;  // 4字节，（有符号整数）表示垂直分辨率，单位是像素/米；
    int biClrUsed;       // 4字节，说明位图使用的调色板中的颜色索引数，为0说明使用所有；
    int biClrImportant;  // 4字节，说明对图像显示有重要影响的颜色索引数，为0说明都重要；
}b;
int main() {
	ifstream in;
	in.open("input.bmp", ios::binary);
	in.read(reinterpret_cast<char*>(&a.bfType), sizeof(a.bfType));
	in.read(reinterpret_cast<char*>(&a.bfSize), sizeof(a.bfSize));
	in.read(reinterpret_cast<char*>(&a.bfReserved1), sizeof(a.bfReserved1));
	in.read(reinterpret_cast<char*>(&a.bfReserved2), sizeof(a.bfReserved2));
	in.read(reinterpret_cast<char*>(&a.bfOffBits), sizeof(a.bfOffBits));
	in.read(reinterpret_cast<char*>(&b.biSize), sizeof(b.biSize));
	in.read(reinterpret_cast<char*>(&b.biWidth), sizeof(b.biWidth));
	in.read(reinterpret_cast<char*>(&b.biHeight), sizeof(b.biHeight));
	in.read(reinterpret_cast<char*>(&b.biPlanes), sizeof(b.biPlanes));
	in.read(reinterpret_cast<char*>(&b.biBitCount), sizeof(b.biBitCount));
	in.read(reinterpret_cast<char*>(&b.biCompression), sizeof(b.biCompression));
	in.read(reinterpret_cast<char*>(&b.biSizeImages), sizeof(b.biSizeImages));
	in.read(reinterpret_cast<char*>(&b.biXPelsPerMeter), sizeof(b.biXPelsPerMeter));
	in.read(reinterpret_cast<char*>(&b.biYPelsPerMeter), sizeof(b.biYPelsPerMeter));
	in.read(reinterpret_cast<char*>(&b.biClrUsed), sizeof(b.biClrUsed));
	in.read(reinterpret_cast<char*>(&b.biClrImportant), sizeof(b.biClrImportant));
	
	in.close();
	ofstream out("output.txt");
	out << "bfType=" << a.bfType << endl;
	out << "bfSize=" << a.bfSize << endl;
	out << "bfReserved1=" << a.bfReserved1 << endl;
	out << "bfReserved2=" << a.bfReserved2 << endl;
	out << "bfOffBits=" << a.bfOffBits << endl;
	out << "biSize=" << b.biSize << endl;
	out << "biWidth=" << b.biWidth << endl;
	out << "biHeight=" << b.biHeight << endl;
	out << "biPlanes=" << b.biPlanes << endl;
	out << "biBitCount=" << b.biBitCount << endl;
	out << "biCompression=" << b.biCompression << endl;
	out << "biSizeImages=" << b.biSizeImages << endl;
	out << "biXPelsPerMeter=" << b.biXPelsPerMeter << endl;
	out << "biYPelsPerMeter=" << b.biYPelsPerMeter << endl;
	out << "biClrUsed=" << b.biClrUsed << endl;
	out << "biClrImportant=" << b.biClrImportant << endl;
	out.close();
	return 0;
}
