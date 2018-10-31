#include <stdio.h>

int main() {
  int width, height;
  FILE* bmpfp = fopen("DATA5611.BMP", "rb");
  fseek(bmpfp, 18, SEEK_SET);
  fread(&width, sizeof(int), 1, bmpfp);
  fread(&height, sizeof(int), 1, bmpfp);
  printf("%d %d", width, height);
}