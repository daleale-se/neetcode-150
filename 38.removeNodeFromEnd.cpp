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

// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
        
//         int size = 0;
//         ListNode* aux = head;
//         while (aux){
//             aux = aux->next;
//             size++;
//         }

//         int removeIndex = size - (n - 1);
//         int counter = 0;
//         aux = head;
//         ListNode* prev = nullptr;

//         while(aux) {
//             counter++;
//             if (counter == removeIndex) {
//                 if (prev == nullptr) {
//                     return aux->next;
//                 } else if (counter == size) {
//                     prev->next = nullptr;
//                     return head;
//                 } else {
//                     prev->next = aux->next;
//                     return head;
//                 }
//             }
//             prev = aux;
//             aux = aux->next;
//         }
//     }
// };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);  
        ListNode* first = dummy;
        ListNode* second = dummy;
        
        for (int i = 0; i <= n; i++) {
            first = first->next;
        }
        
        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }
        
        second->next = second->next->next;
        
        return dummy->next;
    }
};