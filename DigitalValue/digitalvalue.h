#ifndef DIGITALVALUE_H
#define DIGITALVALUE_H


class DigitalValue
{
    public:
        DigitalValue(int value = -1);
        ~DigitalValue();

        bool hasChanged();
        static bool isDigital(int value);

        int getValue();
        void setValue(int value);

    private:
        int m_value;
        int m_previousValue;
};

#endif // DIGITALVALUE_H
