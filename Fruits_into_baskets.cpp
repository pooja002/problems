#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class FruitsIntoBaskets
{
    public:
    static int putfruitsintobaskets( const vector<char>&trees)
    {
        unordered_map<char,int> frequencymap;
        int windowstart=0,maxlength=0;
        for(int windowend=0;windowend<trees.size();windowend++)
        {
            char right=trees[windowend];
            frequencymap[right]++;
            while(frequencymap.size()>2)
            {
                char left=trees[windowstart];
                frequencymap[left]--;
                if(frequencymap[left]==0)
                {
                    frequencymap.erase(left);
                }
                windowstart++;
            }
             maxlength=max(maxlength,windowend-windowstart+1);
        }
        return maxlength;
    }

};


int main(int argc, char*argv[])
{
    int result=FruitsIntoBaskets::putfruitsintobaskets(vector<char>{'A','B','C','B','B','C'});
    cout<<result;
}