#include <iostream>
#include <string>
using namespace std;

int main() {
    string car1, car2, combined;

    for (int i = 1; i <= 3; i++) {
        cout << "Enter hypercar name #" << i << " (first one): ";
        getline(cin, car1);

        cout << "Enter hypercar name #" << i << " (second one): ";
        getline(cin, car2);

        combined = car1 + " " + car2;

        cout << "Combined name #" << i << ": " << combined << endl << endl;
    }

    return 0;
}
