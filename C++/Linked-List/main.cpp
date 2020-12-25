#include "Node.h"
#include "./LinkedList.h"

int main() {
    LinkedList<int> a;

    a.push(1);
    a.push(2);
    a.push(3);

    a.shift();

    return 0;
}