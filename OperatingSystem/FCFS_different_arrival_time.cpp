#include <bits/stdc++.h>
using namespace std;

struct process2
{
    int processId;
    int burst_time;
    int arrival_time;
    int comp_time;
    int tat;
    int wait_time;
    int resp_time;
    bool isCompleted = false;
    bool isFirst = true;
    bool startTime = 0;
};

int main()
{
    int n;
    cin >> n;
    process2 *arr = new process2[n];

    float avg_tat = 0, avg_wt = 0;
    // talking input for burst time
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].arrival_time;
        cin >> arr[i].burst_time;
        arr[i].processId = i + 1;
    }

    int completed_till_yet = 0;
    int current_time = 0;

    while (completed_till_yet != n)
    {
        vector<process2 *> readyQueue;
        for (int i = 0; i < n; i++)
        {
            if (arr[i].arrival_time <= current_time && arr[i].isCompleted == false)
            {
                readyQueue.push_back(&arr[i]);
            }
        }
        // if ready queue is not empty
        if (readyQueue.empty() == false)
        {
            int indx = -1;
            int min_arrival_time = INT_MAX;

            for (int i = 0; i < readyQueue.size(); i++)
            {
                if (readyQueue[i]->arrival_time < min_arrival_time)
                {
                    min_arrival_time = readyQueue[i]->arrival_time;
                    indx = i;
                }
            }
            // calculating completion time
            current_time += readyQueue[indx]->burst_time;
            readyQueue[indx]->comp_time = current_time;
            readyQueue[indx]->tat = readyQueue[indx]->comp_time - readyQueue[indx]->arrival_time;
            readyQueue[indx]->wait_time = readyQueue[indx]->tat - readyQueue[indx]->burst_time;
            completed_till_yet++;

            avg_tat += readyQueue[indx]->tat;
            avg_wt += readyQueue[indx]->wait_time;
            readyQueue[indx]->isCompleted = true;
        }
        else
        {
            current_time++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << "process id :" << arr[i].processId << "\t"
             << "burst time :" << arr[i].burst_time << "\t"
             << "completion time :" << arr[i].comp_time << "\t"
             << "turn around time :" << arr[i].tat << "\t"
             << "wait time :" << arr[i].wait_time << endl;
    }
    cout << "average tat :" << avg_tat/n << endl;
    cout << "average wait time :" << avg_wt/n << endl;
    return 0;
}