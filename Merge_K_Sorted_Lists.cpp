#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Given an array of ‘K’ sorted LinkedLists, merge them into one sorted list.

Example 1:

Input: L1=[2, 6, 8], L2=[3, 6, 7], L3=[1, 3, 4]
Output: [1, 2, 3, 3, 4, 6, 6, 7, 8]
Example 2:

Input: L1=[5, 8, 9], L2=[1, 7]
Output: [1, 5, 7, 8, 9]
*/


/*
Approach 1 is to put all the elements of K lists to one list and then sort it .
If there are a total of ‘N’ elements in all the input lists,
 then the brute force solution will have a time complexity of O(N*logN)
 as we will need to sort the merged list. Can we do better than this?
 How can we utilize the fact that the input lists are individually sorted?

Approach 2 is to take a heap of size K , and then  add all the starting 
elements of lists to the min heap , pop the top (which is the smallest) element and
add the next element of this top element to heap */

class ListNode
{
 public:
 int data;
 ListNode *next;
 ListNode(int data)
 {
     this->data=data;
     this->next=nullptr;
 }
};



class Merge_K_Lists
{
 public:
 struct Compare
 {
   bool operator()(ListNode *x, ListNode *y)
   {
      return x->data>y->data;
   }
 };


 static ListNode *Merge_K_Lists_Here(const vector<ListNode*> &lists)
 {
  priority_queue<ListNode*, vector<ListNode*>, Compare> minheap;
  for(auto root: lists)
  {
      if(root!=nullptr)
      {
          minheap.push(root);
      }
  }
   
   ListNode *head=nullptr, *tail=nullptr;
  while(!minheap.empty())
  {
      ListNode *node=minheap.top();
      minheap.pop();
      if(head==nullptr)
      {
          head=tail=node;
      }
      else
      {
          tail->next=node;
          tail=tail->next;
      }
      if(node->next!=nullptr)
      {
          minheap.push(node->next);
      }
  }
  return head;
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

    ListNode *l3=new ListNode(1);
    l3->next=new ListNode(3);
    l3->next->next=new ListNode(4);

    ListNode *result= Merge_K_Lists::Merge_K_Lists_Here(vector<ListNode *>{l1,l2,l3});

    while(result!=nullptr)
    {
        cout<<result->data<<" ";
        result=result->next;
    }
}


/*

Time complexity #
Since we’ll be going 
through all the elements of all arrays and will be removing/adding one element to the heap in each step,
 the time complexity of the above algorithm will be O(N*logK) where ‘N’ is the total number of elements 
 in all the ‘K’ input arrays.

Space complexity #
The space complexity will be O(K) because, at any time, 
our min-heap will be storing one number from all the ‘K’ input arrays

*/