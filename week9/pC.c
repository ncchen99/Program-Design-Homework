#include <stdio.h>
#define SIZE 256

void alpha_composite(unsigned int image[][SIZE], unsigned int width, unsigned int height, float alpha, int background_color);

int main() {
    unsigned int width, height, image[SIZE][SIZE] = {0}, backgounrd_color;
    float alpha;

    scanf("%f %u", &alpha, &backgounrd_color);
    scanf("%u %u", &width, &height);
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            scanf("%u", &image[i][j]);
        }
    }

    alpha_composite(image, width, height, alpha, backgounrd_color);

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            printf("%u ", image[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void alpha_composite(unsigned int image[][SIZE], unsigned int width, unsigned int height, float alpha, int background_color) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i][j] = (image[i][j] * alpha + background_color * 1 * (1 - alpha)) / (alpha + 1 * (1 - alpha));
        }
    }
}