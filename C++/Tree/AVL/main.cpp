/**
 * Test for Balance binary search tree runs here
*/

#include <iostream>
#include "AVL.h"
using namespace std;

int main() {
    AVL<int> avl(0);
    
    cout << "Create: " << endl;
    avl.insert(1);
    avl.inOrderTraversal();
    cout << endl;

    avl.insert(2);
    avl.inOrderTraversal();
    cout << endl;

    avl.insert(3);
    avl.inOrderTraversal();
    cout << endl;

    avl.insert(4);
    avl.inOrderTraversal();
    cout << endl;

    avl.insert(5);
    avl.inOrderTraversal();
    cout << endl;

    cout << endl << "Search: " << endl;
    cout << avl.search(5) << endl;
    cout << avl.search(6) << endl;
    cout << avl.search(-1) << endl;

    cout << endl << "Remove: " << endl;
    avl.removeNode(3);
    avl.inOrderTraversal();
    cout << endl;

    return 0;
}