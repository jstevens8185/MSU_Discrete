/**********************************
 * Name:    Jered Stevens
 * Date:    11/29/22
 * Course:  Discrete Structures,
 *          Stringfellow
 * Purpose: Use a greedy Algo to create
 *              an efficient schedule
 *              for events where start
 *              time and duration is known
 *              for each event.
 ***********************************/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Event {
private:
    unsigned short int startTime;
    unsigned short int duration;
    unsigned short int endTime;
public:
    Event() {
        startTime = 0;
        duration = 0;
        endTime = 0;
    }
    Event(unsigned short int start, unsigned short int d) {
        startTime = start;
        duration = d;
        endTime = (start + d);
    }
    void setStartTime(unsigned short int s) {
        startTime = s;
    }
    void setDuration(unsigned short int d) {
        duration = d;
    }
    void setEndTime(unsigned short int e) {
        endTime = e;
    }
    unsigned short int getStartTime() {
        return startTime;
    }
    unsigned short int getDuration() {
        return duration;
    }
    unsigned short int getEndTime() {
        return endTime;
    }
};

void openFiles(std::ifstream& infile, std::ofstream& outfile);
void populateEventList(ifstream& in, vector<Event*>& EventList);
void populateGreedyList(vector<Event*>& G, vector<Event*>& E);
void printAllEvents(ofstream& out, vector<Event*>& EventList);
void sortEvents(vector<Event*>& EventList);
void deallocateList(vector<Event*>& List);

int main() {
    vector<Event*> EventList;
    vector<Event*> GreedyList;
    ifstream in;
    ofstream out;

    openFiles(in, out);

    //PrintHeader
    out << "Name:   Jered Stevens\n"
        << "Date:   11/29/22\n"
        << "Course: Discrete Structures\n"
        << "        Stringfellow\n\n";

    populateEventList(in, EventList);
    in.close();
    sortEvents(EventList);
    populateGreedyList(GreedyList, EventList);
    printAllEvents(out, GreedyList);
    out.close();
    deallocateList(EventList);
}

/******************************************
*   Name:       deallocateList
*   Params:     vector<Event*>& List
*   Returns:    void
*   Purpose:    Deallocates memory taken
*                   by pointers in the
*                   vector of Events
*****************************************/
void deallocateList(vector<Event*>& List) {
    for (int i = 0; i < List.size(); i++) {
        delete List[i];
    }
};

/******************************************
*   Name:       populateEventList
*   Params:     ifstream& in, 
*               vector<Event*>& Eventlist
*   Returns:    void
*   Purpose:    Reads input from a file and
*                   creates events from data
*                   then pushes the new event
*                   to a vector of events
*****************************************/
void populateEventList(ifstream& in, vector<Event*>& EventList) {
    int numEvents;
    int startTime;
    int duration;
    in >> numEvents;

    for (int i = 0; i < numEvents; i++) {
        in >> startTime;
        in >> duration;
        Event* temp = new Event(startTime, duration);
        EventList.push_back(temp);
    }
};

/******************************************
*   Name:       populateGreedyList
*   Params:     vector<Event*>& G
*               vector<Event*>& E
*   Returns:    void
*   Purpose:    Takes values from an existing
*                   vector of Events and pushes
*                   them to a new vector to 
*                   create a schedule where
*                   no 2 events will overlap.
*****************************************/
void populateGreedyList(vector<Event*>& G, vector<Event*>& E) {
    G.push_back(E[0]);
    for (int i = 1; i < E.size(); i++) {
        if (E[i]->getStartTime() >= G.back()->getEndTime()) {
            G.push_back(E[i]);
        };
    }
};

/******************************************
*   Name:       openFiles
*   Params:     ifstream& infile
*               ofstream& outfile
*   Returns:    void
*   Purpose:    opens files specified by
*                   user input.
*****************************************/
void openFiles(std::ifstream& infile, std::ofstream& outfile)
{
    char inFileName[40];
    char outFileName[40];
    std::cout << "Enter the input file name: ";
    std::cin >> inFileName;
    infile.open(inFileName);
    std::cout << "Enter the output file name: ";
    std::cin >> outFileName;
    outfile.open(outFileName);

    return;
}

/******************************************
*   Name:       printAllEvents
*   Params:     ofstream& out
*               vector<Event*>& List
*   Returns:    void
*   Purpose:    prints all events contained
*                   in a vector of events.
*                   Includes their start
*                   time, duration, and end
*                   times.
*****************************************/
void printAllEvents(ofstream& out, vector<Event*>& EventList) {
    for (int i = 0; i < EventList.size(); i++) {
        out << "Event #" << i + 1 << endl;
        out << "StartTime:" << EventList[i]->getStartTime() << endl;
        out << "Duration:" << EventList[i]->getDuration() << endl;
        out << "EndTime:" << EventList[i]->getEndTime() << endl << endl;
    }
}

/******************************************
*   Name:       sortEvents
*   Params:     vector<Event*>& EventList
*   Returns:    void
*   Purpose:    Sorts all events in a vector
*                   of events in increasing
*                   order of their end times
*                   using a select sort algo.
*****************************************/
void sortEvents(vector<Event*>& EventList) {
    Event* temp1;
    int j;
    for (int i = 1; i < EventList.size(); i++) {
        temp1 = EventList[i];
        j = i - 1;
        while (j >= 0 && EventList[j]->getEndTime() > temp1->getEndTime()){
            EventList[j + 1] = EventList[j];
            j--;
        }
        EventList[j + 1] = temp1;
    }
};