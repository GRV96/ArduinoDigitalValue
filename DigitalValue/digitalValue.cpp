#include "digitalValue.h"

#define DEFAULT -1
#define HIGH 1
#define LOW 0

DigitalValue::DigitalValue(int value) {
    m_nValue = isDigital(value)? value: DEFAULT;
    m_nPreviousValue = DEFAULT;
}

DigitalValue::~DigitalValue() {}

int DigitalValue::getOpposite() const {return getOppositeOf(m_nValue);}

int DigitalValue::getOppositeOf(int value) {
    switch(value) {
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

bool DigitalValue::isDigital(int value) {return value==LOW || value==HIGH;}

bool DigitalValue::isHigh() const {return m_nValue == HIGH;}

bool DigitalValue::isLow() const {return m_nValue == LOW;}

bool DigitalValue::isUndefined() const {return m_nValue == DEFAULT;}

bool DigitalValue::setValue(int value) {
    if(!isDigital(value)) {return false;}
    m_nPreviousValue = m_nValue;
    m_nValue = value;
    return true;
}
