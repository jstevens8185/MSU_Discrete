#pragma once
#include <iomanip>
#include <iostream>
#include<fstream>
using namespace std;

void openFiles(ifstream& infile, ofstream& outfile);
unsigned short int**& createBitwiseTable(int rowCount, int columnCount);
void populateBitwiseTable1(ifstream& input, int rowcount, int columnCount, unsigned short int**& dataTable);
void destroyBitwiseTable(unsigned short int**& bitTable, int rowCount);
void printBitwiseTable1(ofstream& output, unsigned short int**& dataTable, int rowCount, int columnCount);
void initializeBitwiseTable(unsigned short int**& dataTable, int rowCount, int columnCount);
void populateBitwiseTable2(ifstream& input, int rowCount, int columnCount, unsigned short int**& dataTable);
void printBitwiseTable2(ofstream& output, unsigned short int**& dataTable, int rowCount, int columnCount);