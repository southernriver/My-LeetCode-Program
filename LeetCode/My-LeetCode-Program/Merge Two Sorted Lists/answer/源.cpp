#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) :val(x), next(NULL){}
};

class Solution
{
public:
    ListNode mergeTwoLists(ListNode* l1, ListNode* l2) {

        if (l1==NULL||l2==NULL)
            return l1==NULL?*l2:*l1;
        ListNode head(-1);
        head.next=NULL;
         ListNode *p=&head;
         for (; l1&&l2; p = p->next)
         {
             if (l1->val>=l2->val)
             {
                  p->next=l2;
                  l2=l2->next;
             }
             else
             {
                 p->next=l1;
                 l1=l1->next;
             }
         }
        p->next = (l1==NULL)?l2:l1;
        return head;
    }
    void insert1(ListNode *head)
    {
         ListNode *p=head;
        
         for (int i = 0; i < 6; i++)
         {
            ListNode *q = (ListNode*)malloc(sizeof(ListNode));
            q->val=i;
            p->next=q;
            p=p->next;
         }
         p->next=NULL;
    }
    void insert2(ListNode *head)
    {
        ListNode *p = head;

        for (int i = 2; i < 8; i++)
        {
            ListNode *q = (ListNode*)malloc(sizeof(ListNode));
            q->val = i;
            p->next = q;
            p = p->next;
        }
        p->next = NULL;
    }

    void display(ListNode head)
    {
        while (head.next)
        {
            cout << head.next->val << "->";
            head.next=head.next->next;
        }
        cout<<endl;
    }
};

int main()
{
    Solution s;
    ListNode l1(-1000);
    
    s.insert1(&l1);
    s.display(l1);


    ListNode l2(-1000);
    s.insert2(&l2);
    s.display(l2);

    
    ListNode head(-1);
    head=s.mergeTwoLists(l1.next,l2.next);
    cout<<head.val<<" "<<head.next->val<<endl;
    s.display(head); 
    s.display(head);
    system("pause");
    return 0;
}