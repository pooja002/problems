#include<iostream>
#include<limits>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

class Minimumlengthofsubarrayforgivensum
{
public:
static int findminimumsubarray(int s, const vector<int> &arr)
{
    int minlength=numeric_limits<int>::max();
    int windowstart=0,windowsum=0;
    for(int windowend=0;windowend<arr.size();windowend++){
        windowsum+=arr[windowend];
        while(windowsum>=s)
        {
        minlength=min(minlength,windowend-windowstart+1);
        windowsum-=arr[windowstart];
        windowstart++;
        }
    }
    return minlength==numeric_limits<int>::max() ? 0 :minlength;

}
};





int main(int argc, char*argv[])
{
   int result=Minimumlengthofsubarrayforgivensum::findminimumsubarray(7,vector<int>{2,1,5,2,3,2});
   cout<<result<<endl;
}