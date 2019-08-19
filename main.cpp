#include <iostream>

#include "digitalvalue.h"
#include "tests/digitalValuetests.h"

using namespace std;

int main()
{
    testAll();

    DigitalValue dv1;
    cout << "Inital value: " << dv1.getValue() << endl;

    DigitalValue dv2(7);
    cout << "New value: " << dv2.getValue() << endl;

    return EXIT_SUCCESS;
}
