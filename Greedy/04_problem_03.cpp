/*
*   Shells Coloring
*   You are given some sell and their color code. you can color sells only their color.
*   your task is to choose two color code so that you can color maximum consecutive sells.
*
*   Concept each time take cone color and if chosen color are three then remove very first color.
*   and each time count number of sells. Maximum number of sells is our result
*
*   n=10; maxColor=2;ar[]={3,9,9,3,4,4,3,6,7,6}; map<int,int> mp;
*
*   Step 1: j=0, i=0, mp[ar[i=0]=3]=1, mp.size()=1{3} > maxColor : false, maxCell=max(maxCell,i-j+1)=max(0,0-0+1)=1
*   Step 2: j=0, i=1, mp[ar[i=1]=9]=1, mp.size()=2{3,9} > maxColor : false, maxCell=max(maxCell,i-j+1)=max(1,1-0+1)=2
*   Step 3: j=0, i=2, mp[ar[i=2]=9]=2, mp.size()=2{3,9}> maxColor : false, maxCell=max(maxCell,i-j+1)=max(2,2-0+1)=3
*   Step 4: j=0, i=3, mp[ar[i=3]=3]=2, mp.size()=2{3,9} > maxColor : false, maxCell=max(maxCell,i-j+1)=max(3,3-0+1)=4
*   Step 5: j=0, i=4, mp[ar[i=4]=4]=1, mp.size()=3{3,9,4} > maxColor : true, mp[ar[j=0]=3]--, mp[ar[j=0]=3]=1 == 0 : false, j++, j=1
*                                      mp.size()=3{3,9,4} > maxColor : true, mp[ar[j=1]=9]--, mp[ar[j=1]=9]=1 == 0 : false, j++, j=2
*                                      mp.size()=3{3,9,4} > maxColor : true, mp[ar[j=2]=9]--, mp[ar[j=2]=9]=0 == 0 : true, erase mp[ar[j=1]=9] j++, j=3
*                                      mp.size()=2{3,4} > maxColor : false, maxCell=max(maxCell,i-j+1)=max(4,4-3+1)=4
*   Step 6: j=3, i=5, mp[ar[i=5]=4]=2, mp.size()=2{3,4} > maxColor : false, maxCell=max(maxCell,i-j+1)=max(4,5-3+1)=4
*   Step 7: j=3, i=6, mp[ar[i=6]=3]=2, mp.size()=2{3,4} > maxColor : false, maxCell=max(maxCell,i-j+1)=max(4,6-3+1)=4
*   Step 8: j=3, i=7, mp[ar[i=7]=6]=1, mp.size()=3{3,4,6} > maxColor : true, mp[ar[j=3]=3]--, mp[ar[j=3]=3]=1 == 0 : false, j++, j=4
*                                      mp.size()=3{3,4,6} > maxColor : true, mp[ar[j=4]=4]--, mp[ar[j=4]=4]=1 == 0 : false, j++, j=5
*                                      mp.size()=3{3,4,6} > maxColor : true, mp[ar[j=4]=4]--, mp[ar[j=4]=4]=0 == 0 : true, erase mp[ar[j=5]=4] j++, j=6
*                                      mp.size()=2{3,6} > maxColor : false, maxCell=max(maxCell,i-j+1)=max(4,7-6+1)=4
*   Step 9: j=5, i=8, mp[ar[i=8]=7]=1, mp.size()=3{3,6,7} > maxColor : true, mp[ar[j=6]=3]--, mp[ar[j=6]=3]=0 == 0 : true, erase mp[ar[j=6]=3] j++, j=7
*                                      mp.size()=2{6,7} > maxColor : false, maxCell=max(maxCell,i-j+1)=max(4,8-7+1)=4
*   Step 9: j=7, i=9, mp[ar[i=9]=6]=2, mp.size()=2{6,7} > maxColor : false, maxCell=max(maxCell,i-j+1)=max(4,9-7+1)=4
*
*   Result : maximum sell color by only two color is 4(3,9,9,3) sells
*
*/
#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n=10;
    int maxColor=2;
    int maxCell=0;
    int ar[]={3,9,9,3,4,4,3,6,7,6};

    map<int,int> mp;

    for(int i=0,j=0;i<n;i++)
    {
        mp[ar[i]]++;
        while(mp.size()>maxColor)
        {
            mp[ar[j]]--;
            if(mp[ar[j]]==0) mp.erase(ar[j]);
            j++;
        }
        maxCell=max(maxCell,i-j+1);
    }

    cout << maxCell << endl;

    return 0;
}

