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

    void makeNodeCopies(Node* currNode, unordered_map<int, Node*>& copyNodes, vector<bool>& visited) {
        visited[currNode -> val] = true;

        Node* currNodeCopy = new Node(currNode -> val);

        copyNodes.insert({currNode -> val, currNodeCopy});

        for(Node* neighbour: (currNode -> neighbors)) {
            if(!visited[neighbour -> val]) {
                makeNodeCopies(neighbour, copyNodes, visited);
            }
        }
    }

    void makeConnections(Node* currNode, unordered_map<int, Node*>& copyNodes, vector<bool>& visited) {
        visited[currNode -> val] = true;

        for(Node* neighbour: (currNode -> neighbors)) {
            (copyNodes[currNode -> val] -> neighbors).push_back(
                copyNodes[neighbour -> val]
            );

            if(!visited[neighbour -> val]) {
                makeConnections(neighbour, copyNodes, visited);
            }
        }
    }

public:
    Node* cloneGraph(Node* node) {
        // Does it have to be a shallow copy or a deep copy?
        // Is it a directed or undirected graph?
        // Is the graph cyclic or acyclic?
        // Do the integer values repeat in the graph?

        if(node == NULL) {
            return NULL;
        }

        // The approach looks kind of straightforward make deep copy of current node.
        // Go to it's neighbours make a deep copy of them and connected their deep copies to this node's deep copy.
        // But this approach might fail in case of cyclic graphs, as we might risk making a node twice.
        // Or even if we keep track of visited nodes and take care of not making two copies of one node even then connecting a previously made node searching for it might be a bit of a hassle.
        // Thus, an approach without any caveates is if we explore all the nodes store their copies in a structure which maps integer value keys against Graph Nodes.
        // And then connecting the copies according to how the actual graph is connected.

        unordered_map<int, Node*> copyNodes;
        vector<bool> visited(101, false); // To avoid going in cycles.

        makeNodeCopies(node, copyNodes, visited);

        for(int i = 0; i <= 100; i++) {
            visited[i] = false;
        }

        makeConnections(node, copyNodes, visited);

        return copyNodes[1];
    }
};