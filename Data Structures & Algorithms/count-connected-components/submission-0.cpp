class Solution {

    void traverseThisComponent(int currNode, vector<vector<int>>& graph, vector<bool>& visited) {
        visited[currNode] = true;

        for(int neighbourNode: graph[currNode]) {
            if(!visited[neighbourNode]) {
                traverseThisComponent(neighbourNode, graph, visited);
            }
        }
    }

public:
    int countComponents(int n, vector<vector<int>>& edges) {
        // So, we have n nodes in the graph right?
        // And the values of nodes vary from 0 to (n - 1).

        // Let's first build an adjacency list for this graph

        // We'll maintain a map which maps a node to the it is further connected and call this map as an adjacency list because for each element it contains the elements adjacent to that element.

        vector<vector<int>> graph(n);

        for(vector<int> edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        // Now, if we have the nodes numbered from 0 to 4 a total of 5 nodes then 0 might be connected to 1, 1 might be connected to 2 and maybe neither of these 3 are connected to the nodes 3 & 4.
        // Thus, if we wanted to go from node 0 to node 3 just by travelling through edges I would not be able to do I would have to pick the node 3 separately to visit the rest of the nodes in the graph.
        // I suppose, we have to figure out the number of times we have to pick up a node separately in order to visit all of the nodes in the graph.
        // Our approach is the same as we discussed above we keep picking up nodes that have not been visited by travelling edges from the nodes we just discovered earlier. when we do get across a node that has not yet been visited we go through all the nodes that are connected to this and mark them as visited so as to not count a component twice.

        vector<bool> visited(n, false);
        int numberOfComponents = 0;

        for(int i = 0; i < n; i++) {
            int currNode = i;

            if(!visited[currNode]) {
                traverseThisComponent(currNode, graph, visited);
                numberOfComponents++;
            }
        }

        return numberOfComponents;
    }
};
