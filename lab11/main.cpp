#include <iostream>
#include "RunningAverage.h"
#include "Sequence.h"
#include "ConstantSequence.h"
#include "ArithmeticProgression.h"
#include <vector>
using namespace std;

struct Rational {
    int x;
    int y;
};
int main()
{
    RunningAverage<double> ra;
    ra.addValue(5.5);
    cout << ra.average() << endl;

    Sequence<int>* s = new ConstantSequence<int>(7);
    cout << s->next() << endl;
    cout << s->next() << endl;
    cout << s->next() << endl;

    std::vector<Sequence<double>*> seqs;
    seqs.push_back(new ArithmeticProgression<double>(2.5, 2.5));
    seqs[0]->next();
    delete seqs[0];
    delete s;
    return 0;
}
