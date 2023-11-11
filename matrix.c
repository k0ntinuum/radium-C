void shift_row(u32 h[N][N], u32 r, u32 s) {
    for (u32 i = 0; i < N; i++) temp[i] = h[r][(i + s)%N];
    for (u32 i = 0; i < N; i++) h[r][i] = temp[i];
}
void shift_col(u32 h[N][N], u32 c, u32 s) {
    for (u32 i = 0; i < N; i++) temp[i] = h[(i + s)%N][c];
    for (u32 i = 0; i < N; i++) h[i][c] = temp[i];
}
u32 random_bit() { 
	return arc4random_uniform(B);
}
void randomize_key(u32 h[N][N]) {
	for (u32 i = 0; i < N; i++) for (u32 j = 0; j < N; j++) h[i][j] = random_bit();
}
void copy_key(u32 t[N][N],u32 s[N][N]) {
    for (u32 i = 0; i < N; i++) for (u32 j = 0; j < N; j++) t[i][j] = s[i][j];
}
u32 trace(u32 h[N][N]) {
	u32 s = 0;
	for (u32 i = 0; i < N; i++) s += h[i][i];
	return s;
}
void spin(u32 h[N][N], u32 d, u32 a) {
	for (u32 i = 0 ; i < N ; i++) {
		switch (( i + d )% B) {
			case 0 : shift_row(h, i, h[i][i] + a + 1);break;
			case 1 : shift_col(h, i, h[i][i] + a + 1);break;
		}
	}
}
void auto_spin(u32 h[N][N], u32 j) {
	for (u32 i = 0 ; i < N ; i++) {
        switch (h[i][j]) {
            case 0 : shift_row(h, i, h[i][i] + 1);break;
            case 1 : shift_col(h, i, h[i][i] + 1);break;
        }
	}
}