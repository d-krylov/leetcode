/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
  Node *cloneGraph(Node *node) {
    if (!node) {
      return nullptr;
    }
    unordered_map<Node *, Node *> m;
    stack<Node *> s;
    s.push(node);
    while (!s.empty()) {
      auto current = s.top();
      s.pop();
      auto sz = current->neighbors.size();
      auto nn = new Node(current->val, vector<Node *>(sz));
      m[current] = nn;
      for (auto x : current->neighbors) {
        if (m.find(x) == m.end()) {
          s.push(x);
        }
      }
    }
    for (auto x : m) {
      for (int i = 0; i < x.first->neighbors.size(); i++) {
        x.second->neighbors[i] = m[x.first->neighbors[i]];
      }
    }
    return m[node];
  }
};