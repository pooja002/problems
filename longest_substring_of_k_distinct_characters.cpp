#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class LongestSubstringOfKDistinctCharacters
{
    public:
    static int FindLongestSubstring(const string &str, int k)
    {
        unordered_map<char,int> frequencycharmap;
        int windowstart=0,maxlength=0;
        for(int windowend=0;windowend<str.length();windowend++)
        {
            char right=str[windowend];
            frequencycharmap[right]++;
            while((int)frequencycharmap.size()>k)
            {
                char left=str[windowstart];
                frequencycharmap[left]--;
                if(frequencycharmap[left]==0)
                {
                    frequencycharmap.erase(left);
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
    int result=LongestSubstringOfKDistinctCharacters::FindLongestSubstring("araaci",2);
    cout<<result;


}