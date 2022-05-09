#include <bits/stdc++.h>
using namespace std;

struct process
{
    int processId;
    int arrival_time;
    int burst_time;
    int temp_burst;
    int comp_time;
    int priority;
    int response_time;
    int start_time;
    int wait_time;
    int tat;

    // booleans
    bool isCompleted = false;
    bool isFirst = true;
};

int main()
{

    // take input
    int n;
    cin >> n;

    // array of the processes
    process *arr = new process[n];

    // flaots
    float avg_wt = 0, avg_tat = 0;

    // take input
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].arrival_time >> arr[i].burst_time >> arr[i].priority;

        // set the process id
        arr[i].processId = i + 1;

        // set the temp burst
        arr[i].temp_burst = arr[i].burst_time;
    }

    int completedTillyet = 0;
    int current_time = 0;

    while (completedTillyet != n)
    {
        // step 1: prepare the ready queue
        vector<process *> readyQueue;
        for (int i = 0; i < n; i++)
        {
            if (arr[i].arrival_time <= current_time && arr[i].isCompleted == false)
            {
                readyQueue.push_back(&arr[i]);
            }
        }

        if (readyQueue.empty() == false)
        {
            // step 2: find the process with maximum priority
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

            // step 3: start executing the process

            // now the process is preemptive yani only execute for 1 second

            if (readyQueue[indx]->isFirst == true)
            {
                readyQueue[indx]->isFirst = false;
                readyQueue[indx]->start_time = current_time;
            }

            if (readyQueue[indx]->temp_burst > 0)
            {
                readyQueue[indx]->temp_burst--;
                current_time++;
            }
            if (readyQueue[indx]->temp_burst == 0)
            {
                // the process is completed
                completedTillyet++;
                readyQueue[indx]->isCompleted = true;
                readyQueue[indx]->comp_time = current_time;
                readyQueue[indx]->tat = readyQueue[indx]->comp_time - readyQueue[indx]->arrival_time;

                // avg tat
                avg_tat += readyQueue[indx]->tat;

                readyQueue[indx]->wait_time = readyQueue[indx]->tat - readyQueue[indx]->burst_time;

                // avg wt
                readyQueue[indx]->response_time = readyQueue[indx]->start_time - readyQueue[indx]->arrival_time;

                avg_wt += readyQueue[indx]->wait_time;
            }
        }
        else
        {
            current_time++;
        }
    }

    avg_tat /= n;
    avg_wt /= n;

    cout << avg_tat << "\n";
    cout << avg_wt << "\n";
    return 0;
}