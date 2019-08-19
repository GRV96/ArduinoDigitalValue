#include <assert.h>

#include "digitalvalue.h"
#include "digitalValuetests.h"

void testAll()
{
    testIsDigitalValue();
    testConstructorAndAccessor();
    testMutatorAndAccessor();
    testHasChanged();
}

void testConstructorAndAccessor()
{
    DigitalValue dv1(-2);
    DigitalValue dv2; //m_value = -1
    DigitalValue dv3(0);
    DigitalValue dv4(1);
    DigitalValue dv5(2);
    assert(dv1.getValue()==-1);
    assert(dv2.getValue()==-1);
    assert(dv3.getValue()==0);
    assert(dv4.getValue()==1);
    assert(dv5.getValue()==-1);
}

void testMutatorAndAccessor()
{
    DigitalValue dv;
    assert(!dv.setValue(-2));
    assert(dv.getValue()==-1);
    assert(dv.setValue(0));
    assert(dv.getValue()==0);
    assert(dv.setValue(1));
    assert(dv.getValue()==1);
    assert(!dv.setValue(2));
    assert(dv.getValue()==1); //1 is the last valid value recorded.
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
