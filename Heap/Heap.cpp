#include "Heap.h"

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i<n ; i++){
        cin >> a[i];
    }
    heap_sort(a,n);
    print(a,n);
    heap_extract_max(a,n);
    heap_max(a);
    heap_max_insert(a,5,n);
}