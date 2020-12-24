/**
 * Test for Binary search tree runs here
*/

#include "BST.h"

int main() {
    BST<int> root(0);

    root.insert(5);
    root.insert(6);
    root.insert(2);
    root.insert(1);
    root.insert(4);
    root.insert(3);
    root.insert(7);

    cout << "Pre-order: ";
    root.preOrderTraversal();
    cout << endl;

    cout << root.search(2) << endl;
    cout << root.search(8) << endl;
    cout << root.search(0) << endl;

    cout << endl;
    root.removeNode(7);
    cout << "Pre-order: ";
    root.preOrderTraversal();
    cout << endl;

    return 0;
}