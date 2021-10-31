// Ref: https://github.com/B-Con/crypto-algorithms/blob/master/sha1.c
 
#include <memory.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <fstream>
#include <iostream>
/****************************** MACROS ******************************/
#define SHA1_BLOCK_SIZE 20  // SHA1 outputs a 20 byte digest
#define ROTLEFT(a, b) ((a << b) | (a >> (32 - b)))
 
using namespace std;
 
/**************************** DATA TYPES ****************************/
typedef unsigned char BYTE;  // 8-bit byte
typedef unsigned int WORD;  // 32-bit word, change to "long" for 16-bit machines
 
typedef struct {
    BYTE data[64];
    WORD datalen;
    unsigned long long bitlen;
    WORD state[5];
    WORD k[4];
} SHA1_CTX;
 
/*********************** FUNCTION DEFINITIONS ***********************/
void sha1_transform(SHA1_CTX *ctx, const BYTE data[]) {
    WORD a, b, c, d, e, i, j, t, m[80];
 
    for (i = 0, j = 0; i < 16; ++i, j += 4)
        m[i] = (data[j] << 24) + (data[j + 1] << 16) + (data[j + 2] << 8) +
               (data[j + 3]);
    for (; i < 80; ++i) {
        m[i] = (m[i - 3] ^ m[i - 8] ^ m[i - 14] ^ m[i - 16]);
        m[i] = (m[i] << 1) | (m[i] >> 31);
    }
 
    a = ctx->state[0];
    b = ctx->state[1];
    c = ctx->state[2];
    d = ctx->state[3];
    e = ctx->state[4];
 
    for (i = 0; i < 20; ++i) {
        t = ROTLEFT(a, 5) + ((b & c) ^ (~b & d)) + e + ctx->k[0] + m[i];
        e = d;
        d = c;
        c = ROTLEFT(b, 30);
        b = a;
        a = t;
    }
    for (; i < 40; ++i) {
        t = ROTLEFT(a, 5) + (b ^ c ^ d) + e + ctx->k[1] + m[i];
        e = d;
        d = c;
        c = ROTLEFT(b, 30);
        b = a;
        a = t;
    }
    for (; i < 60; ++i) {
        t = ROTLEFT(a, 5) + ((b & c) ^ (b & d) ^ (c & d)) + e + ctx->k[2] +
            m[i];
        e = d;
        d = c;
        c = ROTLEFT(b, 30);
        b = a;
        a = t;
    }
    for (; i < 80; ++i) {
        t = ROTLEFT(a, 5) + (b ^ c ^ d) + e + ctx->k[3] + m[i];
        e = d;
        d = c;
        c = ROTLEFT(b, 30);
        b = a;
        a = t;
    }
 
    ctx->state[0] += a;
    ctx->state[1] += b;
    ctx->state[2] += c;
    ctx->state[3] += d;
    ctx->state[4] += e;
}
 
void sha1_init(SHA1_CTX *ctx) {
    ctx->datalen = 0;
    ctx->bitlen = 0;
    ctx->state[0] = 0x67452301;
    ctx->state[1] = 0xEFCDAB89;
    ctx->state[2] = 0x98BADCFE;
    ctx->state[3] = 0x10325476;
    ctx->state[4] = 0xc3d2e1f0;
    ctx->k[0] = 0x5a827999;
    ctx->k[1] = 0x6ed9eba1;
    ctx->k[2] = 0x8f1bbcdc;
    ctx->k[3] = 0xca62c1d6;
}
 
void sha1_update(SHA1_CTX *ctx, const BYTE data[], size_t len) {
    size_t i;
 
    for (i = 0; i < len; ++i) {
        ctx->data[ctx->datalen] = data[i];
        ctx->datalen++;
        if (ctx->datalen == 64) {
            sha1_transform(ctx, ctx->data);
            ctx->bitlen += 512;
            ctx->datalen = 0;
        }
    }
}
 
void sha1_final(SHA1_CTX *ctx, BYTE hash[]) {
    WORD i;
 
    i = ctx->datalen;
 
    // Pad whatever data is left in the buffer.
    if (ctx->datalen < 56) {
        ctx->data[i++] = 0x80;
        while (i < 56) ctx->data[i++] = 0x00;
    } else {
        ctx->data[i++] = 0x80;
        while (i < 64) ctx->data[i++] = 0x00;
        sha1_transform(ctx, ctx->data);
        memset(ctx->data, 0, 56);
    }
 
    // Append to the padding the total message's length in bits and transform.
    ctx->bitlen += ctx->datalen * 8;
    ctx->data[63] = ctx->bitlen;
    ctx->data[62] = ctx->bitlen >> 8;
    ctx->data[61] = ctx->bitlen >> 16;
    ctx->data[60] = ctx->bitlen >> 24;
    ctx->data[59] = ctx->bitlen >> 32;
    ctx->data[58] = ctx->bitlen >> 40;
    ctx->data[57] = ctx->bitlen >> 48;
    ctx->data[56] = ctx->bitlen >> 56;
    sha1_transform(ctx, ctx->data);
 
    // Since this implementation uses little endian byte ordering and MD uses
    // big endian, reverse all the bytes when copying the final state to the
    // output hash.
    for (i = 0; i < 4; ++i) {
        hash[i] = (ctx->state[0] >> (24 - i * 8)) & 0x000000ff;
        hash[i + 4] = (ctx->state[1] >> (24 - i * 8)) & 0x000000ff;
        hash[i + 8] = (ctx->state[2] >> (24 - i * 8)) & 0x000000ff;
        hash[i + 12] = (ctx->state[3] >> (24 - i * 8)) & 0x000000ff;
        hash[i + 16] = (ctx->state[4] >> (24 - i * 8)) & 0x000000ff;
    }
}
 
void sha1(int password, char *output) {
    char input[256];
    sprintf(input, "%d", password);
 
    BYTE buf[SHA1_BLOCK_SIZE];
    SHA1_CTX ctx;
 
    sha1_init(&ctx);
    sha1_update(&ctx, (unsigned char *)input, strlen(input));
    sha1_final(&ctx, buf);
    for (int i = 0; i < SHA1_BLOCK_SIZE; i++) {
        sprintf(output + (i * 2), "%02x", buf[i]);
    }
}
char s[5005];
inline bool same(char *a, char *b) {
	int la = strlen(a), lb = strlen(b);
	if (la != lb)	return false;
	for(int i = 0; i < la; i++)
		if(a[i] != b[i])	return false;
	return true; 
}
inline bool check(int x) {
	char code[100];
	sha1(x, code);
	return same(code, s);
}
int main() {
	ifstream in;
	ofstream out;
	int l, r;
	in.open("checkpoint.txt");
	if (!in) {
		in.close();
		cin >> l >> r >> s;
		FILE *ff;
		ff = fopen("checkpoint.txt", "w");
		out.open("checkpoint.txt");
		out << l << " " << r << endl << s << endl;
		out.close();
		in.open("checkpoint.txt");
//		cp << l << " " << r << endl << s << endl;
	}
	in >> l >> r >> s;
	in.close();
	for(int i = l; i <= r; i++) {
		if(check(i)) {
			cout << i << endl; 
			return 0;
		}
		if(i % 1000 == 0){
			out.open("checkpoint.txt");
			out << i + 1 << " " << r << endl << s << endl; 
			out.close();
		}
	}
    return 0;
}
