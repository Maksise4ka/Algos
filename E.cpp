#include <iostream>
#include <fstream>
  
using namespace std;
  
void quicksort(int a[], int left, int right, int k) {
    int i = left;
    int j = right;
    int key = a[(i + j) / 2];
 
    if (left == right) 
        return;
     
    while (i <= j) {
        while (a[i] < key)
            i ++;
        while (a[j] > key)
            j --;
        if (i <= j) {
            swap(a[i], a[j]);
            i ++;
            j --;
        }
    }
 
    if (k >= i && k <= right) 
        quicksort(a, i, right, k);
 
    if (k <= j && k >= left)
        quicksort(a, left, j, k);
     
}
  
  
int main(){
    ifstream fin("kth.in");
    ofstream fout("kth.out");
    int n, k, A, B, C, a1, a2;
    fin >> n >> k >> A >> B >> C >> a1 >> a2;
    int *a = new int[n];
    a[0] = a1;
    a[1] = a2;
    for (int i = 2; i < n; ++i)
        a[i] = A * a[i - 2] + B * a[i - 1] + C;
         
    quicksort(a, 0, n - 1, k - 1);
    fout << a[k - 1];
 
    fin.close ();
    fout.close ();
    delete [] a;
    return 0;
}