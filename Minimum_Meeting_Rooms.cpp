/* 

Given a list of intervals representing the start and end time of ‘N’ meetings, find the minimum number of rooms required to hold all the meetings.

Meetings: [[1,4], [2,5], [7,9]]
Output: 2
Explanation: Since [1,4] and [2,5] overlap, we need two rooms to hold these two meetings. [7,9] can 
occur in any of the two rooms later.

Algoritm used:
Sort all the meetings on their start time.
Create a min-heap to store all the active meetings. This min-heap will also be used to find the active meeting with the smallest end time.
Iterate through all the meetings one by one to add them in the min-heap. Let’s say we are trying to schedule the meeting m1.
Since the min-heap contains all the active meetings, so before scheduling m1 we can remove all meetings from the heap that have ended before m1, i.e., remove all meetings from the heap that have an end time smaller than or equal to the start time of m1.
Now add m1 to the heap.
The heap will always have all the overlapping meetings, so we will need rooms for all of them. Keep a counter to remember the maximum size of the heap at any time which will be the minimum number of rooms needed.
*/

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
bool sort_by_start_time(Interval a , Interval b)
{
    return a.s<b.s;
}



int findMinimummeetingRooms(vector<Interval> &meeting)
{
  sort(meeting.begin(),meeting.end(),sort_by_start_time);
  int minrooms=0;
  priority_queue<Interval,vector<Interval>,endcompare> minheap;
  for (auto meet:meeting)
  {
      while(!minheap.empty() && meet.s>=minheap.top().e)
      {
          minheap.pop();
      }
      minheap.push(meet);
      minrooms=max(minrooms, (int)minheap.size());
  }

  return minrooms;
}

int main()
{
    vector<Interval> input={{1,4},{2,5},{7,9}};
    int result=findMinimummeetingRooms(input);
    cout<<result;
}

/*he time complexity of the above algorithm is O(N*logN)O(N∗logN), where ‘N’ is the total number of meetings. This is due to the sorting that we did in the beginning.*/
/* Space Complexity:
The space complexity of the above algorithm will be O(N)O(N) which is required for sorting. Also, in the worst case scenario, we’ll have to insert all the meetings into the Min Heap (when all meetings overlap) which will also take O(N)O(N) space. The overall space complexity of our algorithm is O(N)O(N).*/