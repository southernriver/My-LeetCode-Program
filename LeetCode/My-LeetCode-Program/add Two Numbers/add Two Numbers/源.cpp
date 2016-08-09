#include<iostream>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    
    ListNode *dummy=new ListNode(-1);
    ListNode *prev=dummy;
    ListNode *al=l1,*bl=l2;
    int carry=0;    
    while (al!=NULL||bl!=NULL)
    {

       
        const int ai=al==nullptr?0:al->val;
        const int bi=bl==nullptr?0:bl->val;
        cout << "ai=" << ai << ",bi="<<bi<<endl;


        const int value=(ai+bi+carry)%10;
        cout<<value<<endl;
        carry = (ai+bi+carry)/10;
        prev->next = new ListNode(value);
        prev=prev->next;
        prev->next=NULL; 
       if (al)
            al=al->next;
        if (bl)
            bl=bl->next;
    }
    if (carry>0)
        prev->next = new ListNode(carry);
    
    return dummy->next;
        
    }
};
int main()
{
    
    int input1[] = {1,2}; 
    ListNode *l1 = new  ListNode(input1[0]);
    ListNode *rear1=l1;   


    for (int i=1;i<2;i++)
    {
        ListNode *p = new ListNode(input1[i]);
        rear1->next=p;
        rear1=p;
        rear1->next=NULL;
    }

    int input2[] = { 3,9, 5 };
    ListNode *l2 = new  ListNode(input2[0]);
    ListNode *rear2 = l2;
    

    for (int j = 1; j<3; j++)
    {
        ListNode *q = new ListNode(input2[j]);
        rear2->next = q;
        rear2 = q;
        rear2->next = NULL;
    }


   



    Solution s;
    ListNode *output = s.addTwoNumbers(l1,l2);


  
    ListNode *pre=output;
    while (pre)
    {
        cout << pre->val;
        pre=pre->next;
    }
    cout<<endl;


    system("pause");
    return 0;
}