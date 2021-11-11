#include <iostream>
#include <fstream>
 
using namespace std; 
 
const int INF = 1000000007;
long long inversions = 0;
 
 
void merge(int a[], int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;
    int *l = new int [n1 + 2];
    int *R = new int [n2 + 2];
 
    for(int i = 1; i <= n1; ++i)
        l[i] = a[p + i - 1];
 
    for(int i = 1; i <= n2; ++i)
        R[i] = a[q + i];
 
    l[n1 + 1] = INF;
    R[n2 + 1] = INF;
 
    int i = 1, j = 1;
    for (int k = p; k <= r; k++) {
        if(l[i] <= R[j]) {
            a[k] = l[i];
            i++;
        }
        else {
            a[k] = R[j];
            inversions += n1 - i + 1;
            j++;
        }
    }
 
    delete [] l;
    delete [] R;
 
}
 
void merge_sort(int a[], int p, int r){
    if (p < r){
        int q = (p + r) / 2;
        merge_sort(a, p, q);
        merge_sort(a, q + 1, r);
        merge(a, p, q, r);
    }
}
 
 
int main(){
    ifstream fin ("inversions.in");
    ofstream fout("inversions.out");
    int n;
    fin >> n;
    int *a = new int [n];
    for(int i = 0; i < n; ++i)
        fin >> a[i];
 
    merge_sort(a, 0, n - 1);
    fout << inversions;
 
    fin.close();
    fout.close();
    delete [] a;
    return 0;
}