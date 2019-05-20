#ifndef SEQUENCE_H
#define SEQUENCE_H

template <typename T>
class Sequence
{
    public:
        Sequence() {}
        virtual ~Sequence() {}
        virtual T getNth(int n) const = 0;
        virtual T next() = 0;
    protected:

    private:
};

#endif // SEQUENCE_H
