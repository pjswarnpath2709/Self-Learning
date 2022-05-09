#include <bits/stdc++.h>
using namespace std;

struct process
{
    int process_id;
    int arrival_time;
    int burst_time;
    int tat;
    int wt;
    int ct;
    int response_time;
    int start_time; // pehli baar cpu kab mila
    int tempBurst;
    bool isFirst = true;
    bool isCompleted = false; // to chk if process is completed or not
};

int main()
{
    int completedTillyet = 0; // number of process completed till yet
    int current_time = 0;     // to denote current time in gantt chart

    int n;
    cin >> n;
    process *arr = new process[n];

    // input
    for (int i = 0; i < n; i++)
    {
        arr[i].process_id = i + 1;
        cin >> arr[i].arrival_time >> arr[i].burst_time;
        arr[i].tempBurst = arr[i].burst_time; // temp burst ko set kiya
    }

    while (completedTillyet != n)
    {
        // prepare the ready queue at current time
        vector<process> vec; // this is a ready queue
        for (int i = 0; i < n; i++)
        {
            if (arr[i].arrival_time <= current_time && arr[i].isCompleted == false)
            {
                vec.push_back(arr[i]);
            }
        }
        // the ready queue is ready
        if (vec.empty() == false)
        {
            int indx = -1; // index of the process with minimum burst time
            int mini_burst = INT_MAX;
            for (int i = 0; i < vec.size(); i++)
            {
                if (vec[i].burst_time < mini_burst)
                {
                    indx = i;
                    mini_burst = vec[i].burst_time;
                }
            }

            // got the process whose burst time is minimum
            // now execute the process
            if (vec[indx].isFirst == true)
            {
                // if the process has arrived for the first time note it's start time
                vec[indx].start_time = current_time;

                vec[indx].isFirst = false;
            }
            if (vec[indx].tempBurst > 0)
            {
                vec[indx].tempBurst = vec[indx].tempBurst - 1;
                current_time++;
            }
            if (vec[indx].tempBurst == 0)
            {
                // process completed here
                vec[indx].isCompleted = true;
                vec[indx].ct = current_time;
                vec[indx].tat = vec[indx].ct - vec[indx].arrival_time;                   // turn around time
                vec[indx].wt = vec[indx].tat - vec[indx].burst_time;                     // waiting time
                vec[indx].response_time = vec[indx].start_time - vec[indx].arrival_time; // response time
                completedTillyet++;                                                      // increment the number of processes completed till yet
            }
        }
        else
        {
            current_time++;
        }
    }

    return 0;
}