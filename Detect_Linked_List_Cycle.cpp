using namespace std;

#include<iostream>

class ListNode{
    public:
    int value=0;
    ListNode *next;

    ListNode(int value)
    {
        this->value=value;
        next= nullptr;
    }
};

class LinkedListCycle
{
    public:
    static bool hasCycle(ListNode *head)
    {
       
       ListNode *fastpointer=head;
       ListNode *slowpointer=head;
       while(fastpointer!=nullptr && fastpointer->next !=nullptr)
       {
           fastpointer=fastpointer->next->next;
           slowpointer=slowpointer->next;
           if(fastpointer==slowpointer)
           {
               return true;
           }
       }

        return false;
    }
};

int main(int argc, char*argv[])
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(4);
    head->next->next->next->next =new ListNode(5);
    head->next->next->next->next=new ListNode(6);

    cout<<"LinkedList has cycle:"<<LinkedListCycle::hasCycle(head)<<endl;

    head->next->next->next->next->next= head->next->next;
    cout<<"Linked list has cycle:"<< LinkedListCycle ::hasCycle(head);
    
}