#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) :val(x), next(NULL){}
};
//������m��n֮�������reverse
ListNode *reverseBetween(ListNode *head, int m, int n){
    ListNode *p=head;
    ListNode *q=NULL;
    int i=0;
    for ( ;i < m-1; i++){
        q=p;         //��ǰҪreverse��ǰһ�����
        p=p->next;    //��ǰҪreverse�ĵ�һ�����
    }
    ListNode *r=p;
    //int num=0;
    //for (; i < n; i++){
    //    r=r->next;          //�ҵ���ǰҪreverse�����һ��������һ�����
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