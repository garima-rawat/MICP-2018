#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node* next;
};

void insert(Node **head,int n)
{
    Node *ptr;//*head;
    //head = *headref;    
    ptr=new Node;
    ptr->data=n;
    ptr->next=NULL;
    if(*head==NULL)
    *head=ptr;
    else
    {
        ptr->next=*head;
        *head=ptr;
    }
    

}
bool isPalindrome(Node *head)
{
    if(head==NULL)
    return 0;
    
    if(head->next==NULL)
    return 1;
    
    Node *ptr2,*head2,*prev,*ptr1,*next;
    ptr1=head;ptr2=head;
    
    //finding middle element
    while(ptr2!=NULL && ptr2->next!=NULL)
    {
        ptr2=ptr2->next->next;
        ptr1=ptr1->next;
    }
    head2=ptr1;
    
    //breaking list into 2
    ptr1=head;
    while(ptr1->next!=head2)
    {
        ptr1=ptr1->next;
    }
    ptr1->next=NULL;
    
    //reversing second list
    prev=NULL;
    ptr1=head2;
    
    while(ptr1->next!=NULL)
    {
        next=ptr1->next;
        ptr1->next=prev;
        
        prev=ptr1;
        ptr1=next;
    }
    head2=ptr1;
    ptr1->next=prev;
    
    
    //comparing
    ptr1=head;
    ptr2=head2;
    while(ptr1!=NULL)
    {
        if(ptr1->data != ptr2->data)
        return 0;
        ptr1=ptr1->next;
        ptr2=ptr2->next;
        
    }
    return 1;
}
bool t1()
{
    Node *head;
    head=NULL;
    insert(&head,1);
    return(isPalindrome(head));
}
bool t2()
{
    Node *head;
    head=NULL;
    insert(&head,1);
    insert(&head,2);
    return(!isPalindrome(head));
}
bool t3()
{
    Node *head;
    head=NULL;
    insert(&head,1);
    insert(&head,1);
    return(isPalindrome(head)); 
}
bool t4()
{
    Node *head;
    head=NULL;
    insert(&head,1);
    insert(&head,2);
    insert(&head,1);
    insert(&head,2);
    return(!isPalindrome(head)); 
}
bool t5()
{
    Node *head;
    head=NULL;
    insert(&head,1);
    insert(&head,2);
    insert(&head,2);
    insert(&head,1);
    return(isPalindrome(head)); 
}
bool t6()
{
    Node *head;
    head=NULL;
    insert(&head,1);
    insert(&head,2);
    insert(&head,3);
    insert(&head,2);
    insert(&head,1);
    return(isPalindrome(head)); 
}
bool t7()
{
    Node *head;
    head=NULL;
    insert(&head,1);
    insert(&head,2);
    insert(&head,3);
    insert(&head,3);
    insert(&head,1);
    return(!isPalindrome(head)); 
}
bool test()
{
    return(t1() && t2() && t3() && t4() && t5() && t6() && t7());
}
int main()
{
    Node *head;
    head=NULL;
    insert(&head,1);
    insert(&head,2);
    insert(&head,3);
    cout<<isPalindrome(head);
    cout<<test();
    return 1;
}
