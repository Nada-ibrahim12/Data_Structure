#include "Sorting_Algorithms.h"

int main()
{
    Sort_Algorithms sorter;

    int arr1[] = {64, 25, 12, 22, 11};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Selection Sort: ";
    sorter.selection(arr1, n1);
    sorter.display(arr1, n1);

    int arr2[] = {12, 11, 13, 5, 6};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "Insertion Sort: ";
    sorter.insertion(arr2, n2);
    sorter.display(arr2, n2);

    int arr3[] = {5, 1, 4, 2, 8};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    cout << "Bubble Sort: ";
    sorter.bubble(arr3, n3);
    sorter.display(arr3, n3);

    int arr4[] = {12, 34, 54, 2, 3};
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    cout << "Shell Sort: ";
    sorter.shell(arr4, n4);
    sorter.display(arr4, n4);

    int arr5[] = {10, 7, 8, 9, 1, 5};
    int n5 = sizeof(arr5) / sizeof(arr5[0]);
    cout << "Quick Sort: ";
    sorter.quick(arr5, 0, n5 - 1);
    sorter.display(arr5, n5);

    int arr6[] = {12, 11, 13, 5, 6, 7};
    int n6 = sizeof(arr6) / sizeof(arr6[0]);
    cout << "Merge Sort: ";
    sorter.mergesort(arr6, 0, n6 - 1);
    sorter.display(arr6, n6);

    int arr7[] = {4, 2, 2, 8, 3, 3, 1};
    int n7 = sizeof(arr7) / sizeof(arr7[0]);
    cout << "Counting Sort: ";
    sorter.countSort(arr7, n7);
    sorter.display(arr7, n7);

    return 0;
}