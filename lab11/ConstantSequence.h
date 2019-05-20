#ifndef CONSTANTSEQUENCE_H
#define CONSTANTSEQUENCE_H

#include "Sequence.h"

template <typename T>
class ConstantSequence : public Sequence<T>
{
    public:
        ConstantSequence(const T& value): value(value) {}
        virtual ~ConstantSequence() {}
        virtual T getNth(int n) const
        {
            return value;
        }
        virtual T next()
        {
            return value;
        }
    protected:

    private:
        T value;
};

#endif // CONSTANTSEQUENCE_H
