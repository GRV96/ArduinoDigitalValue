#include "digitalvalue.h"

#define HIGH 1
#define LOW 0

using namespace std;

DigitalValue::DigitalValue()
{
    m_value = -1;
    m_previousValue = -1;
}

DigitalValue::~DigitalValue() {}

int DigitalValue::getValue() {return m_value;}

void DigitalValue::setValue(int value)
{
    m_previousValue = m_value;
    m_value = value;
}
