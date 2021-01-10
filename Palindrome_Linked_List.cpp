/* Problem Given the head of a Singly LinkedList, write a method to check if the LinkedList is a palindrome or not.*/
/*Naive Approach is to copy elements of linked list to a vector and check for palindrome
TimeComplexity taken is O(N)+O(N) (For travesing through linked list and checking for palindrome in vector
Space Complexity taken is O(N)

Let's solve this problem in constant space!! as below
*/





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

class Palindrome_Linked_List
{
  public:
  static bool  Is_Palindrome_Linked_List(ListNode* head)
  {
    if(head->next==nullptr ||  head==nullptr)
    {
        return true;
    }
    // Find Middle of linked list 
    ListNode *fastpointer=head;
    ListNode *slowpointer=head;
    while(fastpointer!=nullptr && fastpointer->next!=nullptr)
    {
        fastpointer=fastpointer->next->next;
        slowpointer=slowpointer->next;
    }

    ListNode *headofsecondhalf=reverse(slowpointer);
    ListNode *copyofheadofsecondhalf=headofsecondhalf;

    while(head!=nullptr && headofsecondhalf!=nullptr)
    {
       if(head->value!=headofsecondhalf->value)
       {
           break;
       }

       head=head->next;
       headofsecondhalf=headofsecondhalf->next;
    }

    reverse(copyofheadofsecondhalf);
    if(head==nullptr || headofsecondhalf==nullptr)
    {
        return true;
    }
    return false;


  }

  private:
  static ListNode* reverse(ListNode* head)
  {
      ListNode* prev=nullptr;
      while(head!=nullptr)
      {
          ListNode* next=head->next;
          head->next=prev;
          prev=head;
          head=next;
      }
      return prev;
  }
  


};


int main()
{
    ListNode* head=new ListNode(1);
    head->next=new ListNode(2);
    head->next->next= new ListNode(3);
    head->next->next->next=new ListNode(2);
    head->next->next->next->next= new ListNode(1);
   /* head->next->next->next->next->next= new ListNode(4);*/
    cout<<Palindrome_Linked_List::Is_Palindrome_Linked_List(head);
}