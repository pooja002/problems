#include<iostream>
using namespace std;


class Listnode
{
  public:

  int value=0;
  Listnode* next;

  Listnode( int value)
  {
      this->value=value;
      next=nullptr;
  }

};


class StartOfCycle
{
  public:
  static Listnode *FindStartOfCycle(Listnode *head)
  {
     
     Listnode *fastpointer=head;
     Listnode *slowpointer= head;

     while(fastpointer->next->next!=nullptr && fastpointer->next!=nullptr)
     {
         fastpointer=fastpointer->next->next;
         slowpointer=slowpointer->next;
         
          if(slowpointer==fastpointer)
          {
              break;
          }
     }
    
    int cyclelength=0;
    do
    {
        slowpointer=slowpointer->next;
        cyclelength++;
    } while (slowpointer!=fastpointer);

    Listnode *pointer1=head,*pointer2=head;


    while(cyclelength>0)
    {
        pointer2=pointer2->next;
        cyclelength--;
    }

    while(pointer1!=pointer2)
    {
        pointer1=pointer1->next;
        pointer2=pointer2->next;
    }
    
    
    return pointer1;
  }

};


int main()
{
    Listnode *head=new Listnode(1);
    head->next = new Listnode(1);
    head->next=new Listnode(2);
    head->next->next=new Listnode(3);
    head->next->next->next=new Listnode(4);
    head->next->next->next->next =new Listnode(5);
    head->next->next->next->next=new Listnode(6);
    head->next->next->next->next->next= head->next->next;
    cout<<"Linked list has length of cycle:"<< StartOfCycle ::FindStartOfCycle(head)->value;
    cout<<endl;
    head->next->next->next->next->next= head->next->next->next;
    cout<<"Linked list has length of cycle:"<< StartOfCycle ::FindStartOfCycle(head)->value;
    cout<<endl;
    head->next->next->next->next->next= head;
    cout<<"Linked list has length of cycle:"<< StartOfCycle ::FindStartOfCycle(head)->value;
}

