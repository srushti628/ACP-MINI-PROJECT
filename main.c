#include <stdio.h>

#define WIDTH 80
#define HEIGHT 24

#define EMPTY '_'

char picture[HEIGHT][WIDTH];

int main() {
    printf("Canvas created of size %d x %d\n", WIDTH, HEIGHT);
    return 0;
}
