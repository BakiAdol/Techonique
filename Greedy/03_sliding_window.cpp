/*
*   Sliding Window
*   Concept, if new element is larger than previous element than previous element is replaced, because it's never will be larger.
*   if new element is smaller than previous element than no replace here, all element are stored, because may be it will be bigger.
*
*   n=10; windowSize=3;ar[]={5,9,3,4,6,7,1,6,9,5}; deque<int> q;
*
*   Step 1: i=0, j=0, q={5}
*   Step 2: i=0, j=1, q={9}
*   Step 3: i=0, j=2, q={9,3} print 9
*   Step 4: i=1, j=3, q={9,4} print 9
*   Step 5: i=2, j=4, q={6} print 6
*   Step 6: i=3, j=5, q={7} print 7
*   Step 7: i=4, j=6, q={7,1} print 7
*   Step 8: i=5, j=7, q={7,6} print 7
*   Step 9: i=6, j=8, q={9} print 9
*   Step 10: i=7, j=9, q={9,5} print 9
*
*   Output : 9 9 6 7 7 7 9 9
*
*/
#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n=10;
    int windowSize=3;
    int ar[]={5,9,3,4,6,7,1,6,9,5};

    deque<int> q;
    for(int i=0,j=0;j<n;j++)
    {
        if(!q.empty() and i>q.front()) q.pop_front();
        if(!q.empty() and ar[q.back()]<ar[j])
        {
            while(!q.empty() and ar[q.back()]<ar[j]) q.pop_back();
        }
        q.push_back(j);
        if(j-i==windowSize-1)
        {
            i++;
            cout << ar[q.front()] << endl;
        }
    }

    return 0;
}

