#include<iostream>
#include<bits/stdc++.h>
using namespace std;



struct Interval
{
 int s,e;
};



struct endcompare
{
    bool operator()(Interval a, Interval b)
    {
          return a.e>b.e;
    }
};

bool startcompare(Interval a, Interval b)
{
    return a.s<b.s;
}

int Minimum_Meeting_Rooms(vector<Interval> &Meetings)
{
    int minrooms=0;
    sort(Meetings.begin(),Meetings.end(),startcompare);
    priority_queue<Interval, vector<Interval>, endcompare> minheap;
    for(auto meet :Meetings)
    {
        while(!minheap.empty() && meet.s>=minheap.top().e)
        {
            minheap.pop();
        }
        minheap.push(meet);
        minrooms=max(minrooms,(int) minheap.size());
    }
    return minrooms;

}


int main()
{

    vector<Interval> input={{1,4},{2,5},{7,9}};
    cout<<Minimum_Meeting_Rooms(input);
}