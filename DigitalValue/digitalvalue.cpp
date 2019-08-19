#include "digitalvalue.h"

#define DEFAULT -1
#define HIGH 1
#define LOW 0

DigitalValue::DigitalValue(int value)
{
    m_value = isDigital(value)? value: DEFAULT;
    m_previousValue = DEFAULT;
}

DigitalValue::~DigitalValue() {}

bool DigitalValue::hasChanged() const {return m_value!=m_previousValue;}

bool DigitalValue::isDigital(int value) {return value==LOW || value==HIGH;}

bool DigitalValue::isHigh() const {return m_value==HIGH;}

bool DigitalValue::isLow() const {return m_value==LOW;}

bool DigitalValue::isUndefined() const {return m_value==DEFAULT;}

int DigitalValue::getOpposite() const
{
    switch(m_value)
    {
    case HIGH:
        return LOW;
    case LOW:
        return HIGH;
    default:
        return DEFAULT;
    }
}

int DigitalValue::getValue() const {return m_value;}

bool DigitalValue::setValue(int value)
{
    if(!isDigital(value)) {return false;}
    m_previousValue = m_value;
    m_value = value;
    return true;
}
