/**
 *
 * Search.h
 *
 * Created by Huy Le Minh on 2020-12-24
 *
 * Visit my github: https://github.com/huyleminh/
 * Contact me: leminhhuy.hcmus@gmail.com
 *
 *
 * File description: Implement Search Algorithms
*/

#ifndef _SEARCH_H_
#define _SEARCH_H_


//----------------------------------------------------
//class definition

/**
 * @return: If the key is founded, return the index of the key otherwise return -1
*/
template<class T>
class Search {
public:
    //Linear search
    static int linearSeach(T* arr, const int& n, const T& key);

    //Linear search using sentinal
    static int sentinalSearch(T* arr, const int& n, const T& key);

    //Iterative binary search
    static int iterativeBinarySearch(T* arr, const int& n, const T& key);

    //Recursive binary search
    static int recursiveBinarySearch(T* arr, const int& left, const int& right, const T& key);
};


//---------------------------------------------------
//Implementation

template<class T>
int Search<T>::linearSeach(T* arr, const int& n, const T& key) {
    for (int i = 0; i < n; ++i)
        if (arr[i] == key)
            return i;
    return -1;
}

template<class T>
int Search<T>::sentinalSearch(T* arr, const int& n, const T& key) {
    T* cloneArr = new T[n + 1];
    for (int i = 0; i < n; ++i)
        cloneArr[i] = arr[i];
    cloneArr[n] = key; //sentinal

    int index = -1;
    for (int i = 0; ; ++i) {
        if (cloneArr[i] == key) {
            index = i;
            break;
        }
    }
    
    delete[] cloneArr;
    return (index != -1) ? index : -1;
}

template<class T>
int Search<T>::iterativeBinarySearch(T* arr, const int& n, const T& key) {
    int left, right;
    left = 0;
    right = n - 1;

    if (left == right) 
        return (arr[left] == key) ? left : -1;
    
    int mid;
    while (left < right) {
        mid = (left + right) / 2;
        if (key == arr[mid])
            return mid;
        else if (key < arr[mid])
            right = mid - 1;
        else 
            left = mid + 1;
    }
    return -1;
}

template<class T>
int Search<T>::recursiveBinarySearch(T* arr, const int& left, const int& right, const T& key) {
    if (left == right)
        return (arr[left] == key) ? left : -1;
    int mid = (left + right) / 2;
    if (key == arr[mid])
        return mid;
    return (key < arr[mid]) ? recursiveBinarySearch(arr, left, mid - 1, key) : recursiveBinarySearch(arr, mid + 1, right, key);
}


#endif