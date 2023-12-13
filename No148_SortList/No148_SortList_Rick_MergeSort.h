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
        return mergeSort(head);
    }

private:
    ListNode* mergeSort(ListNode* head) {
        if(!head) return head;
        if(!head->next) return head;
        ListNode* mid = getMid(head);
        ListNode* h1 = mergeSort(head);
        ListNode* h2 = mergeSort(mid);
        ListNode* dummyHead = sortOperator(h1, h2);
        return dummyHead;
    }

    ListNode* sortOperator(ListNode* h1, ListNode* h2){
        ListNode* h1ptr = h1;
        ListNode* h2ptr = h2;
        ListNode* dummyHead = new ListNode();
        ListNode* ptrDummy = dummyHead;
        //TODO: H1 finished first, H2 Finished first. one by one
        while (h1ptr!=NULL || h2ptr!=NULL){
            if (h1ptr==NULL) {
                ptrDummy->next = h2ptr;
                h2ptr = NULL;
                continue;
            }
            if (h2ptr==NULL) {
                ptrDummy->next = h1ptr;
                h1ptr = NULL;
                continue;
            }
            if(h1ptr->val<h2ptr->val){
                ptrDummy->next = h1ptr;
                h1ptr = h1ptr->next;
                ptrDummy = ptrDummy->next;
            } else {
                ptrDummy->next = h2ptr;
                h2ptr = h2ptr->next;
                ptrDummy = ptrDummy->next;
            }

        }
        return dummyHead->next;
    }

    ListNode* getMid(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = head;
        while(fast!=NULL&&fast->next!=NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        return slow;
    }
};