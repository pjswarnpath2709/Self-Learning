#include <bits/stdc++.h>
using namespace std;
struct process1
{
    int processId;
    int burst_time;
    int temp_burst;
    int arrival_time;
    int comp_time;
    int tat;
    int wait_time;
    int resp_time;
    int start_time;
    int priority;
    bool isCompleted = false;
    bool isFirst = true;
};
int main()
{
    int n;
    cin >> n;

    process1 *arr = new process1[n];

    float avg_tat = 0, avg_wt = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].arrival_time >> arr[i].burst_time >> arr[i].priority;
        arr[i].processId = i + 1;
        arr[i].temp_burst = arr[i].burst_time;
    }

    int completedTillYet = 0;
    int currentTime = 0;

    while (completedTillYet != n)
    {
        // STEP1 : preapare the ready queue
        vector<process1 *> ready_queue;

        // yaha galti kari hain isne
        for (int i = 0; i < n; i++)
        {
            // need to prepare the list of processes to be added in the ready queue
            // i.eagar arrival time kaam hoga current time se to us process ko apn ready queue me add krenge
            if (arr[i].arrival_time <= currentTime && arr[i].isCompleted == false)
            {
                ready_queue.push_back(&arr[i]);
            }
        }
        // agar ready queue empty nhi h to
        if (ready_queue.empty() == false)
        {
            // STEP2
            int indx = -1;
            int max_priority = INT_MIN;

            for (int i = 0; i < ready_queue.size(); i++)
            {
                if (max_priority < ready_queue[i]->priority)
                {
                    max_priority = ready_queue[i]->priority;
                    indx = i;
                }
            }
            // STEP3 : start executing the process
            if (ready_queue[indx]->isFirst == true)
            {
                ready_queue[indx]->start_time = currentTime;
                // we noted here that the process has now arrived
                ready_queue[indx]->isFirst = false;
            }
            // now the algo is premptive so we execute every process for 1 sec
            if (ready_queue[indx]->temp_burst > 0)
            {
                ready_queue[indx]->temp_burst--;
                currentTime++;
            }
            // now when temp burst becomes zero that means the process has been completed
            if (ready_queue[indx]->temp_burst == 0)
            {
                ready_queue[indx]->isCompleted = true;
                completedTillYet++;
                ready_queue[indx]->comp_time = currentTime;
                ready_queue[indx]->tat = ready_queue[indx]->comp_time - ready_queue[indx]->arrival_time;
                ready_queue[indx]->wait_time = ready_queue[indx]->tat - ready_queue[indx]->burst_time;
                ready_queue[indx]->resp_time = ready_queue[indx]->start_time - ready_queue[indx]->arrival_time;
                avg_tat += ready_queue[indx]->tat;
                avg_wt += ready_queue[indx]->wait_time;
                ready_queue.clear();
            }
        }
        else
        {
            currentTime++;
        }
    }
    // now printing the info
    for (int i = 0; i < n; i++)
    {
        cout << "process id:" << arr[i].processId << "\t"
             << "burst time:" << arr[i].burst_time << "\t"
             << "arrival time:" << arr[i].arrival_time << "\t"
             << "completion time:" << arr[i].comp_time << "\t"
             << "tat:" << arr[i].tat << "\t"
             << "wait time:" << arr[i].wait_time << "\t"
             << "response time:" << arr[i].resp_time << endl;
    }
    cout << "average time :" << avg_wt / n << endl;
    cout << "wait time :" << avg_tat / n << endl;
}