#include<string>
#include<sstream>
#include<vector>
#include<iostream>
using namespace std;
class Solution
{
    public:
    int planTrip(vector<int> moneyDisributed,int numPairs, vector<vector<int>>coldWarMembers)
    {

    }
};


int main()

{
    string line;
    vector<int> moneyDistributed;
    vector<vector<int>> coldWarMembers;
    int val,numpairs,pairone,paittwo;
    getline(cin,line);
    isstringstream stream(line);
    while(stream>>val)
    {
        moneyDistributed.push_back(val);
    }
    cin>>numpairs;
    for(int i=0;i<numpairs;i++)
    {
        cin>>pairone>>pairtwo;
        coldWarMembers.push_back({pairone,pairtwo});
    }
    cout<<Solution().planTrip(moneyDistributed,numpairs,coldWarMembers);
}