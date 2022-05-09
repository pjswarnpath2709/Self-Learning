#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define mset multiset
#define uset unordered_set
#define umap unordered_map
#define vi vector<int>
#define vll vector<long long>
#define vc vector<char>
#define vs vector<string>
#define pi pair<int, int>
#define pll pair<long long, long long>
#define all_vec vec.begin(), vec.end()
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define MOD 1000000007
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
template <class T>
void in_array(T *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}
template <class T>
void print_array(T *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
// Lomuto's Partition------partiton number 2
int lomutoPartition(int arr[], int low, int high, int pivot)
{
    // this algorithm always take last elemeent as the pivot so we will first swap last element with the pivot element
    swap(arr[pivot], arr[high]);
    // position of pivot may change so we will stroe pivot in any temproary variable
    int pivot_value = arr[high];

    // now we will make the window of smaller elements
    // and always increase the window size when we find any smaller element
    int i = low - 1; // window size will be zero at first therefore it will start from low-1

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot_value)
        {
            i++;                  // increase window size
            swap(arr[j], arr[i]); // swap the last element in the window with smaller element
        }
    }
    swap(arr[i + 1], arr[high]); // as i+1th element will contain a greater element swap it with pivot
    return i + 1;                // return the correct position of that element
}

// Hoare's Partition-------partition number 3
int hoarePartiton(int arr[], int low, int high, int pivot)
{
    // it always assumes the first element as the pivot
    // so we will swap the givon pivot with first element
    swap(arr[pivot], arr[low]);
    int pivot_value = arr[low];
    int i = low - 1;  // window of lesser elements
    int j = high + 1; // window of greater or equal elements
    while (true)
    {
        do
        {
            i++;
        } while (arr[i] < pivot_value);
        do
        {
            j++;
        } while (arr[j] >= pivot_value);
        if (i <= j)
        {
            return j;
        }
        swap(arr[i], arr[j]);
    }
    // this partition does not ensures or gurantee taht the element is made fixed at that position
    // it just gives the position 1 lesser than the actual position of the pivot element
}

// Lomuto's QuickSort
void quickSortLomuto(int arr[], int low, int high)
{
    // isme pivot point ata hain return mein isliye,hum pivot ke left side wale
    // ko recursiveely sort karte hain aur pivot ke right side wale ko recursively solve karte hain
    if (low < high)
    {
        int p = lomutoPartition(arr, low, high, high); // last element ke arround karta hain partition
        // position p pe correct element rahega toh use sort karne ki jaroorat nahi
        quickSortLomuto(arr, low, p - 1);  // pivot ke left side ko karo sort
        quickSortLomuto(arr, p + 1, high); // pivot ke right side ko karo sort
    }
}

// Hoare's QuickSort
void quickSortHoare(int arr[], int low, int high)
{
    // isme pivot ki position nahi atti isliye array ke do parts pe wapis recursively call karte hain
    if (low < high)
    {
        int p = hoarePartiton(arr, low, high, low); // first element ke around partition karta hain
        // jo position return hogi uski garauntee nahi hain ki woh sahi jagah par hain
        // but is baat ki garauntee hain ki array ab do parts mein divide hogaya hain
        // {left part->smaller elements} and {right part->larger element}
        // ab in dono part pe independently sorting kar sakte hain because they are independent of each other
        quickSortHoare(arr, low, p);      // sorting left part
        quickSortHoare(arr, p + 1, high); // sorting right part
    }
}
int main()
{

    return 0;
}