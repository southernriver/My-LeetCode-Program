struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) :val(x), next(NULL){ printf("¹¹Ôìº¯Êý...\n"); }
};
ListNode *swapPairs(ListNode *head){
    if (head==nullptr||head->next==nullptr)  return head;
    ListNode *p=head;
    for (ListNode *prev = p, *cur = prev->next, *next = cur->next; next;
        prev = cur, cur = cur->next, next = cur ? cur->next : nullptr){
        prev->next=next;
        cur->next=next->next;
        next->next=cur;
    }
    return p;
}
ListNode* swapPairs1(ListNode* head) {
    if (head == NULL || head->next == NULL)       return head;
    ListNode *p=head;
    ListNode *q=p->next;
    ListNode *h=q;  
    p->next=q->next;
    q->next=p;
    
    while (p)
    {
         ListNode *r=p;
         p=p->next;
         if (p==NULL) break;
         h=p->next;
         if (p==NULL) break;
         p->next = h->next;
         h->next = p;
         r->next = h;
    }
    return q;

}