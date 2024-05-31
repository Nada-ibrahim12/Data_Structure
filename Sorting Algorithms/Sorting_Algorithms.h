#include <bits/stdc++.h>

using namespace std;

class Sort_Algorithms
{
public:
    void selection(int a[], int n);

    void insertion(int a[], int n);

    void bubble(int a[], int n);

    void shell(int a[], int n);

    void quick(int a[], int l, int r);

    void mergesort(int a[], int start, int end);

    void merge(int a[], int start, int mid, int end);

    void countSort(int array[], int size);

    void display(int a[] , int size);
};

// select the minimum element then insert it in its correct position (2loop - if w swap)
void Sort_Algorithms::selection(int a[], int n)
{
    int minInd, temp;
    for (int i = 0; i < n - 1; i++)
    {
        minInd = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[minInd])
            {
                minInd = j;
            }
        }
        if (minInd != i)
        {
            temp = a[minInd];
            a[minInd] = a[i];
            a[i] = temp;
        }
    }
}

// bnakhod element w n loop 3ala ba2y el array w n7oto f makano el mzbot  (loop - while w swap l7d myt7t f makano)
void Sort_Algorithms::insertion(int a[], int n)
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (j > 0 && a[j] < a[j - 1])
        {
            temp = a[j];
            a[j] = a[j - 1];
            a[j - 1] = temp;
            j--;
        }
    }
}

// select the maximum element then insert it in its correct position (2loop - if w swap)
void Sort_Algorithms::bubble(int a[], int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (a[j] < a[j - 1])
            {
                temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
            }
        }
    }
}

void Sort_Algorithms::shell(int a[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int j;
            for (j = i; j >= gap && a[j - gap] > a[j]; j -= gap)
            {
                int temp = a[j];
                a[j] = a[j - gap];
                a[j - gap] = temp;
            }
        }
    }

}
// left - right - pivot and swap / recursion
void Sort_Algorithms::quick(int a[], int l, int r)
{
    int i = l, j = r;
    int temp, pivot = a[(l + r) / 2];
    // partition
    while (i <= j)
    {
        while (a[i] < pivot)
            i++;
        while (a[j] > pivot)
            j--;
        if (i <= j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
    // recursion
    if (l < j)
        quick(a, l, j);
    if (r < i)
        quick(a, i, r);
}
 // Divide and conquer
 void Sort_Algorithms::mergesort(int a[], int start, int end) {
     if (start >= end)
         return;
     int mid = start + (end - start) / 2;
     mergesort(a, start, mid);
     mergesort(a, mid + 1, end);
     merge(a, start, mid, end);
 }

void Sort_Algorithms::merge(int a[], int start, int mid, int end) {
    // Get size of 2 subarrays
    int size1 = mid - start + 1;
    int size2 = end - mid;

    // Use vectors for automatic memory management
    std::vector<int> sub1(size1), sub2(size2);

    // Copy the data to each array
    for (int i = 0; i < size1; i++) {
        sub1[i] = a[start + i];
    }
    for (int i = 0; i < size2; i++) {
        sub2[i] = a[mid + 1 + i];
    }

    // Merge the subarrays back into the original array
    int index1 = 0, index2 = 0, indexmid = start;
    while (index1 < size1 && index2 < size2) {
        if (sub1[index1] <= sub2[index2]) {
            a[indexmid] = sub1[index1];
            index1++;
        } else {
            a[indexmid] = sub2[index2];
            index2++;
        }
        indexmid++;
    }

    // Copy any remaining elements of sub1, if any
    while (index1 < size1) {
        a[indexmid] = sub1[index1];
        index1++;
        indexmid++;
    }

    // Copy any remaining elements of sub2, if any
    while (index2 < size2) {
        a[indexmid] = sub2[index2];
        index2++;
        indexmid++;
    }
}
// 3 arrays
void Sort_Algorithms::countSort(int array[], int size)
{
    int output[10];
    int count[10];
    int max = array[0];
    
    // find the max value
    for (int i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }
    //intialize the count array
    for (int i = 0; i <= max; ++i)
    {
        count[i] = 0;
    }
    // Store the count of each element
    for (int i = 0; i < size; i++)
    {
        count[array[i]]++;
    }
    // Store the cummulative count of each element
    for (int i = 1; i <= max; i++)
    {
        count[i] += count[i - 1];
    }
    // Find the index of each element of the original array in count array, and
    // place the elements in output array
    for (int i = size - 1; i >= 0; i--)
    {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }
    //copy the values to the original array
    for (int i = 0; i < size; i++)
    {
        array[i] = output[i];
    }
}

void Sort_Algorithms::display (int a[], int size ){

    for (int i =  0 ; i < size ; i++){
        cout << a[i] << "  " ;
    }
}
