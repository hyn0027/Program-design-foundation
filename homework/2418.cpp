#include <iostream>  
#include <cstring> 
#include <algorithm>
#include <cstdio>
#include <fstream>
using namespace std;
const int MAXL = 1e3 + 5;
struct BitMapFileHeader {
    short bfType;      // 2�ֽڣ��ļ����ͣ�magic number����һ��Ϊ0x4D42��
    int bfSize;      // 4�ֽڣ��ļ���С��
    short bfReserved1; // 2�ֽڣ�������һ������Ϊ0��
    short bfReserved2; // 2�ֽڣ�������һ������Ϊ0��
    int bfOffBits;   // 4�ֽڣ���ͷ��λͼ���ݵ�ƫ�ƣ�
}a;
struct BitMapInfoHeader {
    int biSize;          // 4�ֽڣ���Ϣͷ�Ĵ�С����40��
    int biWidth;          // 4�ֽڣ����з���������������Ϊ��λ˵��ͼ��Ŀ�ȣ�
    int biHeight;         // 4�ֽڣ����з���������������Ϊ��λ˵��ͼ��ĸ߶�;
    short biPlanes;        // 2�ֽڣ�ΪĿ���豸˵����ɫƽ�������ܱ�����Ϊ1��
    short biBitCount;      // 2�ֽڣ�˵��������/��������ֵ��1��2��4��8��16��24��32��
    int biCompression;   // 4�ֽڣ�˵��ͼ���ѹ�����ͣ���õľ���0��BI_RGB������ʾ��ѹ����
    int biSizeImages;    // 4�ֽڣ�˵��λͼ���ݵĴ�С������BI_RGB��ʽʱ����������Ϊ0��
    int biXPelsPerMeter;  // 4�ֽڣ����з�����������ʾˮƽ�ֱ��ʣ���λ������/�ף�
    int biYPelsPerMeter;  // 4�ֽڣ����з�����������ʾ��ֱ�ֱ��ʣ���λ������/�ף�
    int biClrUsed;       // 4�ֽڣ�˵��λͼʹ�õĵ�ɫ���е���ɫ��������Ϊ0˵��ʹ�����У�
    int biClrImportant;  // 4�ֽڣ�˵����ͼ����ʾ����ҪӰ�����ɫ��������Ϊ0˵������Ҫ��
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
