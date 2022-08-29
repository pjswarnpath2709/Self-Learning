

#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int data;
    ListNode *next;
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int cnt = 0;
        ListNode *ans = head;
        ListNode *del = head;
        ListNode *spcase = head;
        while (head != NULL)
        {
            head = head->next;
            cnt++;
        }

        int todel = cnt - n + 1;

        if (n != cnt || n == 1)
        {
            ListNode *back;
            for (int i = 1; i < todel; i++)
            {
                if (i == todel - 1)
                    back = del;

                del = del->next;
            }

            ListNode *fwd = del->next;
            delete del;
            back->next = fwd;

            if (n == 1)
            {
                back->next = NULL;
            }
        }

        if (n == cnt)

        {
            ans = ans->next;
            delete head;
        }

        return ans;
    }
};

int main()
{

    return 0;
}