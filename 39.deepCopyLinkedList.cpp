/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr; 

        unordered_map<Node*, Node*> umap; 
        Node* aux = head;
        Node* res = new Node(aux->val);
        umap[aux] = res;

        Node* list = res;

        while (aux) {
            if (aux->next) {
                if (umap.find(aux->next) == umap.end()) {
                    umap[aux->next] = new Node(aux->next->val);
                }
                list->next = umap[aux->next];
            }
            if (aux->random) {
                if (umap.find(aux->random) == umap.end()) {
                    umap[aux->random] = new Node(aux->random->val);
                }
                list->random = umap[aux->random];
            }
            aux = aux->next;
            list = list->next;
        }

        return res;
    }
};