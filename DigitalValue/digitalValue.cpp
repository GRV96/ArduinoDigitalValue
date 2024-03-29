#include "digitalValue.h"

#define DEFAULT -1
#define HIGH 1
#define LOW 0

DigitalValue::DigitalValue(int nValue) {
    m_nValue = isDigital(nValue)? nValue: DEFAULT;
    m_nPreviousValue = DEFAULT;
}

DigitalValue::~DigitalValue() {}

int DigitalValue::getOpposite() const {return getOppositeOf(m_nValue);}

int DigitalValue::getOppositeOf(int nValue) {
    switch(nValue) {
    case HIGH:
        return LOW;
    case LOW:
        return HIGH;
    default:
        return DEFAULT;
    }
}

int DigitalValue::getValue() const {return m_nValue;}

bool DigitalValue::hasChanged() const {return m_nValue != m_nPreviousValue;}

bool DigitalValue::isDigital(int nValue) {return nValue==LOW || nValue==HIGH;}

bool DigitalValue::isHigh() const {return m_nValue == HIGH;}

bool DigitalValue::isLow() const {return m_nValue == LOW;}

bool DigitalValue::isUndefined() const {return m_nValue == DEFAULT;}

bool DigitalValue::setValue(int nValue) {
    if(!isDigital(nValue)) {return false;}
    setValueNoCheck(nValue);
    return true;
}

void DigitalValue::setValueNoCheck(int nValue) {
    m_nPreviousValue = m_nValue;
    m_nValue = nValue;
}

void DigitalValue::switchValue() {
    setValueNoCheck(getOpposite());
}
