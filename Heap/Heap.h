#include <bits/stdc++.h>

using namespace std;

void max_heapify(int a[], int i, int n){
    while (true) {
        int left = 2*i + 1;
        int right = 2*i + 2;
        int max = i;
        if (left < n && a[left] > a[max]){
            max = left;
        }
        if (right < n && a[right] > a[max]){
            max = right;
        }
        if (max == i) {
            break; 
        }
        swap(a[max], a[i]);
        i = max;
    }
}

void build_max_heap(int a[], int n){

    for (int i = (n/2)-1 ; i >=0 ; i--){
        max_heapify(a,i,n);
    }
}
void heap_sort(int a[], int n){
    build_max_heap(a,n);
    for (int i = n-1 ; i >= 0 ; i--){
        swap(a[0],a[i]);
        max_heapify(a,0,i);
    }
}

void print(int a[], int n){
    for (int i = 0; i < n ; i++){
        cout << a[i] << "  ";
    }
    cout << endl;
}
int heap_extract_max(int a[], int n){
    if (n<1){
        cout << "heap underflow"<< endl;
        return 0;
    }
    int max = a[0];
    a[0]=a[n-1];
    max_heapify(a,0,n);
    return max;
}
int heap_max(int a[]){
    return a[0];
}
void heap_inc_key(int a[], int i, int key){
    if (key < a[i]){
        cout << "new key is smaller than current key"<< endl;
        return;
    }
    a[i] = key;
    while (i>0 && a[(i - 1) / 2] < a[i]){
        swap (a[i], a[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void heap_max_insert(int a[],int key,int n){
    n++;
    a[n-1] = INT_MIN;
    heap_inc_key(a, n+1, key);
}