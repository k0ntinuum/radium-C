#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
typedef u_int32_t u32;
const u32 B = 3;
const u32 N = 9;
const u32 T = 11;
u32 F[N][N] = {0};
u32 f[N][N] = {0};
u32 temp[N] = {};

#include"print.c"
#include"matrix.c"
#include"spin.c"
	
int main() {
	demo();
}
