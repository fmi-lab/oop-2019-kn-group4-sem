#ifndef RUNNINGAVERAGE_H
#define RUNNINGAVERAGE_H

template <typename T>
class RunningAverage
{

    public:
        RunningAverage(): currentAverage(), count() { }
        void addValue(const T& value) {
            this->currentAverage = (this->count * this->currentAverage + value) / (this->count + 1);
            this->count++;
        }
        T average() const {
            return this->currentAverage;
        }

    protected:

    private:
        T currentAverage;
        int count;
};

#endif // RUNNINGAVERAGE_H
