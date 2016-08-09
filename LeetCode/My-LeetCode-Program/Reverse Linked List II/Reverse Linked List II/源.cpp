#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) :val(x), next(NULL){}
};
//将链表m到n之间的数据reverse
ListNode *reverseBetween(ListNode *head, int m, int n){
    ListNode *p=head;
    ListNode *q=NULL;
    int i=0;
    for ( ;i < m-1; i++){
        q=p;         //当前要reverse的前一个结点
        p=p->next;    //当前要reverse的第一个结点
    }
    ListNode *r=p;
    //int num=0;
    //for (; i < n; i++){
    //    r=r->next;          //找到当前要reverse的最后一个结点的下一个结点
    //}
    int *A = new int[n-m+1];
    int j=0;
    for (; j<n - m + 1; j++){
        A[j]=p->val;
        p=p->next;
    }
    for (j=j-1; j >= 0; j--){
        r->val = A[j];
        r=r->next;
    }
    return head;
}
int main(){




    system("pause");
    return 0;
}