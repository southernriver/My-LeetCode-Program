#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    ListNode* swapPairs(ListNode* head) {
    ListNode *p=head;
    while (p->next)
    {
        
        ListNode *q=p->next;
        p->next=q->next;
        q->next=p;
    }
    return p;    
    }
    
    void insert(ListNode *head){
    ListNode *p=head;
        for (int i=1;i<=5;i++)
        { 
            ListNode * q = new ListNode(i);
            q->next=NULL;
            p->next=q;
            p=p->next;
        }
    }
    void display(ListNode *head){
        while (head)
        {
            cout << head->val << "->";
            head=head->next;
        }
        cout<<endl;
    }

};

int main()
{
    Solution s;
    ListNode  l1(-1);
    s.insert(&l1); 
    s.display(&l1); s.display(&l1);
   // ListNode *r=s.swapPairs(&l1);
  //  s.display(*r);


    system("pause");
    return 0;
}