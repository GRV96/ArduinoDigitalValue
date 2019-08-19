#include "digitalvalue.h"

#define HIGH 1
#define LOW 0

DigitalValue::DigitalValue(int value)
{
    m_value = value;
    m_previousValue = -1;
}

DigitalValue::~DigitalValue() {}

bool DigitalValue::hasChanged() {return m_value!=m_previousValue;}

bool DigitalValue::isDigital(int value) {return value==LOW || value==HIGH;}

int DigitalValue::getValue() {return m_value;}

void DigitalValue::setValue(int value)
{
    m_previousValue = m_value;
    m_value = value;
}
