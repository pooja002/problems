#include<iostream>
using namespace std;

class ListNode
{
    public:
    int value;
    ListNode* next;

    ListNode(int value)
    {
        this->value=value;
        next=nullptr;
    }

};


class Middle_Of_LinkedList
{
   public:
   static ListNode*  Find_Middle_Of_Linked_List(ListNode* head)
   {
       ListNode* slowpointer=head;
       ListNode* fastpointer=head;

       while(fastpointer!=nullptr && fastpointer->next!=nullptr)
       {
           fastpointer=fastpointer->next->next;
           slowpointer=slowpointer->next;
       }
       return slowpointer;
   }


};


int main()
{
    ListNode* head=new ListNode(1);
    head->next=new ListNode(2);
    head->next->next= new ListNode(3);
    head->next->next->next=new ListNode(4);
    head->next->next->next->next= new ListNode(5);
    head->next->next->next->next->next= new ListNode(6);

    cout<<Middle_Of_LinkedList::Find_Middle_Of_Linked_List(head)->value;
}