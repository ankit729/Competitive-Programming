// Given the head of a linked list, return the list after sorting it in ascending order.

// Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?

 

// Example 1:


// Input: head = [4,2,1,3]
// Output: [1,2,3,4]
// Example 2:


// Input: head = [-1,5,3,4,0]
// Output: [-1,0,3,4,5]
// Example 3:

// Input: head = []
// Output: []
 

// Constraints:

// The number of nodes in the list is in the range [0, 5 * 10^4].
// -10^5 <= Node.val <= 10^5

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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* mid=getMid(head);
        return merge(sortList(head),sortList(mid));
    }
private:
    ListNode* getMid(ListNode* head) {
        ListNode dummy(0,head);
        ListNode* prev=&dummy;
        while(head && head->next){
            prev=prev->next;
            head=head->next->next;
        }
        ListNode* mid=prev->next;
        prev->next=NULL;
        return mid;
    }
    ListNode* merge(ListNode* l, ListNode* r) {
        ListNode dummy;
        ListNode* prev=&dummy;
        while(l && r){
            if(l->val<=r->val){
                prev->next=l;
                l=l->next;
            }
            else{
                prev->next=r;
                r=r->next;
            }
            prev=prev->next;
        }
        if(l)
            prev->next=l;
        else
            prev->next=r;
        return dummy.next;
    }
};
