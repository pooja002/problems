#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class NoRepeatSubstring
{
    public:
    static int findnorepeatsubstringofmaxlen(const string &str)
    {
        unordered_map<char,int> frequency;
        int maxlength=0,windowstart=0;
        for(int windowend=0;windowend<str.length();windowend++)
        {
              char right=str[windowend];
              if(frequency.find(right)!=frequency.end())
              {
                  windowstart=max(windowstart,frequency[right]+1);
              }
              frequency[right]=windowend;


              maxlength=max(maxlength,windowend-windowstart+1);
        }
        return maxlength;
    }
};


int main(int argc, char*argv[])
{
    int result=NoRepeatSubstring::findnorepeatsubstringofmaxlen("geeksforgeeks");
    cout<<result;
}