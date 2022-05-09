#include <bits/stdc++.h>
using namespace std;

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

// naive approach ------- partition number 1
int partitionNaive(int arr[], int low, int high, int pivot)
{
    int *temp = new int[high - low + 1];
    int index = 0;
    // for all lower element
    for (int i = low; i <= high; i++)
    {
        if (arr[i] < arr[pivot])
        {
            temp[index] = arr[i];
            index++;
        }
    }
    // for all equal too elements
    for (int i = low; i <= high; i++)
    {
        if (arr[i] == arr[pivot])
        {
            temp[index] = arr[i];
            index++;
        }
    }
    int result = low + index - 1; // taking the last equal element's index as result
    // for all higher elements
    for (int i = low; i <= high; i++)
    {
        if (arr[i] > arr[pivot])
        {
            temp[index] = arr[i];
            index++;
        }
    }
    // copy whole array in the previous array
    for (int i = 0; i < index; i++)
    {
        arr[i + low] = temp[i];
    }
    return result; // returning the correct position of that element
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

int main()
{

    return 0;
}