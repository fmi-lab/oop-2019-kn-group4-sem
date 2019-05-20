#ifndef FIBONACCI_H
#define FIBONACCI_H

#include "Sequence.h"


class Fibonacci : public Sequence<int>
{
    public:
        Fibonacci(): value1(1), value2(1) {}
        virtual ~Fibonacci() {}
        virtual int getNth(int n) const
        {
            // TODO: calculate the n-th number
            return 0;
        }
        virtual int next()
        {
            value2 = value1 + value2;
            value1 = value2 - value1;
            return value1;
        }

    protected:

    private:
        int value1;
        int value2;
};

#endif // FIBONACCI_H
