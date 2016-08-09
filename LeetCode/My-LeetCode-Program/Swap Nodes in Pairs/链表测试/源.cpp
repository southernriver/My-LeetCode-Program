#include<iostream>
#include<string>
#include<algorithm>

using  namespace std;

struct  ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) :val(x), next(NULL){}
};
ListNode* swapPairs(ListNode* head) {

    if (head == NULL||head->next==NULL)       return head;
    ListNode *p=head;
    ListNode *m=p->next;
    p->next = m->next;
    m->next = p;
    ListNode *q=NULL;
    ListNode *r=NULL;  
    while (p)
    {
        r=p;
        p = p->next;        
        if (p==NULL)
            break;
        q = p->next;
        if (q==NULL)
                break;
         p->next=q->next;
         q->next=p;
         r->next=q;
    }
    return  m;
}
void insert(ListNode *head, int elem)
{
    ListNode *p=new ListNode(elem); //Ҫ�볤�ڱ����㣬��Ҫ�ڶ��п�������
    ListNode *q=head;
    while (q->next)
    {
            q=q->next;
    }
    q->next=p;
}
ListNode* deleteK(ListNode *head, int k)
{
    ListNode *p=head;
    ListNode *q=NULL;
    int i = 0;
    while (p&&i<k-1)
    {       
        i++;
        q=p;
        p=p->next;
    }
    if (q==NULL)
        return head->next;
    ListNode *r=q->next;
    q->next=r->next;    
    delete r;
    return head;
}
void display(ListNode head)
{
    cout<<head.val<<"->";
    while(head.next)
    {
        cout << head.next->val << "->";
        head=*head.next;
    }
    cout<<endl;
}

int main()
{
    ListNode L(-1);    //ֻ��������һ���ṹ����,���Ǳ���ó�ʼ��


    for (int i = 0; i < 4; i++)
    {
        insert(&L,i);
    }
    display(L);


    
    ListNode *r=swapPairs(&L);
    display(*r);
    system("pause");
    return 0;
}