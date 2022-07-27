#define vi vector<int>
#define vll vector<long long>
#include <bits/stdc++.h>
using namespace std;

void in_vector(int size, vector<int> &vec)
{
    for (int i = 0; i < size; i++)
    {
        cin >> vec[i];
    }
}

void printVector(vector<int> &vec)
{
    for (auto ele : vec)
    {
        cout << ele << " ";
    }
    cout << "\n";
}

struct Triplet
{
    // current value in the array
    int value;

    // position of the value in array
    int indexofValueInArray;

    // position of the array in array of arrays
    int indexofArrayInArrayOfArrays;

    Triplet(int val, int posVal, int posArr)
    {
        value = val;
        indexofValueInArray = posVal;
        indexofArrayInArrayOfArrays = posArr;
    }
};

struct myComp
{
    bool operator()(Triplet const &t1, Triplet const &t2)
    {
        return t1.value > t2.value;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{
    vi res;

    // build the new min heap
    priority_queue<Triplet, vector<Triplet>, myComp> min_heap;

    // fill the array with the first element of every element
    for (int i = 0; i < kArrays.size(); i++)
    {
        min_heap.push(Triplet(kArrays[i][0], 0, i));
    }

    while (!min_heap.empty())
    {
        // take the minimum element out of the heap
        Triplet t = min_heap.top();
        min_heap.pop();

        // insert it into the result
        res.push_back(t.value);

        // now fill the next element of the same array int the heap
        int posArr = t.indexofArrayInArrayOfArrays;
        int posVal = t.indexofValueInArray;

        if (posArr < kArrays.size() && posVal < kArrays[posArr].size())
        {
            int value = kArrays[posArr][posVal + 1];
            min_heap.push(Triplet(value, posVal + 1, posArr));
        }
    }

    return res;
}

void solve()
{

    int k;
    cin >> k;
    vector<vector<int>> kArrays;
    for (int i = 0; i < k; i++)
    {
        int n;
        cin >> n;
        vector<int> vec(n);
        in_vector(n, vec);
        kArrays.push_back(vec);
    }

    vector<int> ans = mergeKSortedArrays(kArrays, k);
    printVector(ans);
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}