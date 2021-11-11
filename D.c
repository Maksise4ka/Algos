#include <stdio.h>
#include <stdlib.h>
 
int main(void){
    int n;
 
    FILE *fin, *fout;
    fin = fopen("smallsort.in", "r");
    fout = fopen("smallsort.out", "w");
    fscanf(fin, "%d", &n);
    int *a = malloc(n*sizeof(int));
 
    for (int i = 0; i < n; ++i)
        fscanf(fin, "%d", &a[i]);
     
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - 1; ++j)
            if (a[j] > a[j + 1]){
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
 
    for (int i = 0; i < n; ++i)
        fprintf(fout,"%d ", a[i]);
 
    free(a);
    fclose(fin);
    fclose(fout);
    return 0;
}