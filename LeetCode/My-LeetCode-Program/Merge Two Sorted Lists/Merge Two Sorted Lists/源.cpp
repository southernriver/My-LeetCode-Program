#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
 };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL || l2 == NULL)
            return l1 == NULL ? l2 : l1;
        ListNode *L=(ListNode*)malloc(sizeof(ListNode));
        ListNode *p=L;
        while(l1&&l2)
        {
            while (l2&&(l1->val>=l2->val))
            {
                p->next=l2;
                p=p->next;
                l2=l2->next;
            }
            if (l2==NULL)   break;
            while (l1&&(l1->val < l2->val))
            {

                p->next = l1;
                p = p->next;
                l1 = l1->next;
            }   
        }
        p->next = l1==NULL?l2:l1;
        return L->next;
    }

    void Insert(ListNode **L, int elem)
    {
 
        ListNode *p = (ListNode*)malloc(sizeof(ListNode));
        p->val=elem;
        p->next=NULL;
        if (*L== NULL){
            *L = (ListNode*)malloc(sizeof(ListNode));
            (*L)->next=NULL;
            (*L)->val=elem;
        }
        else
        {
            p->next=*L;
            *L=p;
        } 
   
    }
    void  Display(ListNode *L)
    {
        ListNode *p=L;
        while (p)
        {   
            cout << p->val << "->";
            p=p->next;
        }
    cout<<endl;
    }
};


int main()
{
    Solution s;
    ListNode *L1=NULL,*L2=NULL;
  //  for (int i=4;i>=0;i--)
  //  { 
         s.Insert(&L1, 2);  
         s.Insert(&L2,1);
    //}
    s.Display(L1);
    s.Display(L2);
    ListNode *L=s.mergeTwoLists(L1,L2);
    s.Display(L);
    system("pause");
    return 0;
}