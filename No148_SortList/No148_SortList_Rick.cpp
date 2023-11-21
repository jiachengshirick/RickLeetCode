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
    ListNode *sortList(ListNode *head) {
        head = quickSort(head, NULL);
        return head;
    }

private:
    // TODO: Add three edge cases: ListSize equal 0, 1, 2
    ListNode *quickSort(ListNode *head, ListNode *tail) {
        if (!head || head == tail) {
            return head;
        }
        ListNode *pivot = head;
        ListNode *slowerPtr = pivot;
        ListNode *fasterPtr = slowerPtr->next;
        if (!(head->next->next)) {
            if (fasterPtr->val < pivot->val) {
                slowerPtr->next = fasterPtr->next;
                fasterPtr->next = head;
                head = fasterPtr;
            }
            return head;
        }
        do {
            if (fasterPtr->val < pivot->val) {
                slowerPtr->next = fasterPtr->next;
                fasterPtr->next = head;
                head = fasterPtr;
                fasterPtr = slowerPtr->next;
            } else {
                slowerPtr = slowerPtr->next;
                fasterPtr = slowerPtr->next;
            }
        } while (fasterPtr);
        tail = slowerPtr;
        head = quickSort(head, pivot);
        pivot->next = quickSort(pivot->next, tail);
        return head;
    }
};