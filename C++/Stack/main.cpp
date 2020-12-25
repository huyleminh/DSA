#include "Stack.h"

int main() {
    Stack<int> st;

    st.push(1);
    st.push(2);

    st.print();

    st.push(5);
    st.push(7);
    st.push(6);
    st.pop();
    st.print();

    int a = st.top();
    cout << a;
    
    return 0;
}