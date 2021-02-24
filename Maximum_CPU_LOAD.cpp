#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Job
{
  int s,e,load;

};

bool startcompare(Job a, Job b)
{
    return a.s<b.s;
}

struct endcompare
{
    bool operator()(Job a , Job b)
    {
       return a.e>b.e;
    }

};

int MaximumCpuLoad(vector<Job> &Jobs)
{
    sort(Jobs.begin(),Jobs.end(),startcompare);
    int maxCPUload=0;
    int currentCPUload=0;
    priority_queue<Job,vector<Job>,endcompare> minheap;

    for(auto job: Jobs)
    {
    
    while(!minheap.empty() && job.s>minheap.top().e)
    {
         currentCPUload-=minheap.top().load;
            minheap.pop();
    }
    

    minheap.push(job);
    currentCPUload+=job.load;
    maxCPUload=max(maxCPUload,currentCPUload);
    }

    return maxCPUload;
}

int main()
{
    vector<Job> input= {{6,7,10},{8,12,15},{2,4,11}};
    cout<<MaximumCpuLoad(input);

}


/* Time complexity #
The time complexity of the above algorithm is O(N*logN), where ‘N’ is the total number of jobs. This is due to the sorting that we did in the beginning. Also, while iterating the jobs, we might need to poll/offer jobs to the priority queue. Each of these operations can take O(logN). Overall our algorithm will take O(NlogN).

Space complexity #
The space complexity of the above algorithm will be O(N)O(N), which is required for sorting. Also, in the worst case, we have to insert all the jobs into the priority queue (when all jobs overlap) which will also take O(N)O(N) space. The overall space complexity of our algorithm is O(N).*/