#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class LongestSubstringWithSameLettersAfterReplacement
{
public:
static int findLongestSubstringWithSameLettersAfterReplacement(int k, const string &str)
{
  int windowstart=0,maxlength=0;
  int maxrepeatcount=0;
  unordered_map<char,int> charfrequency;
  for(int windowend=0;windowend<str.length();windowend++)
  {
      char right=str[windowend];
      charfrequency[right]++;
      maxrepeatcount=max(maxrepeatcount,charfrequency[right]);
      if(windowend-windowstart+1-maxrepeatcount>k)
      {
       char left=str[windowstart];
       charfrequency[left]--;
       windowstart++;
      }
      maxlength=max(maxlength,windowend-windowstart+1);

  }
  return maxlength;
}

};


int main()
{
  int result=LongestSubstringWithSameLettersAfterReplacement::findLongestSubstringWithSameLettersAfterReplacement(1,"aabccb");
  cout<<result;
}