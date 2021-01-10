#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class PermutationOfPatternInString
{
public:
   static bool findpermutationofpatternstring(const string &str, const string &pattern)
   {
       int windowstart=0,count=0;
       bool found=false;
       
       unordered_map<char,int> charfrequencymap;
       
       for(auto chr:pattern)
       {
           charfrequencymap[chr]++;
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
              found=true;
          }

          if(windowend>=pattern.length()-1)
          {
            char left= str[windowstart++];
            if(charfrequencymap.find(left)!=charfrequencymap.end())
            {
                if(charfrequencymap[left]==0)
                {
                    count--;
                }

            charfrequencymap[left]++;
            }
            
        

          }

      }
      return found;

   }
};

int main(int argc, char*argv[])
{
 bool result=PermutationOfPatternInString::findpermutationofpatternstring("eidbaooo","ab" );
 cout<<result;

}