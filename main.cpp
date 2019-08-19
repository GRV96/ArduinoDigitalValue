#include <iostream>

#include "digitalvalue.h"

using namespace std;

int main()
{
    DigitalValue dg;
    cout << "Inital value: " << dg.getValue() << endl;

    dg.setValue(7);
    cout << "New value: " << dg.getValue() << endl;

    return EXIT_SUCCESS;
}
