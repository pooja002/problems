#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class String_Anagrams
{
public:
static vector<int> Find_String_Anagarams(const string &str, const string &pattern)
{
    vector<int> result;
    unordered_map<char,int> charfrequencymap;
    int count=0,windowstart=0;
    for(auto ch:pattern)
    {
      charfrequencymap[ch]++;
    }
    
    for(int windowend=0;windowend<str.length();windowend++)
    {
        char right=str[windowend];
        if(charfrequencymap.find(right)!=charfrequencymap.end())
        {
            charfrequencymap[right]--;
            if(charfrequencymap[right]==0)
            {
                count++;
            }
        
        }

        if(count==(int)charfrequencymap.size())
        {
            result.push_back(windowstart);
           
        }

        if(windowend>=pattern.length()-1)
        {
            char left=str[windowstart++];
            if(charfrequencymap.find(left)!=charfrequencymap.end())
            {
                if(charfrequencymap[left]==0)
                {
                count--;
                }
            }
            charfrequencymap[left]++;
        }



    }



    return result;

}

};

int main(int argc, char* argv[])
{
    vector<int> result=String_Anagrams::Find_String_Anagarams("aaaaa","a");
    for(int i=0;i<result.size();i++)
    {
    cout<<result[i]<<" ";
    }
}