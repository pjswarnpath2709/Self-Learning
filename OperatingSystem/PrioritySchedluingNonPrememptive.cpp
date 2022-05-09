#include <bits/stdc++.h>
using namespace std;

// structure of a Process
struct Process
{
    int processID;
    int start_time;
    int burst_time;
    int priority;
    int arrival_time;
    int comp_time;
    int tat;
    int wt;
    bool isComopleted = false;
    bool isFirst = true;
    int response_time;
};

int main()
{

    int n;
    cin >> n;

    Process *arr = new Process[n];

    float avg_wt = 0, avg_tat = 0;

    // input lena hain
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].arrival_time >> arr[i].burst_time >> arr[i].priority;
        arr[i].processID = i + 1;
    }

    int completedTillyet = 0;
    int current_time = 0;

    while (completedTillyet != n)
    {
        // ready queue banayi hain
        vector<Process *> readyQueue;

        for (int i = 0; i < n; i++)
        {
            // if the arrival time of not ready process is lesser than the current time
            // then add iut to the ready queue
            if (arr[i].arrival_time <= current_time && arr[i].isComopleted == false)
            {
                readyQueue.push_back(&arr[i]);
            }
        }

        // for (int i = 0; i < readyQueue.size(); i++)
        // {
        //     cout << readyQueue[i]->processID << " ";
        // }
        // cout << "\n";

        if (readyQueue.empty())
        {
            current_time++;
        }
        else
        {
            int indx = -1;
            int max_priority = INT_MIN;

            for (int i = 0; i < readyQueue.size(); i++)
            {
                if (readyQueue[i]->priority > max_priority)
                {
                    max_priority = readyQueue[i]->priority;
                    indx = i;
                }
            }

            // got the process with maximum priority having index indx in ready queue
            if (readyQueue[indx]->isFirst == true)
            {
                readyQueue[indx]->isFirst = false;
                readyQueue[indx]->start_time = current_time;
            }

            // non premptive hain toh ek saatyh poori process execute hogi
            current_time += readyQueue[indx]->burst_time;

            readyQueue[indx]->isComopleted = true;

            readyQueue[indx]->comp_time = current_time;

            completedTillyet++;

            // now calculate the the other things of the process
            readyQueue[indx]->tat = readyQueue[indx]->comp_time - readyQueue[indx]->arrival_time;
            avg_tat += readyQueue[indx]->tat;
            readyQueue[indx]->wt = readyQueue[indx]->tat - readyQueue[indx]->burst_time;
            avg_wt += readyQueue[indx]->wt;
            readyQueue[indx]->response_time = readyQueue[indx]->start_time - readyQueue[indx]->arrival_time;
            readyQueue.clear();
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << "process id:" << arr[i].processID << "\t"
             << "burst time:" << arr[i].burst_time << "\t"
             << "arrival time:" << arr[i].arrival_time << "\t"
             << "completion time:" << arr[i].comp_time << "\t"
             << "tat:" << arr[i].tat << "\t"
             << "wait time:" << arr[i].wt << "\t"
             << "response time:" << arr[i].response_time << endl;
    }

    avg_tat /= n;
    avg_wt /= n;
    cout << "Average tat " << avg_tat;
    cout << "Average wt " << avg_wt;
}