/*
Given ‘M’ sorted arrays, find the K’th smallest number among all the arrays.

Example 1:

Input: L1=[2, 6, 8], L2=[3, 6, 7], L3=[1, 3, 4], K=5
Output: 4
Explanation: The 5th smallest number among all the arrays is 4, this can be verified from the merged 
list of all the arrays: [1, 2, 3, 3, 4, 6, 6, 7, 8]
Example 2:

Input: L1=[5, 8, 9], L2=[1, 7], K=3
Output: 7
Explanation: The 3rd smallest number among all the arrays is 7.

*/

/* This solution is for linked list input 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class ListNode
{
    public:
    int value=0;
    ListNode *next;
    ListNode(int value)
    {
        this->value=value;
        this->next=nullptr;
    }
};


class Find_Kth_smallest_Number
{
    public:
    struct Compare
    {
       bool operator()(const ListNode *x, const ListNode *y)
       {
           return x->value > y->value;
       }
    };


    static ListNode *find(const vector<ListNode *> &lists,  int k)
    { 
        priority_queue<ListNode*, vector<ListNode *>, Compare> minheap;

        for(auto root: lists)
        {
            if(root!=nullptr)
            {
            minheap.push(root);
            }
        }

        ListNode *node;
        while(k>0)
        {
            node=minheap.top();
            minheap.pop();
            k--;
            if(node->next!=nullptr)
            {
              minheap.push(node->next);
            }
        }
        return node;
    }
};


int main()
{
    ListNode *l1=new ListNode(2);
    l1->next=new ListNode(6);
    l1->next->next=new ListNode(8);


    ListNode *l2=new ListNode(3);
    l2->next=new ListNode(6);
    l2->next->next=new ListNode(7);

    ListNode *l3= new ListNode(2);
    l3->next=new ListNode(3);
    l3->next->next=new ListNode(4);



    ListNode *result= Find_Kth_smallest_Number::find(vector<ListNode*> {l1,l2,l3},5);
    cout<<result->value;
}


Time Complexity: O(K * Log M)
where M is the total number of elements in all K arrays

Space Complexity: O(K)

*/

/*
Given arrays as input, the approach is same as Merge K sorted list ,
but inorder to keep track of next elemnt in the current array we need to maintain element indices
*/


#include<iostream>
#include<bits/stdc++.h>
using namespace std;



class find_kth_smallest_num
{
    public:
    struct Compare
    {
       bool operator()(const pair<int,pair<int,int>> &x, pair<int,pair<int,int>> &y)
       { 
           return x.first>y.first;

       }
    };


   static int find(const vector<vector<int>> &lists, int k)
   {
       priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, Compare> minheap;

       // put the first element of all input arrays into minheap

       for(int i=0;i<lists.size();i++)
       {
           if(!lists[i].empty())
           {
           minheap.push(make_pair(lists[i][0],make_pair(i,0)));
           }
       }

       int numbercount=0,result=0;
       while(!minheap.empty())
       {
           auto node=minheap.top();
           minheap.pop();
           result=node.first;
           if(++numbercount==k)
           {
               break;
           }
           node.second.second++;
           if(lists[node.second.first].size()>node.second.second)
           {
               node.first=lists[node.second.first][node.second.second];
               minheap.push(node);
           }
       }
       return result;
   }
};


int main()
{
    vector<vector<int>> lists={{2,6,8},{3,6,7},{1,3,4}};
    int result=find_kth_smallest_num::find(lists,5);
    cout<<result;
}


/*
Since we’ll be going through at most ‘K’ elements among all the arrays, 
and we will remove/add one element in the heap in each step, the time
 complexity of the above algorithm will be O(K*logM)O(K∗logM) where ‘M’ is the total number of input arrays.

Space complexity #
The space complexity will be O(M) because, at any time, our min-heap will be storing one number from all the ‘M’ input arrays.*/