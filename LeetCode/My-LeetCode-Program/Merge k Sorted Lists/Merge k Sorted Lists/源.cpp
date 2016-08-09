#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode*> &lists) {
        if (lists.size()==0)
                            return NULL;
        if (lists.size()==1)
            return lists[0];
        ListNode  *p=NULL;
        if (lists[0] == NULL || lists[1] == NULL)
                p = lists[0] ? lists[1] : lists[0];
        else p=mergeTwoLists(lists[0]->next, lists[1]->next);
        for (int i = 2; i<lists.size(); i++){

            p= mergeTwoLists(p, lists[i]->next);
        }
        return p;
    }
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2){
        if (l1 == NULL || l2 == NULL)
            return l1 == NULL ? l2 : l1;

        ListNode head(-1);
        ListNode *p=&head;
        for (; l1&&l2; p = p->next){
            if (l1->val > l2->val)
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
        p->next=l1?l1:l2;
        return head.next;
    }
    void insert(ListNode *head,int num)
    {
        ListNode *q=head;

        for (int i =num; i <5+num; i++)
        {
            ListNode *p = new ListNode(i);

                 q->next=p;
                 q=q->next;
            
        }
    }
    void display(ListNode *head){
        while (head)
        {
               cout<<head->val;
                head =head ->next;
        }
        cout<<endl;
    }
};
int main()
{
    Solution s;
    ListNode l1(-1);
    l1.next=NULL;
    s.insert(&l1,3);
    s.display(l1.next);

    ListNode l2(-1);
    l2.next=NULL;
    s.insert(&l2, 2);
    s.display(l2.next);


    ListNode l3(-1);
    l3.next = NULL;
    s.insert(&l3, 4);
    s.display(l3.next);

    ListNode l4(-1);
    l4.next = NULL;
    s.insert(&l4, 1);
    s.display(l4.next);

    vector<ListNode *>  vL;
    vL.push_back(&l1);
    vL.push_back(&l2);
    vL.push_back(&l3);
    vL.push_back(&l4);


    ListNode *L= s.mergeKLists(vL);
 //   ListNode *L = s.mergeTwoLists(l1.next,l2.next);
    s.display(L); 
    //ListNode *LL = s.mergeTwoLists(L,l3.next);
    //s.display(LL);

    
    system("pause");
    return 0;
}