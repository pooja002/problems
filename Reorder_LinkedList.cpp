/* Problem Statement: Given the head of a Singly LinkedList, write a method to modify the LinkedList such that the nodes from the second half of the LinkedList are inserted alternately to the nodes from the first half in reverse order. So if the LinkedList has nodes 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> null, your method should return 1 -> 6 -> 2 -> 5 -> 3 -> 4 -> null.
Constraint:Your algorithm should not use any extra space and the input LinkedList should be modified in-place. 
Below Algorithm Takes Time complexity of O(N)
Space Complexity of O(1)*/



#include<iostream>
using namespace std;

class ListNode
{
  public:
  int value=0;
  ListNode* next;
  ListNode(int value)
  {
      this->value=value;
      next=nullptr;
  }
};

class Reorder
{
 public:
 static void Do_Reordering(ListNode* head)
 {
     //edge case
     if(head==nullptr || head->next==nullptr)
     {
         return;
     }
     //find middle of linked list
     ListNode *fastpointer=head;
     ListNode *slowpointer=head;
     while(fastpointer!=nullptr && fastpointer->next!=nullptr)
     {
         fastpointer=fastpointer->next->next;
         slowpointer=slowpointer->next;
     }

    ListNode *headofsecondhalf=reverse(slowpointer);
    ListNode *headoffirsthalf=head;
    //Rearange the Linked List
    while(headofsecondhalf!=nullptr && headoffirsthalf!=nullptr)
    {
        ListNode *temp= headoffirsthalf->next;
        headoffirsthalf->next=headofsecondhalf;
        headoffirsthalf=temp;

        temp=headofsecondhalf->next;
        headofsecondhalf->next=headoffirsthalf;
        headofsecondhalf=temp;
    }

    if(headoffirsthalf!=nullptr)
    {
        headoffirsthalf->next=nullptr;
    }
 }

 private:
 
 static ListNode* reverse(ListNode *head)
 {
     ListNode *prev=nullptr;
     while(head!=nullptr)
     {
     ListNode *temp;
     temp=head->next;
     head->next=prev;
     prev=head;
     head=temp;
     }
     return prev;

 }
};


int main()
{
    ListNode* head=new ListNode(2);
    head->next=new ListNode(4);
    head->next->next= new ListNode(6);
    head->next->next->next=new ListNode(8);
    head->next->next->next->next= new ListNode(10);
    head->next->next->next->next->next= new ListNode(12);
    Reorder::Do_Reordering(head);
    while(head!=nullptr)
    {
        cout<<head->value<<" ";
        head=head->next;

    }
}