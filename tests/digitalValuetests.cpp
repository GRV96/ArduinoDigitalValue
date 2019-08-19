#include <assert.h>

#include "digitalvalue.h"
#include "digitalValuetests.h"

void testAll()
{
    testConstructorAndAccessor();
    testHasChanged();
    testIsDigitalValue();
}

void testConstructorAndAccessor()
{
    DigitalValue dv1;
    DigitalValue dv2(0);
    DigitalValue dv3(1);
    assert(dv1.getValue()==-1);
    assert(dv2.getValue()==0);
    assert(dv3.getValue()==1);
}

void testHasChanged()
{
    DigitalValue dv1;
    assert(!dv1.hasChanged());
    dv1.setValue(0);
    assert(dv1.hasChanged());

    DigitalValue dv2(1);
    assert(dv2.hasChanged());
}

void testIsDigitalValue()
{
    assert(!DigitalValue::isDigital(-1));
    assert(DigitalValue::isDigital(0));
    assert(DigitalValue::isDigital(1));
    assert(!DigitalValue::isDigital(2));
}
