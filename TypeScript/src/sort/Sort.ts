/**
 *
 * Sort.ts
 *
 * Created by Huy Le Minh on 2020-12-24
 *
 * Visit my github: https://github.com/huyleminh/
 * Contact me: leminhhuy.hcmus@gmail.com
 *
 *
 * File description: Implement Sort Algorithms
*/


function interchangeSort(arr: Array<number>): void {
    for (let i = 0; i < arr.length - 1; i++)
        for (let  j = i + 1; j < arr.length; j++)
            if (arr[i] > arr[j])
                [arr[i], arr[j]] = [arr[j], arr[i]];
}

function selectionSort(arr: Array<number>): void {
    for (let i = 0; i < arr.length - 1; i++) {
        let min = i;
        for (let j = i + 1; j < arr.length; j++) {
            if (arr[j] < arr[min])
                min = j;
        }
        if (min !== i)
            [arr[i], arr[min]] = [arr[min], arr[i]]
    }
}

function bubbleSort(arr: Array<number>): void {
    for (let i = 0; i < arr.length; i++)
        for (let j = arr.length - 1; j > i; j--)
            if (arr[j] < arr[j - 1])
                [arr[j], arr[j - 1]] = [arr[j - 1], arr[j]];
}

function shakerSort(arr: Array<number>): void {
    let left = 0, right = arr.length - 1;
    let flag = left;
    
    while(left < right) {
        for (let i = left; i < right; i++)
            if (arr[i] > arr[i + 1]) {
                [arr[i], arr[i + 1]] = [arr[i + 1], arr[i]];
                flag = i;
            }
        right = flag;

        for (let i = right; i > left; i--)
            if (arr[i] < arr[i - 1]) {
                [arr[i], arr[i - 1]] = [arr[i - 1], arr[i]];
                flag = i;
            }
        left = flag;
    }
}

function insertionSort(arr: Array<number>): void {
    let j, temp;
    for (let i = 1; i < arr.length; i++) {
        j = i - 1;
        temp = arr[i];
        while (j > -1 && temp < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;  
    }
}

function createMaxHeap(arr: Array<number>, left: number, right: number): void {
    let i = left, check = arr[i];
    let j = 2 * i + 1;
    while (j <= right) {
        if (j < right)
            if (arr[j] < arr[j + 1])
                j++;
        if (check >= arr[j])
            break;
        arr[i] = arr[j];
        i = j;
        j = 2 * i + 1;
    }
    arr[i] = check;
}

function heapSort(arr: Array<number>): void {
    let left = Math.floor(arr.length / 2) - 1;
    while (left > -1) {
        createMaxHeap(arr, left, arr.length - 1);
        left--;
    }

    let right = arr.length - 1;
    while (right > 0) {
        [arr[0], arr[right]] = [arr[right], arr[0]];
        right--;
        createMaxHeap(arr, 0, right);
    }
}



export {interchangeSort, selectionSort, bubbleSort, shakerSort, insertionSort, heapSort};