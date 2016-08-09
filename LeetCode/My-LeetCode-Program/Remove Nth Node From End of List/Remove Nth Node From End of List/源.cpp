#include<stdio.h>
#include<stdlib.h>
#include<string.h>


/**
ע���ͷ���Ͳ���ͷ����������Ŀ����˵��Ϊ׼��
**/
struct ListNode {
    int val;
    ListNode *next;
};
#include"����һ��.h"
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

//1 ���ȱ�������ȷ�����ĸ���
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

//ɾ��������k�����
/**
ע���ͷ���Ͳ���ͷ��������leetcode�����������Ĭ�ϲ���ͷ��㣬����head�洢�ľ��ǵ�һ��Ԫ��
**/
ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    ListNode *p=head->next;
    ListNode *q=NULL;
 
    //�ҵ���˳����n-1�����q
    for (int i = 0; i < LengthOfList(head)-n && p; i++)
    {
            q=p;
            p=p->next;
    }
    //���qΪ�գ�˵����ɾ���Ľ���ǵ�һ����㣬��������n�����
    if (q == NULL)
    {
        head->next=p->next;  
        free(p);                //�ͷ�ͷ���
        
    }
    //
    else
    {
        ListNode *r=q->next;
        q->next=r->next;
        free(r);
    }
    return head;    //����ͷ���
}
int main()
{
    ListNode *head = (ListNode*)malloc(sizeof(ListNode));
    head->val=10;
    head->next=NULL;

    for (int i=0;i<1;i++)
        Insert(head,i);
    Display(head);
    printf("����ĳ���:%d\n", LengthOfList(head));

    int k=1;
    //��ͷ���
    //ListNode *r = removeNthFromEnd(head, k);
    //printf("ɾ��������%d������\n",k);
    //Display(r);

   
    printf("\n\ntest1,����ͷ���\n");
    ListNode *r1=removeNthFromEnd1(head,k);
    printf("ɾ��������%d������\n",k);
    Display(r1);
    system("pause");
    return 0;
}