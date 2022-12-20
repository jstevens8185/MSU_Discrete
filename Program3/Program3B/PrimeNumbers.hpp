//
//  PrimeNumbers.hpp
//  Program3
//
//  Created by Jered Stevens on 11/8/22.
//

#ifndef PrimeNumbers_hpp
#define PrimeNumbers_hpp

#include <stdio.h>



struct Number{
private:
    int number;
    bool prime;
    
public:
    static int totalPrimes;
    Number();
    Number(int num, bool prime);
    void setNumber(int n);
    int getNumber();
    void setPrime(bool p);
    bool isPrime();
//    int getTotalPrimes();
//    void setTotalPrimes(int n);
};

struct PrimesAndTime{
    int totalPrimes;
    double duration;
    PrimesAndTime();
    PrimesAndTime(int p, double d);
    void setPrimes(int p);
    void setDuration(double d);
    int getPrimes();
    double getDuration();
    
};
#endif /* PrimeNumbers_hpp */
