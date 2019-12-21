#include <assert.h>

#include "digitalValue.h"
#include "digitalValueTests.h"

void testAll() {
    testIsDigitalValue();
    testConstructorAndAccessor();
    testMutatorAndAccessor();
    testGetOpposite();
    testHasChanged();
}

void testIsDigitalValue() {
    assert(!DigitalValue::isDigital(-1));
    assert(DigitalValue::isDigital(0));
    assert(DigitalValue::isDigital(1));
    assert(!DigitalValue::isDigital(2));
}

void testConstructorAndAccessor() {
    DigitalValue dv1(-2);
    DigitalValue dv2; //m_value = -1
    DigitalValue dv3(0);
    DigitalValue dv4(1);
    DigitalValue dv5(2);
    assert(dv1.getValue() == -1);
    assert(dv2.getValue() == -1);
    assert(dv3.getValue() == 0);
    assert(dv4.getValue() == 1);
    assert(dv5.getValue() == -1);
}

void testMutatorAndAccessor() {
    DigitalValue dv;
    assert(!dv.setValue(-2));
    assert(dv.getValue() == -1);
    assert(!dv.setValue(-1));
    assert(dv.getValue() == -1);
    assert(dv.setValue(0));
    assert(dv.getValue() == 0);
    assert(dv.setValue(1));
    assert(dv.getValue() == 1);
    assert(!dv.setValue(2));
    assert(dv.getValue() == 1); //1 is the last valid value recorded.
}

void testGetOpposite() {
    assert(DigitalValue::getOppositeOf(-1) == -1);
    assert(DigitalValue::getOppositeOf(0) == 1);
    assert(DigitalValue::getOppositeOf(1) == 0);
    assert(DigitalValue::getOppositeOf(2) == -1);
    DigitalValue dv1;
    DigitalValue dv2(0);
    DigitalValue dv3(1);
    assert(dv1.getOpposite() == -1);
    assert(dv2.getOpposite() == 1);
    assert(dv3.getOpposite() == 0);
}

void testHasChanged() {
    DigitalValue dv1;
    assert(!dv1.hasChanged());
    dv1.setValue(0);
    assert(dv1.hasChanged());

    DigitalValue dv2(1);
    assert(dv2.hasChanged());
}

void testIsHigh() {
    DigitalValue dv1; //m_value = -1
    DigitalValue dv2(0);
    DigitalValue dv3(1);
    assert(!dv1.isHigh());
    assert(!dv2.isHigh());
    assert(dv3.isHigh());
}

void testIsLow() {
    DigitalValue dv1; //m_value = -1
    DigitalValue dv2(0);
    DigitalValue dv3(1);
    assert(!dv1.isLow());
    assert(dv2.isLow());
    assert(!dv3.isLow());
}

void testIsUndefined() {
    DigitalValue dv1; //m_value = -1
    DigitalValue dv2(0);
    DigitalValue dv3(1);
    assert(dv1.isUndefined());
    assert(!dv2.isUndefined());
    assert(!dv3.isUndefined());
}
