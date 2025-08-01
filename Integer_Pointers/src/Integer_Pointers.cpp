#include <iostream>
using namespace std;

int main() {
    int a, b, c;

    cout << "Enter integer #1: ";
    cin >> a;
    cout << "Enter integer #2: ";
    cin >> b;
    cout << "Enter integer #3: ";
    cin >> c;

    int* ptrA = new int;
    int* ptrB = new int;
    int* ptrC = new int;

    *ptrA = a;
    *ptrB = b;
    *ptrC = c;

    cout << "\nStored Values:\n";
    cout << "Variable a = " << a << ", Pointer *ptrA = " << *ptrA << endl;
    cout << "Variable b = " << b << ", Pointer *ptrB = " << *ptrB << endl;
    cout << "Variable c = " << c << ", Pointer *ptrC = " << *ptrC << endl;

    delete ptrA;
    delete ptrB;
    delete ptrC;

    return 0;
}
