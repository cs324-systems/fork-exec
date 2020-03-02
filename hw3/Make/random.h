/*
 *  Class Random implements two functions for sampling
 *  random ints and doubles.
 */
 #ifndef RANDOM_H
 #define RANDOM_H

class Random {
  public:
    // returns a random floating point number
    // uniformly distributed in the interval [0,1]
    static double uniform_double ();

    // returns a random integer uniformly distributed
    // in the interval [0, n-1]
    static int uniform_int (int n);
};

#endif
