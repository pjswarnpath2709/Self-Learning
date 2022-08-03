

#include <bits/stdc++.h>
using namespace std;
int countDivisors(int n)
{
    int cnt = 0;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            // If divisors are equal,
            // count only one
            if (n / i == i)
                cnt++;

            else // Otherwise count both
                cnt = cnt + 2;
        }
    }
    return cnt;
}

long long countOddSum(vector<long long> ar, int N)
{
    // A temporary array of size 2. temp[0] is going to
    // store count of even subarrays and temp[1] count of
    // odd. temp[0] is initialized as 1 because there a
    // single odd element is also counted as a subarray
    int temp[2] = {1, 0};

    // Initialize count. sum is sum of elements under modulo
    // 2 and ending with arr[i].
    long long result = 0, val = 0;

    // i'th iteration computes sum of arr[0..i] under modulo
    // 2 and increments even/odd count according to sum's
    // value
    for (int i = 0; i <= N - 1; i++)
    {
        // 2 is added to handle negative numbers
        val = ((val + ar[i]) % 2 + 2) % 2;
        // Increment even/odd count
        temp[val]++;
    }
    // An odd can be formed by even-odd pair
    result = (temp[0] * temp[1]);
    return (result);
}
long long countSubarray(int N, vector<long long> A)
{

    // array which willm contain number of divisors for each element
    vector<long long> divisors(N);

    for (int i = 0; i < N; i++)
    {
        // t.c. for getting number of divisor for one ele o(n*1/3)
        divisors[i] = countDivisors(A[i]);
    }

    // now we just have to see how many number of subaarays have oddSum

    int numberOfOddSubbarrays = countOddSum(divisors, N);
    return numberOfOddSubbarrays;
}
int main()
{
    int n;
    cin >> n;
    vector<long long> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }

    cout << countSubarray(n, vec) << "\n";

    return 0;
}