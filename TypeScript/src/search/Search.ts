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


export default class Search {

    /**
     * @param arr: array list
     * @param key: key to search
     * @return index founded or -1
     */
    public static linearSearch<T> (arr: Array<T>, key: T): number {
        for (let i = 0; i < arr.length; i++)
            if (arr[i] === key)
                return i;
        return -1;
    }

    /**
     * @param arr: array list
     * @param key: key to search
     * @return index founded or -1
     */
    public static binarySearch<T> (arr: Array<T>, key: T): number {
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

    /**
     * @param arr: array list
     * @param key: key to search
     * @param left: left index
     * @param right: right index
     * @return index founded or -1
     */
    public static recursiveBinarySearch<T> (arr: Array<T>, key: T, left: number, right: number): number {
        if (right < left)
            return -1;
        let mid = Math.floor((left + right) / 2);
        if (arr[mid] === key)
            return mid;
        return (arr[mid] > key) ? this.recursiveBinarySearch(arr, key, left, mid - 1) : this.recursiveBinarySearch(arr, key, mid + 1, right);
    }
}
