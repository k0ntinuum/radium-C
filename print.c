void frgb(u32 r, u32 g, u32 b) {
    printf("\033[38;2;%d;%d;%dm",r,g,b);
}
void brgb(u32 r, u32 g, u32 b) {
    printf("\033[48;2;%d;%d;%dm",r,g,b);
}
void rgb(int r, int g, int b) {
    printf("\x1b[38;2;%d;%d;%dm",r,g,b);
}
void cls() {
    printf( "\x1b[2J");
}

void hide_cursor() {
    printf("\x1b[?25l");
}
void show_cursor() {
    printf("\x1b[?25h");
}

void cursor_to(int r, int c) {
    printf("\x1b[%d;%dH",r,c);
}

void print_symbol(u32 i) {
	printf("%s", i == 0 ? "O" : "|");
}
void print_f(u32 h[N][N]) {
	for (u32 i = 0; i < N; i++) {
        printf("            ");
		for (u32 j = 0; j < N; j++) printf("%s", h[i][j] == 0 ? "O " : "| ");
		printf("\n");
	}
}
void print_f_color(u32 h[N][N]) {
    u32 hue_1 = 45;
    u32 hue_2 = 255;
    brgb(0,0,0);
	for (u32 i = 0; i < N; i++) {
        printf("            ");
		for (u32 j = 0; j < N; j++) {
            switch (h[i][j]) {
                case 0 : 
                    rgb(135,135,135);
                    brgb(10,10,10);
                    printf("O\u2588");
                    break;
        
                    break;

                case 1 : 
                    rgb(hue_1,hue_1,hue_1);
                    printf("\u2588\u2588");
                    break;
                default : 
                    frgb(5,5,5);
                    //frgb(60,60,60);
                    printf("\u2588\u2588");
                    brgb(0,0,0);
                    //frgb(255,255,255);
                    break;
            }
        }
        brgb(0,0,0);
		printf("\n");
	}
}
	