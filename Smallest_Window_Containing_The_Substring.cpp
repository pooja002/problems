#include<iostream>
#include<bits/stdc++.h>

using namespace std; 
class Smallest_Window_Containing_The_Substring
{
    public:

    static string Find_Smallest_Window_Containing_The_Substring(const string &str, const string &pattern)
    {
        int windowstart=0,matched=0,minlength=str.length()+1,substringstart=0;
        unordered_map<char,int> charfrequencymap;
        for( auto ch:pattern)
        {
            charfrequencymap[ch]++;
        }

       

        for(int windowend=0;windowstart<str.length();windowend++)
        {
             char right=str[windowend];
             if(charfrequencymap.find(right)!=charfrequencymap.end())
             {
              
              charfrequencymap[right]--;
              if(charfrequencymap[right]>=0)
              {
                  matched++;
              }
             }

             while(matched==pattern.length())
             {
                 if(minlength>windowend-windowstart+1)
                 {
                        minlength=windowend-windowstart+1;
                        substringstart=windowstart;
                 }

                 char left=str[windowstart++];
                
                if(charfrequencymap.find(left)!=charfrequencymap.end())
                {
                  if(charfrequencymap[left]==0)
                  {
                      matched--;
                  }
                  charfrequencymap[left]++;

                }

             }

        }
        return minlength>str.length() ? "": str.substr(substringstart,minlength);
    }

};


int main(int argc, char *argv[])
{
    cout<<Smallest_Window_Containing_The_Substring::Find_Smallest_Window_Containing_The_Substring("aabcde","b") <<endl;
}