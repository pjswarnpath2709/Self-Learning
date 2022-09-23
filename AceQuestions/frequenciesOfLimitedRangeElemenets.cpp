//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// efficient solution for the frequencyCount Approach
// -ve frequency approach / congested hashing approach

class Solution
{
public:
    void frequencyCount(vector<int> &arr, int N, int P)
    {
        // step 1: mark all the frequencies
        int i = 0;
        while (i < N)
        {
            // negative elements will represent the frequency
            if (arr[i] <= 0)
            {
                i++; // already negative element ya zero hai toh aage badho
            }
            else
            {
                // woh frequency nahi hai toh yani waha pe unmarked number present hai
                // ab arr[i] lie karta hai 1 -> N mein to use map kar sakte 0 -> N-1 indexes pe
                // ab iski hashing hum negative numbers se karenge jo frequency denote karenge
                // ek mapIndx variable banega jaha pe frequency store karayenge
                int indx = arr[i] - 1;
                if (arr[indx] <= 0)
                {
                    // yani yeh phele mark hogaya tha bas ab iski frequency badhani hai
                    arr[indx]--;
                    // ab is value ka kaam hogya toh ise zero mark kardo
                    arr[i] = 0;
                    // aage move karado , yaha se toh kaam hogya hai kyuki
                    i++;
                }
                else
                {
                    // yani yeh phele se mark nahi hu tha , abhi iski jagah koi aur value padhi hui hai
                    // toh values ko swap karlo
                    arr[i] = arr[indx];
                    // ab iske mapIndex pe -1 mark kardo
                    arr[indx] = -1;
                }
            }
        }

        // step 2: make all the frequencies positive baby
        for (int i = 0; i < N; i++)
        {
            arr[i] *= -1;
        }
    }
};

// approach 2 : The Multiple of N theorem
void frequencyCount2(vector<int> &arr, int N, int P)
{
    for (int i = 0; i < N; i++)
    {
        arr[i] -= 1;
    }
    for (int i = 0; i < N; i++)
    {
        arr[arr[i]%N]+=N;
    }

    for (int i = 0; i < N; i++)
    {
        arr[i] /= N;
    }
}

//{ Driver Code Starts.

int main()
{
    long long t;

    // test cases
    cin >> t;

    while (t--)
    {

        int N, P;
        // size of array
        cin >> N;

        vector<int> arr(N);

        // adding elements to the vector
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        cin >> P;
        Solution ob;
        // calling frequencyCount() function
        ob.frequencyCount(arr, N, P);

        // printing array elements
        for (int i = 0; i < N; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends