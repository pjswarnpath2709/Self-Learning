#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define mset multiset
#define uset unordered_set
#define umap unordered_map
#define nline "\n"
#define vi vector<int>
#define vll vector<long long>
#define pi pair<int, int>
#define pll pair<long long, long long>
#define all_vec vec.begin(), vec.end()
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define MOD 1000000007
/*---------------------------------------------------------------------------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;

/*---------------------------------------------------------------------------------------------------------------*/
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
/*---------------------------------------------------------------------------------------------------------------*/
const int N = 1e7 + 10;
// A))FINDING MAXIMUM SUM IN WINDOW SIZE 3

// int main()
// {
//     ll n;
//     cin >> n;
//     vll vec(n, 0);
//     for (auto &i : vec)
//     {
//         cin >> i;
//     }
//     int i = 0, j = 0, k = 3;
//     ll sum = 0;
//     while (j <= k - 1)
//     {
//         sum += vec[j];
//         j++;
//     }
//     // cout<<j<<"\n";
//     // cout<<sum<<"\n";
//      ll sum2=sum;
//     while(j<n){
//         sum=sum+vec[j++]-vec[i++];
//         sum2=max(sum,sum2);
//     // cout<<sum2<<"\n";
//     }                           // this is happening exactly
//     cout<<sum2<<"\n";          // [2 3 5] 2 ---> [2 3 5 2] ---> 2 [3 5 2]
// }

/*---------------------------------------------------------------------------------------------------------------*/

// B))FINDING FIRST NEGATIVE NUMBER IN WINDOW SIZE 3
// int main()
// {
//     ll n;
//     cin >> n;
//     vll vec(n);
//     for (auto &i : vec)
//     {
//         cin >> i;
//     }
//     int i = 0;
//     int j = 0;
//     int k = 3;
//     queue<int> qt;
//     vll ans;
//     while (j < n)
//     {
//         if (vec[j] < 0)
//         {
//             qt.push(vec[j]);
//         }
//         if (j - i + 1 < k)
//         {
//             j++;
//             // continue;
//         }
//         else
//         {
//             if (qt.size() != 0)
//                 ans.pb(qt.front());
//             if (qt.size() == 0)
//             {
//                 ans.pb(0);
//             }

//             if (vec[i] == qt.front())
//             {
//                 qt.pop();
//             }
//             i++;
//             j++;
//         }
//     }
//     for (auto &i : ans)
//     {
//         cout << i << " ";
//     }
//     cout << "\n";
// }

/*---------------------------------------------------------------------------------------------------------------*/

// C))Count Ocuurances of Anagram IN WINDOW SIZE 3
// int main()
// {
//     string str;
//     cin >> str;
//     string st;
//     cin >> st;
//     umap<char, int> mp;
//     for (int t = 0; t < st.size(); t++)
//     {
//         mp[st[t]]++;
//     }
//     int countmp = mp.size();
//     int k = st.size();
//     int ans=0;
//     int i = 0, j = 0;
//     while (j < str.length())
//     {
//         if (mp.find(str[j]) != mp.end())
//         {
//             mp[str[j]]--;
//             if (mp[str[j]] == 0)
//             {
//                 countmp--;
//             }
//         }
//         if(j-i+1<k){
//             j++;
//         }
//         else{
//             if(countmp==0){
//                 ans++;
//             }
//             j++;
//             if(mp.find(str[i])!=mp.end()){
//                 mp[str[i]]++;
//                 if(mp[str[i]]==1){
//                     countmp++;
//                 }
//                 i++;
//             }else{
//                 i++;
//             }
//         }
//     }
//     cout<<ans<<"\n";
// }

/*---------------------------------------------------------------------------------------------------------------*/

// D))Finding maximum of all subarrays of window size SIZE 3
// int main()
// {
//     ll n;
//     cin >> n;
//     vi vec(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> vec[i];
//     }
//     int k;
//     cin >> k;
//     int i = 0;
//     int j = 0;
//     vector<int> ans;
//     deque<int> qt;
//     while (j < n)
//     {
//         while (qt.size() > 0 && qt.back() < vec[j])
//         {
//             qt.pop_back();
//         }
//         qt.pb(vec[j]);
//         if (j - i + 1 < k)
//         {
//             j++;
//         }
//         else
//         {
//             ans.pb(qt.front());
//             if (qt.front() == vec[i])
//             {
//                 qt.pop_front();
//             }

//                 i++;
//                 j++;

//         }
//     }
//     for (int i : ans)
//     {
//         cout << i << " ";
//     }
// }

/*---------------------------------------------------------------------------------------------------------------*/

// E))Finding maximum of all subaarya of window size SIZE 3

// int main()
// {
//     ll n;
//     cin >> n;
//     vll vec(n);
//     for (auto &i : vec)
//     {
//         cin >> i;
//     }
//     ll k;
//     cin >> k;
//     int mx = INT_MIN;
//     int j = 0;
//     int i = 0;
//     ll sum = 0;
//     while (j < n)
//     {
//         sum += vec[j];
//         if (sum < k)
//         {
//             j++;
//             continue;
//         }
//         else if (sum == k)
//         {
//             mx = max(mx, (j - i + 1));
//             j++;
//         }
//         else
//         {
//             while (sum >= k)
//             {
//                 sum -= vec[i++];
//             }
//             j++;
//         }
//     }
//     cout << mx << "\n";
// }

/*---------------------------------------------------------------------------------------------------------------*/
// F))Finding maximum of all subarrays of window  SIZE 3
int main(){
    
}