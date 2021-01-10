#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Words_Concatenation
{

    public:

    static vector<int> Find_Words_Concatenation(const string &String, const vector<string> &Words)
    {
       unordered_map<string,int> wordmap;
       for(auto str: Words)
       {
           wordmap[str]++;
       }

       vector<int> resultindices;

       int wordscount=Words.size();
       int wordlength=Words[0].length();

      for(int i=0;i<=String.length()-wordscount*wordlength;i++)
      {
          unordered_map<string,int> wordseen;
          for(int j=0;j<wordscount;j++)
          {
            int nextwordindex=i+j*wordlength;
            string word=String.substr(nextwordindex,wordlength);
            if(wordmap.find(word)==wordmap.end())
            {
                break;
            }
     
            wordseen[word]++;

            if(wordseen[word]>wordmap[word])
            {
                break;
            }

            if(j+1==wordscount)
            {
                resultindices.push_back(i);
            }

            
          }
      }
      return resultindices;
    }

};


int main(int argc, char *argv[])
{
    vector<int> result=Words_Concatenation::Find_Words_Concatenation("catcatcat",vector<string> {"cat","fox"});
    for(int i=0;i<result.size();i++)
    {
    cout<<result[i]<<" ";
    }
}