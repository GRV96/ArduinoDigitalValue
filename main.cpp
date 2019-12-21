#include <iostream>

#include "digitalValue.h"
#include "tests/digitalValueTests.h"

using namespace std;

int main() {
    testAll();

    DigitalValue oDv1(19);
    cout << "oDv1: " << oDv1.getValue() << endl;

    DigitalValue oDv2(0);
    cout << "oDv2: " << oDv2.getValue() << endl;

    DigitalValue oDv3(1);
    cout << "oDv3: " << oDv3.getValue() << endl;

    return EXIT_SUCCESS;
}
