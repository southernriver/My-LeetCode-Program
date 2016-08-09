#include<iostream>
#include"Swap Nodes.h"
using namespace std;


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *p1=l1;
    ListNode *p2=l2;
    ListNode p(-1);

    ListNode *r=&p;
    int value =0;
    int carry=0;
    while (p1||p2)
    {
        int num1 = (p1==nullptr)?0:p1->val;
        int num2 = (p2==nullptr)?0:p2->val;
        value=(carry+num1+num2)%10;
        carry = (carry + num1 + num2) / 10;
        r->next = new ListNode(value);
        r=r->next;
        p1=p1==NULL?NULL: p1=p1->next;
        p2 = p2 == NULL ? NULL : p2= p2->next;
    }
    if (carry > 0)
    {
        r->next = new ListNode(carry);
    }
    
    return p.next;
}
void insert(ListNode *l1,int elem){
    ListNode *p=l1;
    while (p->next)
    {
        p=p->next;
    }
    ListNode *q = (ListNode*)malloc(sizeof(ListNode));
    q->val=elem;
    q->next=NULL;
    p->next=q;
}
void display(ListNode *head){
    ListNode *p=head;
    while (p)
    {
        printf("%d->",p->val);
        p=p->next;
    }
    printf("\n");
}
//将链表m到n之间的数据reverse
ListNode *reverseBetween(ListNode *head, int m, int n){
    ListNode *p = head;
    ListNode *q = NULL;
    int i = 0;
    for (; i < m - 1; i++){
        q = p;         //当前要reverse的前一个结点
        p = p->next;    //当前要reverse的第一个结点
    }
    ListNode *r = p;
    //int num=0;
    //for (; i < n; i++){
    //    r=r->next;          //找到当前要reverse的最后一个结点的下一个结点
    //}
    int *A = new int[n - m + 1];
    int j = 0;
    for (; j<n - m + 1; j++){
        A[j] = p->val;
        p = p->next;
    }
    for (j = j - 1; j >= 0; j--){
        r->val = A[j];
        r = r->next;
    }
    return head;
}
ListNode *partition(ListNode *head, int x){
    ListNode *p=head;
    ListNode left(-1);
    ListNode right(-1);
    ListNode *l=&left;
    ListNode *r=&right;
    while (p)
    {
        if (p->val < x)
        {
            l->next=p;
            l=p;
        }
        else
        {
            r->next=p;
            r=p;
        }
        p=p->next;
    }
    l->next=right.next;
    r->next=nullptr;
    return left.next;
}
ListNode* deleteDuplicates(ListNode* head) {
    ListNode *p = head;
    while (p){
        ListNode *q = p->next;
        if (q == NULL)   break;
        if (p->val == q->val){
            p->next = q->next;
            delete q;
            continue;
        }
        p = p->next;
    }
    return head;
}
ListNode* deleteDuplicates2(ListNode* head) {
    if (head==nullptr)  return head;
    ListNode dummy(INT_MIN);
    dummy.next=head;
    ListNode *prev=&dummy,*cur=head;
    while (cur)
    {
        bool duplicated=false;
        while (cur->next&&cur->val==cur->next->val)
        {
            duplicated =true;
            ListNode *temp=cur;
            cur=cur->next;
            delete temp;
        }
        if (duplicated){ 
            ListNode *temp=cur;
            cur=cur->next;
            delete temp;
            continue;
        }
        prev->next=cur;
        prev=prev->next;
        cur=cur->next;
    }
    prev->next=cur;
    
    return dummy.next;
}
int main(){
    ListNode *l1 = (ListNode*)malloc(sizeof(ListNode));
    ListNode *l2 = (ListNode*)malloc(sizeof(ListNode));
    l1->val=2,l2->val=1;
    l1->next=NULL;l2->next=NULL;
    //insert(l2, 6); insert(l2,4);
    //display(l1); display(l2);

    //ListNode *res =addTwoNumbers(l1,l2);
    //display(res);
    //
    for (int i = 3; i <= 5; i++){
        insert(l1,i);
    }
    display(l1);

   /* ListNode *p = reverseBetween(l1,2,4);
    display(p);
    partition(l1,3);*/
   
    //insert(l2, 2); insert(l2, 2); insert(l2,3);
    //display(l2);
    //ListNode *res = deleteDuplicates2(l2);
    //display(res);


    ListNode *res = swapPairs1(l1);
    display(res);

    system("pause");
}