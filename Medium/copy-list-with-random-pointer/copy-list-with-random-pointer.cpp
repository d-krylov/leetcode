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
  Node *copyRandomList(Node *head) {
    if (!head) {
      return nullptr;
    }
    unordered_map<Node *, Node *> m;
    stack<Node *> s;
    s.push(head);
    while (!s.empty()) {
      auto node = s.top();
      s.pop();
      auto new_node = new Node(node->val);
      m[node] = new_node;

      if (node->next) {
        if (m.find(node->next) == m.end()) {
          s.push(node->next);
        }
      }
      if (node->random) {
        if (m.find(node->random) == m.end()) {
          s.push(node->random);
        }
      }
    }
    for (auto x : m) {
      x.second->next = x.first->next ? m[x.first->next] : nullptr;
      x.second->random = x.first->random ? m[x.first->random] : nullptr;
    }
    return m[head];
  }
};