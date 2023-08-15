#include<string.h>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define WIDTH 10
#define HEIGHT 10

int locateWords(char matrix[WIDTH][HEIGHT]) {

    FILE* f = fopen("words.txt", "r");

    if (f == NULL) {
        perror("file");
        return 1;
    }

    // horizontal
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            char buffer[12];
 
            int i = 0;
            while (i < WIDTH - x) {
                buffer[i] = matrix[y][x + i];
                buffer[i + 1] = '\0';
                char line[256];
                while (fgets(line, sizeof(line), f) != NULL) {
                    line[strcspn(line, "\n")] = '\0';
                    if (strcmp(buffer, line) == 0) {
                        if (strcmp(buffer, "I") == 1) {
                            printf("%s, %d:%d\n", buffer, y, x);
                            return 1;
                        }
                    }
                } 

                fseek(f, 0, SEEK_SET);
                ++i;
            }
        }
    }

    fclose(f);
    return 0;
}

int main(void) {

    char matrix[WIDTH][HEIGHT];

    for (;;) {
        for (int x = 0; x < WIDTH; ++x) {
            for (int y = 0; y < HEIGHT; ++y) {

                int offset = rand()%26;
                int rn = 65 + offset;

                matrix[x][y] = rn;
                printf("%c ", rn);

            }
            printf("\n");
        }
        printf("\n");

        int r = locateWords(matrix);
        if (r != 0) {
            perror("error");
            return r;
        
        }
    }

    return 0;
}
