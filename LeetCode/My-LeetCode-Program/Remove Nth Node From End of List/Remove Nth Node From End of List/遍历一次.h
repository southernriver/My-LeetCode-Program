
struct ListNode* removeNthFromEnd1(struct ListNode* head, int n){
    ListNode *p=head;
    ListNode *q=head;
    for (int i = 0; p&&i < n; i++)
    {
        p=p->next;
    }
    ListNode *r=NULL;
    while (p)
    {
          p=p->next;
          r=q;
          q=q->next;
    }
    if (r==NULL){
            head=q->next;
            free(q);}
    else
    {
            r->next=q->next;
            free(q);
    }

    return head;
}