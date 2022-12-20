/****************************************************
 *  Author:           Jered Stevens
 *
 *  Course:         Discrete Structures
 *                  MWF 10AM
 *                  Stringfellow
 *
 *  File:           Sequence.cpp
 *
 *  Description:    This is the implementation file
 *                  to be used in conjunction with
 *                  Sequence.h.
 *
 *  Date:           10/11/22
 ***************************************************/
#include "Sequence.h"
#include <stdio.h>


/****************************************************************
 *          Open Files Function
 *  Name:   openFiles(ifstream&, ofStream&)
 *
 *  Args:   ifstream& infile, ofstream& outfile
 *
 *  Rtrn:   void
 *
 *  Func:   Opens input and output files of users choice
 *
 *  Logic:  Declare char arrays to hold user specified
 *          input and output file names. Get names from user.
 *          Open files
 ****************************************************************/

void openFiles (ifstream& infile, ofstream& outfile)
{
    char inFileName[40];
    char outFileName[40];
    cout<<"Enter the input file name: ";
    cin>>inFileName;
    infile.open(inFileName);
    cout<<"Enter the output file name: ";
    cin>> outFileName;
    outfile.open(outFileName);

    return;
}


/****************************************************************
 *          Check Order Function
 *  Name:   checkOrder(int& k, int& l, int& temp1)
 *
 *  Args:   int& k, int& l, int& temp1
 *
 *  Rtrn:   void
 *
 *  Func:   Checks the order of the input. If not in ascending order, swaps them
 *
 *  Logic:  Check if k is smaller or equal to l. If it is, leave it alone.
 *       If not, swap k and l so that they are in the correct order
 ****************************************************************/

void checkOrder(int& k, int& l, int& temp1){
    if(k <= l){
        temp1 = k;
    }else{
        temp1 = l;
        l = k;
        k = temp1;
    }
    return;
};


/****************************************************************
 *          Print Top Row Function
 *  Name:   printBitwiseTable1(ofstream& output)
 *
 *  Args:   ofstream& output
 *
 *  Rtrn:   void
 *
 *  Func:   Prints the label row of the table
 ****************************************************************/

void printTopRow(ofstream& output){
    output << setw(10) << "n"
           << setw(10) << "m"
           << setw(10) << "max"
           << setw(10) << "sum" << endl;

    return;
};

/****************************************************************
 *          Print Bitwise Table 1 Function
 *  Name:   printHeader(ofstream& output)
 *
 *  Args:   ofstream& output
 *
 *  Rtrn:   void
 *
 *  Func:   Prints Header
 ****************************************************************/

void printHeader(ofstream& output){
    output << "Jered Stevens" << endl;
    output << "Discrete Structures - Stringfellow" << endl;
    output << "Program 2: Sequences" << endl;
    output << "Date: 10/11/22" << endl;
    
    return;
}


/****************************************************************
 *          Calculate Max Values Function
 *  Name:   calcMax(int&, int&, int&, int&, ifstream&, ofstream&)
 *
 *  Args:   int& k, int& l, int& maxCount,
 *       int& maxSum, ifstream& input, ofstream& output
 *
 *  Rtrn:   void
 *
 *  Func:   Loops through 2 numbers at a time in file and performs
 *          operations on each number until they are equal to 1.
 *          Keeps track of largest sequence and the sum of all
 *          the numbers within that sequence.
 *
 *  Logic:  While there are still inputs to get, get inputs and print
 *          them, check if they are in order or need to be
 *          swapped. Loop through every number between and
 *          including the 2 inputs, performing operations on
 *          every one of them. Keep track of which one
 *          takes the most number of cycles to get to 1.
 *          store the sum of all the numbers in that cycle.
 *          Reset variables and repeat.
 ****************************************************************/

void calcMax(int& k, int& l, int& maxCount,
             int& maxSum, ifstream& input, ofstream& output){
    int sum = 0;
    int count = 0;
    int temp1 = 0;
    
    while(!input.eof()){
        output << setw(10) << k << setw(10) << l;
        checkOrder(k, l, temp1);
        while(k <= l){
            temp1 = k;
            while(temp1 != 1){
                sum += temp1;
                if((temp1 & 1) == true){
                    temp1 = (temp1 * 3) + 1;
                }else{
                    temp1 /= 2;
                }
                count++;
            }
            if(count > maxCount){
                maxCount = count;
                maxSum = sum + 1;
            }
            sum = 0;
            count = 0;
            k++;
        }
        output << setw(10) << maxCount+1;
        output << setw(10) << maxSum << endl << endl;
        input >> k;
        input >> l;
        sum = maxSum = maxCount = count = 0;
    }
};
