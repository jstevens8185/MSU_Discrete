//  main.cpp
//  Program3
//
//  Created by Jered Stevens on 11/8/22.
//
#include <ctime>
#include <cstdio>
#include <iostream>
#include <fstream>
#include "PrimeNumbers.hpp"

//for program a and b , make it run all the way to max instead of sqrt of max

void Seive(Number (&arr)[]);
void openFiles (std::ofstream& outfile);

const int MAX = 500;
int Number::totalPrimes = MAX;


int main() {
    std::ofstream output;
    std::clock_t start;
    double duration;
    openFiles(output);
    
    
    //Print Header
    output << "Jered Stevens" << std::endl;
    output << "Discrete Structures - Stringfellow" << std::endl;
    output << "Program 3A" << std::endl;
    output << "Date: 11/9/22" << std::endl<<std::endl;
    
    /**********Initialize Array********/
    Number primeArray[MAX];
    for(int i = 0; i < MAX; i++){
        primeArray[i].setNumber(i);
    }
    primeArray[0].setPrime(0);
    primeArray[1].setPrime(0);
    /******************************/
    
    /**********Start Clock********/
    start = std::clock();
    
    Seive(primeArray);
    
    /**********End Clock********/
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

    for(int i = 0; i < MAX; i++){
        if (primeArray[i].isPrime()){
            output << primeArray[i].getNumber() << " ";
            output << "is prime" << std::endl;
        }
    }
    
    output << "There are " << primeArray[0].getTotalPrimes()
        << " prime numbers from 1 to " << MAX << std::endl;
    output<<"Duration of code execution "<< duration <<'\n';

    return 0;
}





void Seive(Number (&arr)[]){
    for (int i = 2; i < MAX; i++){
        if(arr[i].isPrime()){
            for ( int j = i*2; j < MAX; j = j + i){
                arr[j].setPrime(0);
            }
        }
    }
};

void openFiles (std::ofstream& outfile)
{
    char outFileName[40];
    std::cout<<"Enter the output file name: ";
    std::cin>> outFileName;
    outfile.open(outFileName);

    return;
}

