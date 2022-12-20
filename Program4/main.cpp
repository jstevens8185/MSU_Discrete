//
//  main.cpp
//  Program4
//
//  Created by Jered Stevens on 11/20/22.
//

#include <iostream>
#include <fstream>

using namespace std;

void openFiles (std::ifstream& infile, std::ofstream& outfile);

struct Event{
private:
    unsigned short int startTime;
    unsigned short int duration;
    unsigned short int endTime;
public:
    Event(){
        startTime = 0;
        duration = 0;
        endTime = 0;
    }
    Event(unsigned short int start, unsigned short int d){
        startTime = start;
        duration = d;
        endTime = (start + d);
    }
    void setStartTime(unsigned short int s){
        startTime = s;
    }
    void setDuration(unsigned short int d){
        duration = d;
    }
    void setEndTime(unsigned short int e){
        endTime = e;
    }
    unsigned short int getStartTime(){
        return startTime;
    }
    unsigned short int getDuration(){
        return duration;
    }
    unsigned short int getEndTime(){
        return endTime;
    }
};

int main() {
    int numEvents;
    Event EArray1[20];
    std::ifstream input;
    std::ofstream output;
    
    openFiles(input, output);
    input >> numEvents;

    output << numEvents;
    
    return 0;
}

void openFiles (std::ifstream& infile, std::ofstream& outfile)
{
    char inFileName[40];
    char outFileName[40];
    std::cout<<"Enter the input file name: ";
    std::cin>>inFileName;
    infile.open(inFileName);
    std::cout<<"Enter the output file name: ";
    std::cin>> outFileName;
    outfile.open(outFileName);

    return;
}
