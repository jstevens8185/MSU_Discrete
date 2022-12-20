/****************************************************
 *  Author:           Jered Stevens
 *
 *  Course:         Discrete Structures
 *                  MWF 10AM
 *                  Stringfellow
 *
 *  File:           Sequence.h
 *
 *  Description:    This is the header file for
 *                  Sequence.cpp. Include this in
 *                  your program to use the functions
 *                  needed to find the max sequence
 *                  and the sum of all of the numbers
 *                  in that max sequence.
 *
 *  Date:           10/11/22
 ***************************************************/

#ifndef Sequence_h
#define Sequence_h

#include<fstream>
#include<iostream>
using namespace std;

void openFiles(ifstream& infile, ofstream& outfile);
void checkOrder(int& k, int& l, int& temp1);
void printHeader(ofstream& output);
void printTopRow(ofstream& output);
void calcMax(int& k, int& l, int& maxCount,
             int& maxSum, ifstream& input, ofstream& output);

#endif /* Sequence_h */
