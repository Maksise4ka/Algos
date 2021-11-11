#include <stdio.h>
#include <stdlib.h>
 
int max(int a, int b){
  if (a > b)
    return a;
  return b;
}
   
int main(void){
  int w, h;
  FILE *fin, *fout;
  fin = fopen("turtle.in", "r");
  fout = fopen("turtle.out", "w");
  fscanf(fin, "%d%d", &h, &w);
   
  //int a[h][w];
   
  int (*a)[w] = malloc(sizeof(int[h][w]));
  int (*f)[w] = malloc(sizeof(int[h][w]));
 
  for (int i = 0; i < h; ++i)
    for (int j = 0; j < w; ++ j)
      fscanf(fin, "%d", &a[i][j]);
 
  f[h - 1][0] = a[h - 1][0];
 
  for (int i = h - 2; i >= 0; --i)
    f[i][0] =  a[i][0] + f[i + 1][0];
 
  for (int i = 1; i < w; ++i)
    f[h - 1][i] =  a[h - 1][i] + f[h - 1][i - 1];
 
  for (int i = h - 2; i >= 0; --i)
    for (int j = 1; j < w; ++j)
      f[i][j] = a[i][j] + max(f[i + 1][j], f[i][j - 1]);
  fprintf(fout, "%d ", f[0][w - 1]);
  free(a);
  fclose(fin);
  fclose(fout);
  return 0;