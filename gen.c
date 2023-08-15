#include<time.h>
#include<stdio.h>
#include<stdlib.h>

#define WIDTH 10
#define HEIGHT 10

int main(void) {
    srand(time(NULL));
    FILE* f = fopen("matrix.txt", "a");

    if (f == NULL) {
        return 1;
    }

    for (;;) {
        for (int x = 0; x < WIDTH; ++x) {
            for (int y = 0; y < HEIGHT; ++y) {

                int offset = rand()%26;
                int rn = 65 + offset;

                fprintf(f, "%c ", rn);
                printf("%c ", rn);
            }
            fprintf(f, "\n");
            printf("\n");
        }
        fprintf(f, "\n");
        printf("\n");
    }

    fclose(f);
    return 0;
}
