//
//  main.cpp
//  homework3_CSCI3400
//
//  Created by Thao Pham on 10/11/21.
//
#include <iostream>
#include <queue>
#include <fstream>
#include <string>

using namespace std;

class Process
{
    
    int ID;
    int execTime;

    public:
        Process(int newID, int newTime)//Constructor
        {
            ID = newID;
            execTime = newTime;
        }
        
        void execute() // decrease the execution time by 1
        {
            execTime--;
        }
        
        int getID()
        {
            return ID;
        }
        
        int getTime()
        {
            return execTime;
        }
        
        void Print()
        {
            cout << "- Process: " << getID() << " sent back of the queue! \t Remaining Time: " << getTime() << " ms" << endl << endl;
        }
};

int main() {
    
    queue<Process> g; //Creating queue with data as a whole block of Process.

    string filename("/Applications/Studying/AUM/FA21/CSCI3400/homework3_CSCI3400/processList.txt"); //Change the path name before running
    
    int id;
    int exectime;
    
    ifstream input_file(filename);
    if (!input_file.is_open())
    {
        cout << "Could not open the file: " << filename << endl;
        return EXIT_FAILURE;
    }
    while (input_file >> id >> exectime)
    {
        Process proc(id, exectime);
        g.push(proc); // pushing that data to the queue
        //cout << "Process: " << id << " \t " << "Remaining Time:" << exectime << " ms" << endl << endl;
    }
    input_file.close();
    
    while ( !g.empty() ) // queue is not empty
    {
        Process proc1 = g.front();
        
        if (proc1.getTime() == 0)
        {
            cout << "+ Process: " << proc1.getID() << " is completed!" << endl << endl;
            g.pop();
        }
        else
        {
            proc1.execute(); //execTime--
            
            proc1.Print();
//            cout << "Process: " << pro1.getID() << " sent back of the queue " << "\t" <<"Remaining time: " << pro1.getTime() << "ms."<< endl;
            
            g.push(proc1);
            g.pop();
        }
    }
    return 0;
}
