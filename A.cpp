#include <iostream>
#include <fstream>
 
using namespace std;
 
int partition(int a[], int p, int r){
    int x = a[r];
    int i = p - 1;
    for (int j = p; j <= r - 1; j ++){
        if (a[j] <= x){
            i ++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[r]);
    return i + 1;
}
 
int randomized_partition(int a[], int p, int r){
    int i = rand() % (r - p) + p;
    swap(a[r], a[i]);
    return partition(a, p , r);
}
 
void quicksort(int a[], int p, int r){
    if (p < r){
        int q = randomized_partition(a, p, r);
        quicksort(a, p, q - 1);
        quicksort(a, q + 1, r);
    }
}
 
 
int main(){
    ifstream fin ("sort.in");
    ofstream fout ("sort.out");
    int n;
    fin >> n;
     
    int *a = new int [n];   
     
    for(int i = 0; i < n; ++i){
        fin >> a[i];
    }
 
    quicksort(a, 0, n - 1);
 
    for (int i = 0; i < n; ++i)
        fout << a[i] << ' ';
 
    fin.close ();
    fout.close ();
    delete [] a;
    return 0;