#include <bits/stdc++.h>
using namespace std;

bool searchinframes(int frames[], int pagenumber, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (frames[i] == pagenumber)
        {
            return true;
        }
    }
    return false;
}
int nextEmptyPlace(int frames[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (frames[i] == -1)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int no_of_frames;
    cin >> no_of_frames;

    int frames[no_of_frames];
    for (int i = 0; i < no_of_frames; i++)
    {
        frames[i] = -1;
    }

    string ref;
    cin >> ref;

    int pagefault = 0;
    int first = 0; // index of the element which came first

    for (int i = 0; i < ref.length(); i++)
    {
        int pagenumber = ref[i]-'0';
        /*
        
        0->97
        1->98
        2->99
        3->100
        .
        .
        .
        .
        int n ='2';
        n=99
        int n='2'-'0';
        n=2
        
        */
        if (!searchinframes(frames, pagenumber, no_of_frames))
        {
            // there exists any empty spot
            int idx = nextEmptyPlace(frames, no_of_frames);
            if (idx != -1)
            {
                frames[idx] = pagenumber;
            }

            // if no then append at first
            else
            {
                frames[first] = pagenumber;
                first = (first + 1) % no_of_frames;
            }

            pagefault++;
        }

        for(int i=0;i<no_of_frames;i++){

        }
    }

    return 0;
}