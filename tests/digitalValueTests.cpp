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
    DigitalValue oDv1(-2);
    DigitalValue oDv2; //m_nValue = -1
    DigitalValue oDv3(0);
    DigitalValue oDv4(1);
    DigitalValue oDv5(2);
    assert(oDv1.getValue() == -1);
    assert(oDv2.getValue() == -1);
    assert(oDv3.getValue() == 0);
    assert(oDv4.getValue() == 1);
    assert(oDv5.getValue() == -1);
}

void testMutatorAndAccessor() {
    DigitalValue oDv; //m_nValue = -1
    assert(!oDv.setValue(-2));
    assert(oDv.getValue() == -1);
    assert(!oDv.setValue(-1));
    assert(oDv.getValue() == -1);
    assert(oDv.setValue(0));
    assert(oDv.getValue() == 0);
    assert(oDv.setValue(1));
    assert(oDv.getValue() == 1);
    assert(!oDv.setValue(2));
    assert(oDv.getValue() == 1); //1 is the last valid value recorded.
}

void testGetOpposite() {
    assert(DigitalValue::getOppositeOf(-1) == -1);
    assert(DigitalValue::getOppositeOf(0) == 1);
    assert(DigitalValue::getOppositeOf(1) == 0);
    assert(DigitalValue::getOppositeOf(2) == -1);
    DigitalValue oDv1; //m_nValue = -1
    DigitalValue oDv2(0);
    DigitalValue oDv3(1);
    assert(oDv1.getOpposite() == -1);
    assert(oDv2.getOpposite() == 1);
    assert(oDv3.getOpposite() == 0);
}

void testHasChanged() {
    DigitalValue oDv1; //m_nValue = -1
    assert(!oDv1.hasChanged());
    oDv1.setValue(0);
    assert(oDv1.hasChanged());

    DigitalValue oDv2(1);
    assert(oDv2.hasChanged());
}

void testIsHigh() {
    DigitalValue oDv1; //m_nValue = -1
    DigitalValue oDv2(0);
    DigitalValue oDv3(1);
    assert(!oDv1.isHigh());
    assert(!oDv2.isHigh());
    assert(oDv3.isHigh());
}

void testIsLow() {
    DigitalValue oDv1; //m_nValue = -1
    DigitalValue oDv2(0);
    DigitalValue oDv3(1);
    assert(!oDv1.isLow());
    assert(oDv2.isLow());
    assert(!oDv3.isLow());
}

void testIsUndefined() {
    DigitalValue oDv1; //m_nValue = -1
    DigitalValue oDv2(0);
    DigitalValue oDv3(1);
    assert(oDv1.isUndefined());
    assert(!oDv2.isUndefined());
    assert(!oDv3.isUndefined());
}

void testSwitching(){
    DigitalValue oDv1; //m_nValue = -1
    DigitalValue oDv2(0);
    DigitalValue oDv3(1);
    oDv1.switchValue();
    oDv2.switchValue();
    oDv3.switchValue();
    assert(oDv1.getValue() == -1);
    assert(oDv2.getValue() == 1);
    assert(oDv3.getValue() == 0);
}
