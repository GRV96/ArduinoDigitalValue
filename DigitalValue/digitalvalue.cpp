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

bool DigitalValue::hasChanged() {return m_value!=m_previousValue;}

bool DigitalValue::isDigital(int value) {return value==LOW || value==HIGH;}

int DigitalValue::getValue() {return m_value;}

bool DigitalValue::setValue(int value)
{
    if(!isDigital(value)) {return false;}
    m_previousValue = m_value;
    m_value = value;
    return true;
}
