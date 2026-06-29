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

    Node* helper(Node* node, unordered_map<int, Node*>& nodeMap) {
        if(node == NULL) {
            return node;
        }

        Node* cloneNode = new Node(node -> val);
        nodeMap[cloneNode -> val] = cloneNode;

        for(int i = 0; i < ((node -> neighbors).size()); i++) {
            if(nodeMap.find((node -> neighbors)[i] -> val) != nodeMap.end()) {
                (cloneNode -> neighbors).push_back(nodeMap[(node -> neighbors)[i] -> val]);
                continue;
            }
            Node* newChildNode = helper((node -> neighbors)[i], nodeMap);
            (cloneNode -> neighbors).push_back(newChildNode);
            cout << (node -> val) << " " << i << " " << ((node -> neighbors)[i] -> val) << endl;
        }

        return cloneNode;
    }

public:
    Node* cloneGraph(Node* node) {
        unordered_map<int, Node*> nodeMap;

        return helper(node, nodeMap);
    }
};
