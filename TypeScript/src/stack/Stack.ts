/**
 *
 * Stack.ts
 *
 * Created by Huy Le Minh on 2020-12-31
 *
 * Visit my github: https://github.com/huyleminh/
 * Contact me: leminhhuy.hcmus@gmail.com
 *
 *
 * File description: Implement Stack
*/


export default class Stack<T> {
    private _containner: T[];
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
        this._containner.pop();
        --this._elements;
    }

    public top = (): T | void => {
        if (this._elements === 0)
            return;
        return this._containner[this._elements - 1];
    }

    public size = (): number => {
        return this._elements;
    }

    public empty = (): boolean => {
        return (this._elements === 0) ? true : false;
    }

    public clearStack = (): void => {
        this._elements = 0;
        this._containner = []
    }
}