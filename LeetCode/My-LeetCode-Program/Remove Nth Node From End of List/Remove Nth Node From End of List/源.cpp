#include<stdio.h>
#include<stdlib.h>
#include<string.h>


/**
注意带头结点和不带头结点的区别（题目给定说明为准）
**/
struct ListNode {
    int val;
    ListNode *next;
};
#include"遍历一次.h"
void Insert(ListNode *head, int elem)
{
    ListNode *p = (ListNode*)malloc(sizeof(ListNode));
    p->val=elem;
    p->next=NULL;
    if (head->next==NULL)
        head->next=p;
    else
    {
        p->next = head->next;
        head->next=p;
    }
}
void Display(ListNode *head)
{
    ListNode *p=head;
    while (p)
    {
        printf("%d->",p->val);
        p=p->next;
     }
    printf("\n");
}

//1 首先遍历链表，确定结点的个数
int LengthOfList(ListNode *head)
{
    int num = 0;
    while (head->next)
    {
        num++;
        head = head->next;
    }
    return num;
}

//删除倒数第k个结点
/**
注意带头结点和不带头结点的区别，leetcode上面的做法是默认不带头结点，所以head存储的就是第一个元素
**/
ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    ListNode *p=head->next;
    ListNode *q=NULL;
 
    //找到第顺数第n-1个结点q
    for (int i = 0; i < LengthOfList(head)-n && p; i++)
    {
            q=p;
            p=p->next;
    }
    //如果q为空，说明所删除的结点是第一个结点，即倒数第n个结点
    if (q == NULL)
    {
        head->next=p->next;  
        free(p);                //释放头结点
        
    }
    //
    else
    {
        ListNode *r=q->next;
        q->next=r->next;
        free(r);
    }
    return head;    //返回头结点
}
int main()
{
    ListNode *head = (ListNode*)malloc(sizeof(ListNode));
    head->val=10;
    head->next=NULL;

    for (int i=0;i<1;i++)
        Insert(head,i);
    Display(head);
    printf("链表的长度:%d\n", LengthOfList(head));

    int k=1;
    //带头结点
    //ListNode *r = removeNthFromEnd(head, k);
    //printf("删除倒数第%d个结点后：\n",k);
    //Display(r);

   
    printf("\n\ntest1,不带头结点\n");
    ListNode *r1=removeNthFromEnd1(head,k);
    printf("删除倒数第%d个结点后：\n",k);
    Display(r1);
    system("pause");
    return 0;
}