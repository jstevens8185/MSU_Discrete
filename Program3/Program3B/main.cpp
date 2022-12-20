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

PrimesAndTime Seive(Number (&arr)[], int MAX);
void openFiles (std::ofstream& outfile);
void printResults (std::ofstream& output, int MAX, PrimesAndTime& results);

const int FIVE000 = 5000;
const int FIFTY000 = 50000;
const int HUNDRED000 = 100000;



int main() {
    std::ofstream output;
    openFiles(output);
    PrimesAndTime primeTime;
    
    
    //Print Header
    output << "Jered Stevens" << std::endl;
    output << "Discrete Structures - Stringfellow" << std::endl;
    output << "Program 3B" << std::endl;
    output << "Date: 11/9/22" << std::endl;
    
    //For 1st case, process 5000 elements
    //For 2nd case, process 50000 elements
    //For 3rd case, process 100000 elements
    for (int n = 0; n < 3; n++){
        switch (n) {
            case 0: {
                /**********Initialize Array********/
                Number primeArray[FIVE000];
                for(int i = 0; i < FIVE000; i++){
                    primeArray[i].setNumber(i);
                }
                primeArray[0].setPrime(0);
                primeArray[1].setPrime(0);
                /******************************/

                
                primeTime = Seive(primeArray, FIVE000);
                

//                for(int i = 0; i < FIVE000; i++){
//                    if (primeArray[i].isPrime()){
//                        output << primeArray[i].getNumber() << " ";
//                        output << "is prime" << std::endl;
//                    }
//                }
                
                printResults(output, FIVE000, primeTime);
                
                break;
            }
                
            case 1: {
                /**********Initialize Array********/
                Number primeArray[FIFTY000];
                for(int i = 0; i < FIFTY000; i++){
                    primeArray[i].setNumber(i);
                }
                
                primeArray[0].setPrime(0);
                primeArray[1].setPrime(0);
                /******************************/
                
                primeTime = Seive(primeArray, FIFTY000);
                
//                for(int i = 0; i < FIFTY000; i++){
//                    if (primeArray[i].isPrime()){
//                        output << primeArray[i].getNumber() << " ";
//                        output << "is prime" << std::endl;
//                    }
//                }
                
                printResults(output, FIFTY000, primeTime);
               
                break;
            }
            case 2: {
                /**********Initialize Array********/
                Number primeArray[HUNDRED000];
                for(int i = 0; i < HUNDRED000; i++){
                    primeArray[i].setNumber(i);
                }
                primeArray[0].setPrime(0);
                primeArray[1].setPrime(0);
                /******************************/
                
                primeTime = Seive(primeArray, HUNDRED000);
                

//                for(int i = 0; i < HUNDRED000; i++){
//                    if (primeArray[i].isPrime()){
//                        output << primeArray[i].getNumber() << " ";
//                        output << "is prime" << std::endl;
//                    }
//                }
                
                printResults(output, HUNDRED000, primeTime);

                break;
            }
            default:
                break;
        }

    }
    return 0;
}





PrimesAndTime Seive(Number (&arr)[], int MAX){
    //totalPrimes starts as max minus
    //digits 1 and 2
    int totalPrimes = MAX - 2;
    std::clock_t start;
    double duration;
    PrimesAndTime x;
    
    /**********Start Clock********/
    start = std::clock();
    for (int i = 2; i < MAX; i++){
        if(arr[i].isPrime()){
            for ( int j = i*2; j < MAX; j = j + i){
                if(arr[j].isPrime()){
                    totalPrimes--;
                    arr[j].setPrime(0);
                }
            }
        }
    }
    /**********End Clock********/
    duration = (std::clock() - start ) / (double) CLOCKS_PER_SEC;
    
    x.setPrimes(totalPrimes);
    x.setDuration(duration);
    return x;
    
};


void openFiles (std::ofstream& outfile)
{
    char outFileName[40];
    std::cout<<"Enter the output file name: ";
    std::cin>> outFileName;
    outfile.open(outFileName);

    return;
}

void printResults (std::ofstream& output, int MAX, PrimesAndTime& results){
    output << "There are " << results.getPrimes()
    << " prime numbers from 1 to " << MAX << std::endl;
    output << "Duration of code execution "
    << results.getDuration() << " seconds" << '\n' << '\n';
};
