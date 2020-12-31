/**
 *
 * Queue.ts
 *
 * Created by Huy Le Minh on 2020-12-31
 *
 * Visit my github: https://github.com/huyleminh/
 * Contact me: leminhhuy.hcmus@gmail.com
 *
 *
 * File description: Implement Queue
*/

export default class Queue<T> {
    private _containner: T[] = []
    private _elements: number;

    constructor(...items: T[]) {
        if (items.length === 0) {
            this._containner = [];
            this._elements = 0;       
        }
        else {
            this._containner = items;
            this._elements = items.length;
        }
    }

    public push = (...items: T[]): void => {
        this._containner.push(...items);
        this._elements += items.length;
    }  

    public pop = (): void => {
        if (this.empty())
            return;
        this._containner.shift();
        --this._elements;
    }

    public front = (): T | void => {
        if (this._elements === 0)
            return;
        return this._containner[0];
    }

    public size = (): number => {
        return this._elements;
    }

    public empty = (): boolean => {
        return (this._elements === 0) ? true : false;
    }

    public clearQueue = (): void => {
        this._elements = 0;
        this._containner = []
    }
}