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
//     bool hasCycle(ListNode* head) {
//         vector<ListNode*> nodes;
//         ListNode* aux = head;

//         while(aux) {
//             nodes.push_back(aux);
//             if (find(nodes.begin(), nodes.end(), aux->next) != nodes.end()) {
//                 return true;
//             }
//             aux = aux->next;
//         }
//         return false;
//     }
// };

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (!head || !head->next) {
            return false;  
        }

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (slow != fast) {
            if (!fast || !fast->next) {
                return false;  
            }
            slow = slow->next;
            fast = fast->next->next;
        }

        return true;
    }
};