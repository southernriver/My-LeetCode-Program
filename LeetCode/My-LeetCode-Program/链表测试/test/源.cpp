#include<iostream>
#include<algorithm>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) :val(x), next(NULL){ printf("¹¹Ôìº¯Êý...\n"); }
};
ListNode *test(ListNode *head){
    ListNode p(100);
    ListNode l(34);
    p.next=&l;

    return &p;
}
int main(){

    ListNode *head =(ListNode*)malloc(sizeof(ListNode));
    head->val=12;head->next=NULL;
    ListNode *res=test(head);
    cout<<res->val<<res->next->val<<endl;

    system("pause");
    return 0;
}