#include <iostream>
#include <algorithm>
using namespace std;
struct process
{
    int process_id;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turnAround_time;
    int waiting_time;
};

//comparator function for the process structure -> tells how to sort a two objects 
bool myComp(process p1, process p2)
{
    return p1.burst_time < p2.burst_time;
}


int main()
{
    int n;
    cin >> n;
    process *arr = new process[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].burst_time;
        arr[i].process_id = i + 1;
    }
    sort(arr, arr + n, myComp);
    float avgTat = 0, avgWt = 0;

    //completion time for the first process will be 
    arr[0].completion_time = arr[0].burst_time;
    for (int i = 1; i < n; i++)
    {
        arr[i].completion_time = arr[i - 1].completion_time + arr[i].burst_time;
    }
    //turn around timings
    for (int i = 0; i < n; i++)
    {
        arr[i].turnAround_time = arr[i].completion_time - arr[i].arrival_time;
        avgTat += arr[i].turnAround_time;
    }
    //wait timings of the processes 
    for (int i = 0; i < n; i++)
    {
        arr[i].waiting_time = arr[i].turnAround_time - arr[i].burst_time;
        avgWt += arr[i].waiting_time;
    }
    avgTat /= n;
    avgWt /= n;

    cout << avgTat << endl;
    cout << avgWt << endl;
}