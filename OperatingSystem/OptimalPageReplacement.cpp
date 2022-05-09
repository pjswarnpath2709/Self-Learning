#include <bits/stdc++.h>
using namespace std;

struct page
{
    char pageNumber;
    int nextIndexInReference;
};

bool searchinframes(page *frames, int n, char pageNumber)
{
    for (int i = 0; i < n; i++)
    {
        if (frames[i].pageNumber == pageNumber)
        {
            return true;
        }
    }
    return false;
}

int getNextEmptySlot(page *frames, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (frames[i].pageNumber == -1)
        {
            return i;
        }
    }
    return -1;
}

int getNextIndexInRefrenceString(char pageNumber, string &s, int currentIndex)
{
    for (int i = currentIndex + 1; i < s.length(); i++)
    {
        if (s[i] == pageNumber)
        {
            return i;
        }
    }
    return s.length() + 1;
}

int getIndexOfVictim(page *frames, int n)
{
    int indx = -1;
    int max_next_index = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (frames[i].nextIndexInReference > max_next_index)
        {
            indx = i;
            max_next_index = frames[i].nextIndexInReference;
        }
    }
    return indx;
}

int printTheframes(page *frames, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << frames[i].pageNumber << " ";
    }
    cout << "\n";
}

int main()
{
    int n;
    cin >> n;

    int pagefaults = 0;

    page *frames = new page[n];
    // set all page number to -1
    for (int i = 0; i < n; i++)
    {
        frames[i].pageNumber = '-1';
    }

    string refstr;
    cin >> refstr;

    for (int i = 0; i < refstr.length(); i++)
    {
        int currentIndex = i;
        char pageNumber = refstr[i];
        int nextIndexInRefrenceString = getNextIndexInRefrenceString(pageNumber, refstr, currentIndex);

        if (!searchinframes(frames, n, pageNumber))
        {
            // if there is empty slot than  find it
            int idx = getNextEmptySlot(frames, n);
            if (idx != -1)
            {
                frames[idx].pageNumber = pageNumber;
                frames[idx].nextIndexInReference = nextIndexInRefrenceString;
            }
            else
            {
                // do replacement
                idx = getIndexOfVictim(frames, n);
                frames[idx].pageNumber = pageNumber;
                frames[idx].nextIndexInReference = nextIndexInRefrenceString;
            }
            pagefaults++;
        }
        else
        {
            // hence it exists the get the index of
            // the frame and update it  with
            // next index in the string
            int idx = -1;
            for (int i = 0; i < n; i++)
            {
                if (frames[i].pageNumber == pageNumber)
                {
                    idx = i; // frame wala index haiu
                    break;
                }
            }
            frames[idx].nextIndexInReference = nextIndexInRefrenceString; // refrence string wala index hai
        }

        printTheframes(frames, n);
    }

    return 0;
}