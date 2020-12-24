/**
 *
 * Search.ts
 *
 * Created by Huy Le Minh on 2020-12-24
 *
 * Visit my github: https://github.com/huyleminh/
 * Contact me: leminhhuy.hcmus@gmail.com
 *
 *
 * File description: Implement Search Algorithms 
*/


//Linear search
function linearSearch(arr: Array<number>, key: number): number {
    for (let i = 0; i < arr.length; i++)
        if (arr[i] === key)
            return i;
    return -1;
}

//Binary search
function binarySearch(arr: Array<number>, key: number): number {
    let left = 0;
    let right = arr.length - 1;

    while(left < right) {
        let mid = Math.floor((left + right) / 2);
        if (arr[mid] === key)
            return mid;
        if (arr[mid] < key)
            left = mid + 1;
        else 
            right = mid - 1;
    }
    if (left == right)
        return (arr[left] === key) ? left : -1;
    return -1;
}

function recursiveBinarySearch(arr: Array<number>, key: number, left: number, right: number): number {
    if (right < left)
        return -1;
    let mid = Math.floor((left + right) / 2);
    if (arr[mid] === key)
        return mid;
    return (arr[mid] > key) ? recursiveBinarySearch(arr, key, left, mid - 1) : recursiveBinarySearch(arr, key, mid + 1, right);
}

export {linearSearch ,binarySearch, recursiveBinarySearch};