#ifndef ARITHMETICPROGRESSION_H
#define ARITHMETICPROGRESSION_H

#include "Sequence.h"

template <typename T>
class ArithmeticProgression : public Sequence<T>
{
    public:
        ArithmeticProgression(const T& initial, const T& diff): initialValue(initial), diff(diff), currentValue(initialValue) {}
        virtual ~ArithmeticProgression() {}
        virtual T getNth(int n) const
        {
            return initialValue + (n - 1) * diff;
        }
        virtual T next()
        {
            T oldValue = currentValue;
            currentValue = currentValue + diff;
            return oldValue;
        }
    protected:

    private:
        T  initialValue;
        T diff;
        T currentValue;
};

#endif // ARITHMETICPROGRESSION_H
