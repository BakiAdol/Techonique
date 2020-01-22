/*
*   You are a class planer. You are given many class starting and
*   ending time. One teacher can take one class at a time, after finish
*   this class this teacher can take another class. Your task is to
*   calculate the minimum number of teacher need for running these class.
*
*   There are seven class, and given their starting and ending time
*
*     2------------9
*   1-----4 5---------------15
*   1----------7 8-------12
*     2--3  5--7
*
*   The concept is we need to find maximum number of overlap class
*   at a particular time.
*
*   When teacher assign for a class count +1 and leave this class count
*   -1. so we need to add all class time signed count value and the
*   maximum count value is result.
*/
#include <bits/stdc++.h>

using namespace std;


int main()
{
    int numberOfClass;
    int startTime,endTime;
    int minimunTeacher=0,tmp=0;
    cin >> numberOfClass;

    map<int,int> classes;
    map<int,int>::iterator it;

    while(numberOfClass--)
    {
        cin >>startTime >> endTime;

        classes[startTime]++;
        classes[endTime]--;
    }
    for(it=classes.begin();it!=classes.end();it++)
    {
        tmp+=it->second;
        minimunTeacher=max(minimunTeacher,tmp);
    }

    cout << "Minimum number of teacher is " << minimunTeacher << endl;

    return 0;
}

