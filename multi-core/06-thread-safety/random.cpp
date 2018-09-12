
//**********************************************************
// Pseudo random number generator:
//     double random
//     void seed (lower_limit, higher_limit)
//**********************************************************
//
// A simple linear congruential random number generator
// (Numerical Recipies chapter 7, 1st ed.) with parameters
// from the table on page 198j.
//
//  Uses a linear congruential generator to return a value between
//  0 and 1, then scales and shifts it to fill the desired range.  This
//  range is set when the random number generator seed is called.
// 
// USAGE:
//
//      pseudo random sequence is seeded with a range
//
//            void seed(lower_limit, higher_limit)
//   
//      and then subsequent calls to the random number generator generates values
//      in the sequence:
//
//            double drandom()
//
// History: 
//      Written by Tim Mattson, 9/2007.
//      changed to drandom() to avoid collision with standard libraries, 11/2011

#include "random.h"
#include <cstdio>
#include <omp.h>

Random::Random(long mult, long pmod) : 
    mult(mult),
    pmod(pmod){
    
    random_global global = init(mult, pmod);
    printf("INIT id:%d, mult=%li, pmod=%li\n", omp_get_thread_num(), global.MULTIPLIER, global.PMOD);

}

random_global Random::init (long mult, long pmod){
    random_global global;
    global.MULTIPLIER = mult;
    global.ADDEND = 0;
    global.PMOD = pmod;
    global.random_last = 0;

    return global;
}

long long Random::drandom()
{
    long long random_next;
    long long ret_val;

    
// 
// compute an integer random number from zero to mod
//
    printf("RANDOM id:%d, mult=%li, pmod=%li\n", omp_get_thread_num(), global.MULTIPLIER, global.PMOD);
    random_next = ((global.MULTIPLIER  * global.random_last + global.ADDEND)% global.PMOD);
    global.random_last = random_next;

//
// shift into preset range
//
    ret_val = ((double)random_next/(double)global.PMOD)*(global.random_hi-global.random_low)+global.random_low;
    return ret_val;
}
//
// set the seed and the range
//
void Random::seed(double low_in, double hi_in)
{
   if(low_in < hi_in)
   { 
      global.random_low = low_in;
      global.random_hi  = hi_in;
   }
   else
   {
      global.random_low = hi_in;
      global.random_hi  = low_in;
   }
   global.random_last = 1;  // just pick something

}
//**********************************************************
// end of pseudo random generator code.
//**********************************************************

