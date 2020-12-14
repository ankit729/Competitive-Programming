// Reverse a linked list from position m to n. Do it in one-pass.

// Note: 1 ≤ m ≤ n ≤ length of list.

// Example:

// Input: 1->2->3->4->5->NULL, m = 2, n = 4
// Output: 1->4->3->2->5->NULL

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m>n)
            swap(m,n);
        ListNode* curr=head,*prev=NULL;
        while(m>1){
            prev=curr;
            curr=curr->next;
            --m;
            --n;
        }
        ListNode* con=prev,*tail=curr;
        while(n>0){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
            --n;
        }
        if(con)
            con->next=prev;
        else
            head=prev;
        tail->next=curr;
        return head;
    }
};
