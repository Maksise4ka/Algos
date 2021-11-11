#include <stdio.h>
    
int main()
{
  long long int a, b;
  FILE *fin, *fout;
  fin = fopen("aplusbb.in", "r");
  fout = fopen("aplusbb.out", "w");
  fscanf(fin, "%lli%lli", &a, &b);
  long long int c = a + b * b;
  fprintf(fout, "%lli", c);
  fclose(fin);
  fclose(fout);
  return 0;
}