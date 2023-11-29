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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 && !list2) return list1;
        if(!list1) return list2;
        if(!list2) return list1;
        ListNode* list1Ptr = list1;
        ListNode* list2Ptr = list2;
        ListNode* dummyHead = new ListNode(0);
        ListNode* dummyHeadPtr = dummyHead;
        while(list1Ptr || list2Ptr){
            if (!list1Ptr){
                dummyHeadPtr->next = new ListNode(list2Ptr->val);
                dummyHeadPtr = dummyHeadPtr->next;
                list2Ptr = list2Ptr->next;
                continue;
            }
            if (!list2Ptr){
                dummyHeadPtr->next = new ListNode(list1Ptr->val);
                dummyHeadPtr = dummyHeadPtr->next;
                list1Ptr = list1Ptr->next;
                continue;
            }
            if (list1Ptr->val < list2Ptr->val){
                dummyHeadPtr->next = new ListNode(list1Ptr->val);
                dummyHeadPtr = dummyHeadPtr->next;
                list1Ptr = list1Ptr->next;
                continue;
            } else if(list1Ptr->val >= list2Ptr->val){
                dummyHeadPtr->next = new ListNode(list2Ptr->val);
                dummyHeadPtr = dummyHeadPtr->next;
                list2Ptr = list2Ptr->next;
                continue;
            }
        }
        return dummyHead->next;
    }
};

