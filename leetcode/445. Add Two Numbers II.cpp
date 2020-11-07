// You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Follow up:
// What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

// Example:

// Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 8 -> 0 -> 7

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n1=len(l1);
        int n2=len(l2);
        if(n1<n2){
            swap(l1,l2);
            swap(n1,n2);
        }
        n1-=n2;
        bool carry=0;
        ListNode* ans= add(l1,l2,n1,n2,carry);
        if(carry){
            ListNode* temp=new ListNode;
            temp->val=1;
            temp->next=ans;
            ans=temp;
        }
        return ans;
    }
private:
    int len(ListNode* l){
        int n=0;
        while(l){
            l=l->next;
            n++;
        }
        return n;
    }
    ListNode* add(ListNode* l1,ListNode* l2,int n1,int n2,bool& carry){
        ListNode* ans=NULL;
        if(n1>0)
            ans=add(l1->next,l2,n1-1,n2,carry);
        else if(n2>1)
            ans=add(l1->next,l2->next,n1,n2-1,carry);
        ListNode *temp=new ListNode;
        temp->val=l1->val+(n1==0?l2->val:0)+carry;
        if(temp->val>9){
            temp->val-=10;
            carry=1;
        }
        else
            carry=0;
        temp->next=ans;
        ans=temp;
        return ans;
    }
};
