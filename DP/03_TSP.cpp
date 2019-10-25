#include <bits/stdc++.h>

using namespace std;

int TSP(vector<vector<int>>& cities, int pos, int visited, vector<vector<int>>& state)
{
    if(visited==((1<<cities.size())-1)) return cities[pos][0];
    if(state[pos][visited]!=INT_MAX) return state[pos][visited];
    for(int i=0;i<cities.size();i++)
    {
        if(i==pos || (visited & (1<<i))) continue;
        int distance = cities[pos][i] + TSP(cities,i,visited|(1<<i),state);
        if(distance<state[pos][visited]) state[pos][visited] = distance;
    }
    return state[pos][visited];
}

int main()
{
    vector<vector<int>> cities = { { 0, 30, 42, 50 },
                                   { 30, 0, 40, 34 },
                                   { 42, 40, 0, 30 },
                                   { 50, 34, 30, 0 }
                                 };
    vector<vector<int>> state(cities.size());
    for(auto& adj : state)
    {
        adj = vector<int>((1<<cities.size())-1,INT_MAX);
    }

    cout << TSP(cities,0,1,state);

    return 0;
}

