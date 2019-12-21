#include <iostream>

#include "digitalValue.h"
#include "tests/digitalValueTests.h"

using namespace std;

int main() {
    testAll();

    DigitalValue dv1(19);
    cout << "dv1: " << dv1.getValue() << endl;

    DigitalValue dv2(0);
    cout << "dv2: " << dv2.getValue() << endl;

    DigitalValue dv3(1);
    cout << "dv3: " << dv3.getValue() << endl;

    return EXIT_SUCCESS;
}
