#ifndef RANDOM_H
#define RANDOM_H

typedef struct random_global_ random_global;

struct random_global_ {
    long MULTIPLIER;
    long ADDEND;
    long PMOD;
    long long random_last;
    double random_low, random_hi;
};

class Random
{
public:
    double mult, pmod;
    Random(long mult, long pmod);
    long long drandom();
    void seed(double low_in, double hi_in);
    random_global init (long mult, long pmod);
private:
    random_global global;

};

#endif