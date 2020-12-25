#include "Queue.h"

int main() {
    Queue<int> q;

    q.push(1);
    q.push(2);

    q.print();

    q.push(5);
    q.push(7);
    q.push(6);
    q.shift();
    q.print();

    int a = q.deQueue();
    cout << a;
    
    return 0;
}