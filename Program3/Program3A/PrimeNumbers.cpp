//
//  PrimeNumbers.cpp
//  Program3
//
//  Created by Jered Stevens on 11/8/22.
//

#include "PrimeNumbers.hpp"


    
    Number::Number(){
        number = 0;
        prime = 1;
    };
    Number::Number(int num, bool prime){
        number = num;
        prime = prime;
    }
    void Number::setNumber(int n){
        number = n;
    }
    int Number::getNumber(){
        return number;
    }
    void Number::setPrime(bool p){
        if (prime == false){
            return;
        }
        prime = p;
        if(p == 0){
            totalPrimes--;
        }
        return;
    }
    bool Number::isPrime(){
        return prime;
    }
    int Number::getTotalPrimes(){
        return totalPrimes;
    }
  
