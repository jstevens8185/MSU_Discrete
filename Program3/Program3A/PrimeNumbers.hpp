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
    static int totalPrimes;
public:
    
    Number();
    Number(int num, bool prime);
    void setNumber(int n);
    int getNumber();
    void setPrime(bool p);
    bool isPrime();
    int getTotalPrimes();
};

#endif /* PrimeNumbers_hpp */
