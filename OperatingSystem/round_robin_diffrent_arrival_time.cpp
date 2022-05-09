#include <bits/stdc++.h>
using namespace std;

// input manke chalnege ki sorted form mein ayega
struct process
{
    int processId;
    int burst_time;
    int arrival_time;
    int comp_time;
    int temp_burst;
    int tat;
    int wait_time;
    int resp_time;
    bool isCompleted = false;
    bool startTime = 0;
    bool isFirst = true;
    bool inQueue = false; // phele se queue mein hein ya nahiu hain
};
int main()
{
    int n;
    cin >> n;
    process *arr = new process[n];
    float avg_tat = 0, avg_wt = 0;
    int time_quantum;
    cin >> time_quantum;
    // talking input for burst time and arrival time

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].arrival_time;
        cin >> arr[i].burst_time;
        arr[i].temp_burst = arr[i].burst_time;
        arr[i].processId = i + 1;
    }
    int completed_till_yet = 0;
    int current_time = 0;
    /*

    REASON FOR ROUND ROBIN QUEUE:
    while loop ke bahar isliye likha hain kyuki poore algorithm mein
    ek queue rehti hai jiska use apan baar baar karte hain

    baaki algorithms mein ready queue banti hai jo har
    current time ke liye NEW banti hai isliye woh while loop ke
    andar banti hain

    */
    queue<process *> roundrobinQueue; // created a roundRobinqueue

    while (completed_till_yet != n)
    {
        // if the round robin queue is not empty
        if (roundrobinQueue.empty() == false)
        {
            // kuch kaam karenge

            // we will execute the front process of the roundRobinQueue

            // kya us process ko peheli baar cpu mil raha hai
            if (roundrobinQueue.front()->isFirst == true)
            {
                roundrobinQueue.front()->startTime = current_time;
                roundrobinQueue.front()->isFirst = false;
            }
            if (roundrobinQueue.front()->temp_burst > time_quantum)
            {
                // time quantam jitna execute karo
                roundrobinQueue.front()->temp_burst -= time_quantum;
                current_time += time_quantum;

                // us process ko hata do queue ke front se
                int idx = roundrobinQueue.front()->processId - 1;
                roundrobinQueue.pop();

                // chk if there are any process
                for (int i = 0; i < n; i++)
                {
                    if (arr[i].arrival_time <= current_time && arr[i].inQueue == false && arr[i].isCompleted == false)
                    {
                        roundrobinQueue.push(&arr[i]); // process ko queue round robin queue mein daal diya
                        arr[i].inQueue = true;
                    }
                }

                // us process process ko wapis daldo round robin ke end mein
                roundrobinQueue.push(&arr[idx]);
            }
            else
            {
                // process ko poora execute kardo
                completed_till_yet++;
                roundrobinQueue.front()->isCompleted = true;
                current_time += roundrobinQueue.front()->temp_burst;
                roundrobinQueue.front()->temp_burst = 0;
                roundrobinQueue.front()->comp_time = current_time;

                // saari cheeje calculate kar lete hai
                roundrobinQueue.front()->tat = roundrobinQueue.front()->comp_time - roundrobinQueue.front()->arrival_time;
                roundrobinQueue.front()->wait_time = roundrobinQueue.front()->comp_time - roundrobinQueue.front()->arrival_time;
                roundrobinQueue.front()->resp_time = roundrobinQueue.front()->startTime - roundrobinQueue.front()->arrival_time;

                // round robin queue se us process ko hata do
                roundrobinQueue.pop();
            }
        }

        // if the queue is empty
        else
        {
            // if the round robin queue is empty
            // we will chk for current time if there exists any process
            bool thereisProcess = false;
            for (int i = 0; i < n; i++)
            {
                if (arr[i].arrival_time <= current_time && arr[i].inQueue == false && arr[i].isCompleted == false)
                {
                    thereisProcess = true;
                    roundrobinQueue.push(&arr[i]); // process ko queue round robin queue mein daal diya
                    arr[i].inQueue = true;
                }
            }
            // if there exists no ready process then increase the current time
            if (thereisProcess == false)
            {
                current_time++;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << "pid :" << arr[i].processId << "\t "
             << "bt :" << arr[i].burst_time << "\t "
             << "at :" << arr[i].arrival_time << "\t "
             << "ct :" << arr[i].comp_time << "\t "
             << "tat :" << arr[i].tat << "\t "
             << "wt :" << arr[i].wait_time << "\t "
             << "rt :" << arr[i].resp_time << "\t ";
        cout << "\n";
    }
}
/*

4
2
0 3
0 6
0 4
0 5


*/