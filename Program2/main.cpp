/****************************************************
 *  Author:           Jered Stevens
 *
 *  Course:         Discrete Structures
 *                  MWF 10AM
 *                  Stringfellow
 *
 *  File:           main.cpp
 *
 *  Description:    This program finds the max number of cycles
 *             and the sum of all the numbers
 *             in the sequence.
 *
 *  Date:           10/11/22
 **************************************************/
#include <fstream>
#include <iostream>
#include "Sequence.h"

using namespace std;

int main() {
    ifstream input;
    ofstream output;
    int k = -1;
    int l = -1;
    int maxCount = 0;
    int maxSum = 0;
    char userChoice = ' ';
    
//Main Loop
    while(userChoice != 'n'){
        openFiles(input, output);
        printHeader(output);
        output << endl << endl;

        printTopRow(output);

        input >> k;
        input >> l;
                
        calcMax(k, l, maxCount,
                maxSum, input, output);
        
        input.close();
        output.close();
        
        userChoice = ' ';
        while(userChoice != 'y' && userChoice != 'n'){
            cout << "Would you like to run another file? (y/n)" << endl;
            cin >> userChoice;
            userChoice = (char) tolower(userChoice);
        }
    }
}
