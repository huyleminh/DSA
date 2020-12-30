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


export default class Sort {
    private static construcHeap<T> (arr: Array<T>, left: number, right: number): void {
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

    private static mergeTwoArray<T> (arr: Array<T>, left: number, mid: number, right: number): void {   
        let arrLeft = arr.slice(left, mid + 1);
        let arrRight = arr.slice(mid + 1, right + 1);
    
        for (let topLeft = 0, topRight = 0, i = left; i < right + 1; i++) {
            if (topLeft >= arrLeft.length) {
                arr[i] = arrRight[topRight++];
            } else if (topRight >= arrRight.length) {
                arr[i] = arrLeft[topLeft++];
            } else if (arrLeft[topLeft] < arrRight[topRight]) {
                arr[i] = arrLeft[topLeft++];
            } else {
                arr[i] = arrRight[topRight++];
            }
        }
    }

    private static partition<T> (arr: Array<T>, left:number, right: number): number {
        let pivot = arr[Math.floor((left + right) / 2)];
        let i = left - 1;
        let j = right + 1;

        while (i < j) {
            while(arr[++i] < pivot);
            while (arr[--j] > pivot);
            [arr[i], arr[j]] = [arr[j], arr[i]];
        }
        [arr[i], arr[j]] = [arr[j], arr[i]];
        return j;
    }

    private static sortRadixBins (arr: Array<number>, step: number): void {
        let bins: Array<Array<number>> = []
        for (let i = 1; i < 11; ++i) {
            bins.push([]);
        }

        for (let i = 0; i < arr.length; ++i) {
            let digit = Math.floor(arr[i] / Math.pow(10, step)) % 10;
            bins[digit].push(arr[i]);
        }
        
        arr.splice(0);
        for (let i = 0; i < 10; ++i) 
            arr.push(...bins[i]);
    }

    //------------------------------------------------------------------------------------------------------
    /**
     * @param arr: array list
     * @return sorted array
     */
    public static interchangeSort<T> (arr: Array<T>): void {
        for (let i = 0; i < arr.length - 1; ++i)
            for (let  j = i + 1; j < arr.length; ++j)
                if (arr[i] > arr[j])
                    [arr[i], arr[j]] = [arr[j], arr[i]];
    }

    /**
     * @param arr: array list
     * @return sorted array
     */
    public static selectionSort<T> (arr: Array<T>): void {
        for (let i = 0; i < arr.length - 1; ++i) {
            let min = i;
            for (let j = i + 1; j < arr.length; ++j) {
                if (arr[j] < arr[min])
                    min = j;
            }
            if (min !== i)
                [arr[i], arr[min]] = [arr[min], arr[i]]
        }
    }

    /**
     * @param arr: array list
     * @return sorted array
     */
    public static bubbleSort<T> (arr: Array<T>) : void {
        const n = arr.length;
        for (let i = 0; i < n; ++i)
            for (let j = n - 1; j > i; --j)
                if (arr[j] < arr[j - 1])
                    [arr[j], arr[j - 1]] = [arr[j - 1], arr[j]];
    }

    /**
     * @param arr: array list
     * @return sorted array
     */
    public static shakerSort<T> (arr: Array<T>): void {
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

    /**
     * @param arr: array list
     * @return sorted array
     */
    public static insertionSort<T> (arr: Array<T>): void {
        const n = arr.length;
        let j, temp;
        for (let i = 1; i < n; i++) {
            j = i - 1;
            temp = arr[i];
            while (j > -1 && temp < arr[j]) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = temp;  
        }
    }

    /**
     * @param arr: array list
     * @return sorted array
     */
    public static heapSort<T> (arr: Array<T>): void {
        let left = Math.floor(arr.length / 2) - 1;
        while (left > -1) {
            this.construcHeap(arr, left, arr.length - 1);
            left--;
        }
    
        let right = arr.length - 1;
        while (right > 0) {
            [arr[0], arr[right]] = [arr[right], arr[0]];
            right--;
            this.construcHeap(arr, 0, right);
        }
    }

    /**
     * @param arr: array list
     * @param left: 0
     * @param right: length - 1
     * @return sorted array
     */
    public static mergeSort<T> (arr: Array<T>, left: number, right: number): void {
        if (left >= right)
            return;
        
        let mid = Math.floor(left + (right - left) / 2);
        this.mergeSort(arr, left, mid);
        this.mergeSort(arr, mid + 1, right);
        
        this.mergeTwoArray(arr, left, mid, right);
    }

    /**
     * @param arr: array list
     * @param left: 0
     * @param right: length - 1
     * @return sorted array
     */
    public static quickSort<T> (arr: Array<T>, left: number, right: number): void {
        if (left >= right)
            return;
        let partition = this.partition(arr, left, right);
        this.quickSort(arr, left, partition);
        this.quickSort(arr, partition + 1, right);
    }

    /**
     * @param arr: array list
     * @return sorted array
     */
    public static radixSort (arr: Array<number>): void {
        let maxVal: number = arr[0];
        for (let i = 1; i < arr.length; ++i)
            if (maxVal < arr[i])
                maxVal = arr[i];
        
        const digits = Math.floor(Math.log10(maxVal)) + 1;
        
        for (let i = 0; i < digits; i++)
            this.sortRadixBins(arr, i);
    }
}