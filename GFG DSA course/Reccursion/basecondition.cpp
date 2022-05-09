

#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
void f()
{
    if (cnt > 10)
        return;
    cout << cnt << "\n";
    cnt++;
    f();
}
int main()
{
    f();
    return 0;
}