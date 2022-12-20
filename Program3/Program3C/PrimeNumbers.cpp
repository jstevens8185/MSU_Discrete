//
//  PrimeNumbers.cpp
//  Program3
//
//  Created by Jered Stevens on 11/8/22.
//

#include "PrimeNumbers.hpp"

///////////////////////////////////////////////////////////
///Constructors for struct Number
///////////////////////////////////////////////////////////

    Number::Number(){
        number = 0;
        prime = 1;
    };
    Number::Number(int num, bool prime){
        number = num;
        prime = prime;
    }

///////////////////////////////////////////////////////////
///Variable setters for Number struct
///////////////////////////////////////////////////////////
    
    void Number::setNumber(int n){
        number = n;
    }
    void Number::setPrime(bool p){
        if (prime == false){
            return;
        }
        prime = p;
    //        if(p == 0){
    //            totalPrimes--;
    //        }
        return;
    }

///////////////////////////////////////////////////////////
///Variable getters for Number struct
///////////////////////////////////////////////////////////
    int Number::getNumber(){
        return number;
    }

    bool Number::isPrime(){
        return prime;
    }


///////////////////////////////////////////////////////////
///Constructors for struct PrimesAndTime
///////////////////////////////////////////////////////////

    PrimesAndTime::PrimesAndTime(){
        totalPrimes = -1;
        duration = -1;
    }
    PrimesAndTime::PrimesAndTime(int p, double d){
        totalPrimes = p;
        duration = d;
    }
///////////////////////////////////////////////////////////
///Variable setters for PrimesAndTime struct
///////////////////////////////////////////////////////////
    void PrimesAndTime::setPrimes(int p){
        totalPrimes = p;
    }
    void PrimesAndTime::setDuration(double d){
        duration = d;
    }
///////////////////////////////////////////////////////////
///Variable getters for PrimesAndTime struct
///////////////////////////////////////////////////////////
    int PrimesAndTime::getPrimes(){
        return totalPrimes;
    }
    double PrimesAndTime::getDuration(){
        return duration;
    }
