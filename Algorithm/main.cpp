#include <iostream>
#include "recursion.h"

int main() {
    int A[10]={2,4,5,1,6,7,3,1,7,9};
    cout << maxRec(A,10) << endl;
    int list[] = {1,2,3,4,5,6};
    Perm(list,0,3);
    return 0;
}