/* Copyright (c) 2019  Guyllaume Rousseau
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is furnished to do
 * so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef DIGITALVALUE_H
#define DIGITALVALUE_H

class DigitalValue {
    private:
        int m_nValue;
        int m_nPreviousValue;

    public:
        DigitalValue(int nValue=-1);
        ~DigitalValue();
        int getOpposite() const;
        static getOppositeOf(int nValue);
        int getValue() const;
        bool hasChanged() const;
        static bool isDigital(int nValue);
        bool isHigh() const;
        bool isLow() const;
        bool isUndefined() const;
        bool setValue(int nValue);
        void switchValue();

    private:
        void setValueNoCheck(int nValue);
};

#endif // DIGITALVALUE_H
