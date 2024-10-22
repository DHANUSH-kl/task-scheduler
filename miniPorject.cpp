#include <iostream>
#include <queue>

using namespace std;

struct Process {
    int id;               
    int burstTime;       
    int remainingTime;   
};

int main() {
    int numProcesses, timeQuantum;

    cout << "Enter the number of processes: ";
    cin >> numProcesses;
    cout << "Enter the time quantum: ";
    cin >> timeQuantum;

    queue<Process> processes;

    for (int i = 1; i <= numProcesses; i++) {
        Process p;
        p.id = i;
        cout << "Enter burst time for Process " << i << ": ";
        cin >> p.burstTime;
        p.remainingTime = p.burstTime;  
        processes.push(p);  
    }

    int currentTime = 0;  

   
    while (!processes.empty()) {
        Process currentProcess = processes.front(); 
        processes.pop(); 

        int executionTime = min(currentProcess.remainingTime, timeQuantum);

        
        currentProcess.remainingTime -= executionTime;
        currentTime += executionTime; 

        
        cout << "Process " << currentProcess.id << " executed for " << executionTime << " time units. Remaining: " << currentProcess.remainingTime << endl;


        if (currentProcess.remainingTime == 0) {
            cout << "Process " << currentProcess.id << " finished at time " << currentTime << endl; 
        } else {
            processes.push(currentProcess); 
        }
    }


    return 0;
}
