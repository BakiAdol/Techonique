/*
*   You are a student. You are given some class starting and ending
*   time. Your task is to find the maximum number of class you can
*   join. Constraint if you start a calls you can't leave this class
*   before it's ending.
*
*     2------------9
*   1-----4 5---------------15
*   1----------7 8-------12
*     2--3  5--7
*
* There are seven class, for simplicity
*   2------------9
*   1-----4
*   5---------------15
*   1----------7
*   8-------12
*   2--3
*   5--7
*
*   Sort these class based on their ending time
*
*   2--3
*   1-----4
*   5--7
*   1----------7
*   2------------9
*   8-------12
*   5---------------15
*
*   Now we pick first class and then find very next class starting
*   time is bigger than first class ending time. Then choose thirst
*   class whose starting time is bigger than previous class ending
*   ending time.
*   So we pick, (2,3), (5,7), (8,12)
*/
#include <bits/stdc++.h>

using namespace std;

struct Class{
    int startTime,endTime;
};

bool cmp(Class a, Class b)
{
    return a.endTime<b.endTime;
}

int main()
{
    int numberOfClass;
    int maxClass=0, endingTime=0;
    cin >> numberOfClass;

    vector<Class> classes;

    Class cls;

    while(numberOfClass--)
    {
        cin >> cls.startTime >> cls.endTime;

        classes.push_back(cls);
    }

    sort(classes.begin(),classes.end(),cmp);

    for(int i=0;i<(int)classes.size();i++)
    {
        if(classes[i].startTime>=endingTime)
        {
            endingTime=classes[i].endTime;
            maxClass++;
        }
    }
    cout << "You can join maximum " << maxClass << " class." << endl;

    return 0;
}
