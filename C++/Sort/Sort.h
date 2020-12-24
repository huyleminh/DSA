/**
 *
 * Sort.h
 *
 * Created by Huy Le Minh on 2020-12-24
 *
 * Visit my github: https://github.com/huyleminh/
 * Contact me: leminhhuy.hcmus@gmail.com
 *
 *
 * File description: Implement Sort Algorithms
 * 
 * All sort algorithms below are used to sort an array of T type in ascending order
 * *Note: If T is not a basic type, use must implement comparision operator for it
*/


#ifndef _SORT_H_
#define _SORT_H_

#include <cmath>

template<class T>
void swapTwoValues(T& a, T& b) {
    T tempVal = a;
    a = b;
    b = tempVal;
}

//------------------------------------------------
//class definition

template<class T>
class Sort {
private: 
    static void createHeap(T* arr, const int& left, const int& right);

    static int findPartition(T* arr, const int& left, const int& right);

    static void sortRadixByStep(T* arr, const int& n, const int& step);
    
    static void mergeTwoArray(T* arr, const int& left, const int& mid, const int& right);

public:
    static void interchangeSort(T* arr, const int& n);

    static void selectionSort(T* arr, const int& n);

    static void bubbleSort(T* arr, const int& n);
    static void shakerSort(T* arr, const int& n); //Improvement of bubble sort

    static void insertionSort(T* arr, const int& n);

    static void heapSort(T* arr, const int& n);

    static void quickSort(T* arr, const int& left, const int& right);

    static void radixSort(T* arr, const int& n);

    static void mergeSort(T* arr, const int& left, const int& right);
};

//------------------------------------------------
//Implementation

//------------------------------------------------
//private:

template<class T>
void Sort<T>::createHeap(T* arr, const int& left, const int& right) { //Max heap
    int i = left; 
    int j = 2 * i + 1;
    T x = arr[i];
    while (j <= right) {
        if (j < right)
            if (arr[j] < arr[j + 1]) j++;
        if (x >= arr[j]) break;
        arr[i] = arr[j];
        i = j; j = 2 * i + 1;
    }
    arr[i] = x;
}

template<class T>
int Sort<T>::findPartition(T* arr, const int& left, const int& right) {
    T pivot = arr[(left + right) / 2];
    int i = left - 1;
    int j = right + 1;

    while (i < j) {
        while(arr[++i] < pivot);
        while (arr[--j] > pivot);
        swapTwoValues(arr[i], arr[j]);
    }
    swapTwoValues(arr[i], arr[j]);
    return j;
}

template<class T>
void mergeTwoArray(T* arr, const int& left, const int& mid, const int& right) {
    int nleft = mid - left + 1;
    int nright = right - mid;

    T* arrLeft = new T[nleft];
    T* arrRight = new T[nright];

    for (int i = 0; i < nleft; i++)
        arrLeft[i] = arr[left + i];
    for (int j = 0; j < nright; j++)
        arrRight[j] = arr[mid + 1 + j];

    int indexLeft = 0;
    int indexRight = 0;
    int index = left;

    while(indexLeft < nleft || indexRight < nright) 
        arr[index++] = (arrLeft[indexLeft] <= arrRight[indexRight]) ? arrLeft[indexLeft++] : arrRight[indexRight++];

    while (indexLeft < nleft) 
        arr[index++] = arrLeft[indexLeft++];
    while (indexRight < nright)
        arr[index++] = arrRight[indexRight++];

    delete[] arrLeft;
    delete[] arrRight;
}

template<class T>
void Sort<T>::sortRadixByStep(T* arr, const int& n, const int& step) {
    T* bins[10];
    int counts[10] = {0};
    int digit;

    for (int i = 0; i < 10; ++i) {
        bins[i] = new T[n];
    }

    //Push each number to bins
    for (int i = 0; i < n; ++i) {
        digit = arr[i] / int(pow(10, step)) % 10;
        bins[digit][counts[digit]++] = arr[i];
    }

    //Combine number to array
    int index = 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < counts[j]; ++j)
            arr[index++] = bins[i][j];
        counts[i] = 0;
        delete bins[i];
    }
}

//------------------------------------------------
//public:
template<class T>
void Sort<T>::interchangeSort(T* arr, const int& n) {
    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
            if (arr[i] > arr[j])
                swapTwoValues(arr[i], arr[j]);
}

template<class T>
void Sort<T>::selectionSort(T* arr, const int& n) {
    for (int i = 0; i < n - 1; ++i) {
        T indexOfMinVal = i;
        for (int j = i + 1; j < n; ++j)
            if (arr[j] < arr[indexOfMinVal])
                indexOfMinVal = j;
        if (indexOfMinVal != i)
            swapTwoValues(arr[i], arr[indexOfMinVal]);
    }
}

template<class T>
void Sort<T>::bubbleSort(T* arr, const int& n) {
    for (int i = 0; i < n - 1; ++i)
        for (int j = n - 1; j > i; --j)
            if (arr[j - 1] > arr[j])
                swapTwoValues(arr[j - 1], arr[j]);
}

template<class T>
void Sort<T>::shakerSort(T* arr, const int& n) {
    int left = 0; //Remembering the position of the last exchange to the left
    int right = n - 1; //Remembering the position of the last exchange to the right
    int flag = right;

    while (left < right) {
        for (int i = left; i < right; ++i) 
            if (arr[i] > arr[i + 1]) {
                swapTwoValues(arr[i], arr[i + 1]);
                flag = i;
            }
        right = flag;

        for (int i = right; i > left; --i)
            if (arr[i] < arr[i - 1 ]) {
                swapTwoValues(arr[i], arr[i - 1]);
                flag = i;
            }
        left = flag;
    }
}

template<class T>
void Sort<T>::insertionSort(T* arr, const int& n) {
    int j, checkVal;

    for (int i = 1; i < n; ++i) {
        checkVal = arr[i];
        j = i - 1;
        while (j > -1) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = checkVal;
    }
}

template<class T>
void Sort<T>::heapSort(T* arr, const int& n) {
    int left = n / 2 - 1;
    while (left > -1) {
        createHeap(arr, left, n - 1);
        --left;
    }

    int right = n - 1;
    while (right > 0) {
        swapTwoValues(arr[0], arr[right]);
        --right;
        createHeap(arr, 0, right);
    }
}

template<class T>
void Sort<T>::quickSort(T* arr, const int& left, const int& right) {
    if (left >= right)
        return;
    int partition = findPartition(arr, left, right);
    quickSort(arr, left, partition);
    quickSort(arr, partition + 1, right);
}

template<class T>
void mergeSort(T* arr, const int& left, const int& right) {
    if (left >= right)
        return;

    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    mergeTwoArray(arr, left, mid, right);
}   

template<class T>
void Sort<T>::radixSort(T* arr, const int& n) {
    //Find max element to determine how many steps todo
    T max = arr[0];
    for (int i = 0; i < n; ++i)
        if (arr[i] > max)
            max = arr[i];
    
    //Find steps
    int steps = floor(log10(max)) + 1;
    for (int i = 0; i < steps; ++i)
        Sort<T>::sortRadixByStep(arr, n, i);
}

#endif