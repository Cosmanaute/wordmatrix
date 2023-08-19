#include<string.h>
#include<ctype.h>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define WIDTH 10
#define HEIGHT 10

void reverse(char* s) {
    int i, tmp;
    int len = strlen(s);
    for (int i = 0; i < len/2; ++i) {
        tmp = s[i];
        s[i] = s[len-i-1];
        s[len-i-1] = tmp;
    }
}

void strToUpper(char *str) {
    for (int i = 0; i < strlen(str); ++i) {
        str[i] = toupper(str[i]);
    }
}

int locateWords(char matrix[WIDTH][HEIGHT]) {

    FILE* f = fopen("words.txt", "r");

    if (f == NULL) {
        perror("file");
        return 1;
    }

    printf("\n\n__________\nHORIZONTAL\n\n");

    // horizontal
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            int i = 0;
            while (i < WIDTH - x) {
                char buffer[WIDTH - i + 1];
                buffer[i] = matrix[y][x + i];
                buffer[i + 1] = '\0';
                char line[24];
                while (fgets(line, sizeof(line), f) != NULL) {
                    line[strcspn(line, "\n")] = '\0';
                    strToUpper(line);
                    if (strcmp(buffer, line) == 0) {
                        printf("%s @ %d:%d\n", buffer, y + 1, x + 1);
                    }
                    reverse(buffer);
                    if (strlen(buffer) != 1 && strcmp(buffer, line) == 0) {
                        printf("%s @ %d:%d\n", buffer, y + 1, x + 1);
                    }
                } 

                fseek(f, 0, SEEK_SET);
                ++i;
            }
        }
    }
    
    fseek(f, 0, SEEK_SET);
    printf("\n\n________\nVERTICAL\n\n");

    // vertical
    for (int x = 0; x < WIDTH; ++x) {
        for (int y = 0; y < HEIGHT; ++y) {
 
            int i = 0;
            while (i < HEIGHT - y) {
                char buffer[HEIGHT - i + 1];
                buffer[i] = matrix[y + i][x];
                buffer[i + 1] = '\0';
                char line[24];
                while (fgets(line, sizeof(line), f) != NULL) {
                    line[strcspn(line, "\n")] = '\0';
                    strToUpper(line);
                    if (strcmp(buffer, line) == 0) {
                        printf("%s @ %d:%d\n", buffer, y + 1, x + 1);
                    }
                    reverse(buffer);
                    if (strlen(buffer) != 1 && strcmp(buffer, line) == 0) {
                        printf("%s @ %d:%d\n", buffer, y + 1, x + 1);
                    }
                } 

                fseek(f, 0, SEEK_SET);
                ++i;
            } 
        }
    }

    fseek(f, 0, SEEK_SET);
    printf("\n\n______________\nDIAGONAL(Left)\n\n");

    // diagonal left
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = WIDTH - 1; x >= 0; --x) {
            int i = 0;
            while (i <= x && i <= HEIGHT - y - 1) {
                int size;
                if (y > WIDTH - 1 - x) size = WIDTH - 1 - x;
                else size = y;

                char buffer[size + 1];
                buffer[i] = matrix[y + i][x - i]; // Left diagonal indexing
                buffer[i + 1] = '\0';
                char line[24];
                while (fgets(line, sizeof(line), f) != NULL) {
                    line[strcspn(line, "\n")] = '\0';
                    strToUpper(line);
                    if (strcmp(buffer, line) == 0) {
                        printf("%s @ %d:%d\n", buffer, y + 1, x + 1);
                    }
                    reverse(buffer);
                    if (strlen(buffer) != 1 && strcmp(buffer, line) == 0) {
                        printf("%s @ %d:%d\n", buffer, y + 1, x + 1);
                    }
                } 

                fseek(f, 0, SEEK_SET);
                ++i;
            }
        }
    }

    fseek(f, 0, SEEK_SET);
    printf("\n\n______________\nDIAGONAL(Right)\n\n");

    // diagonal right 
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            int i = 0;
            while (i <= WIDTH - 1 - x && i <= HEIGHT - y - 1) {
                int size;
                if (y > x) size = x;
                else size = y;

                char buffer[size + 1];
                buffer[i] = matrix[y + i][x + i]; 
                buffer[i + 1] = '\0';
                char line[24];
                while (fgets(line, sizeof(line), f) != NULL) {
                    line[strcspn(line, "\n")] = '\0';
                    strToUpper(line);
                    if (strcmp(buffer, line) == 0) {
                        printf("%s @ %d:%d\n", buffer, y + 1, x + 1);
                    }
                    reverse(buffer);
                    if (strlen(buffer) != 1 && strcmp(buffer, line) == 0) {
                        printf("%s @ %d:%d\n", buffer, y + 1, x + 1);
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
    srand(time(NULL));

 //   for (;;) {
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
   // }

    return 0;
}
