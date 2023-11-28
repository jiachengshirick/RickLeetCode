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
        ListNode* mid = getMid(head);
        ListNode* h1 = sortList(head);
        ListNode* h2 = sortList(mid->next);
        return mergeSort(head);
    }

private:
    ListNode* mergeSort(ListNode* head, ListNode* tail) {
        if(!head || head==tail) return head;
        if(!head->next) return head;
        ListNode* mid = getMid(head, tail);
        ListNode* h1 = mergeSort(head, mid);
        ListNode* h2 = mergeSort(mid->next, tail);
        ListNode* dummyHead = new ListNode();
        ListNode* ptrDummy = dummyHead;
        while(h1!=tail){
            if (h2!=tail->next && h2->val < h1->val){
                ptrDummy->next = new ListNode(h2->val);
                h2 = h2->next;
                ptrDummy = ptrDummy->next;
            } else {
                ptrDummy->next = new ListNode(h1->val);
                h1 = h1->next;
                ptrDummy = ptrDummy->next;
            }
            if (h1 == h2) break;
        }
        return dummyHead->next;
    }

    ListNode* swapNumber(ListNode* first, ListNode* second){
        ListNode* tmp = second;
        ListNode* beforeSecond = first;
        while(beforeSecond->next!=second){
            beforeSecond = beforeSecond->next;
        }
        beforeSecond->next = second->next;
        tmp->next = first;
        first = tmp;
        return tmp;
    }

    ListNode* getMid(ListNode* head, ListNode* tail) {
        ListNode* ptr = head;
        ListNode* tailPtr = tail;
        while (ptr->next && ptr->next->next){
            if (ptr->next == tail) {
                tail = ptr;
                break;
            }
            ListNode* tmp = ptr->next;
            ptr->next = ptr->next->next;
            tmp->next = tailPtr->next;
            tailPtr->next = tmp;
            tailPtr = tailPtr->next;
            ptr = ptr->next;
            if (ptr == tail) break;
        }
        return tail;
    }

    ListNode* getTail(ListNode* head) {
        if (!head) return head;
        if (!head->next) return head;
        ListNode* tail = head;
        while(tail->next){
            tail = tail->next;
        }
        return tail;
    }

};