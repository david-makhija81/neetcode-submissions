class Solution {

    bool detectCycle(int currNode, vector<vector<int>>& graph, vector<bool>& visited, int parent) {
        visited[currNode] = true;

        for(int neighbour: graph[currNode]) {
            if(neighbour == parent) {
                continue;
            }

            if(visited[neighbour] || detectCycle(neighbour, graph, visited, currNode)) {
                return true;
            }
        }

        return false;
    }

    void traverseThisComponent(int currNode, vector<vector<int>>& graph, vector<bool>& visited) {
        visited[currNode] = true;

        for(int neighbour: graph[currNode]) {
            if(!visited[neighbour]) {
                traverseThisComponent(neighbour, graph, visited);
            }
        }
    }

    bool isConnected(vector<vector<int>>& graph, int n) {
        int numberOfComponents = 0;
        vector<bool> visited(n, false);

        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                traverseThisComponent(i, graph, visited);
                numberOfComponents++;
            }
        }        

        return (numberOfComponents == 1);
    }

public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // Is it a connected graph?
        // Are there double edges in the graph or any self loops?

        // Let's make an adjacency list which stores for each element it's neighbours

        vector<vector<int>> graph(n);

        for(vector<int> edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        // So, a graph valid tree if and only if any of the child nodes of any does not point to a parent node.
        // Thus, in other words we have to just figure out if a node eventually points to a parent of it's parent node that has already been visited.

        vector<bool> visited(n, false);

        return ((!detectCycle(0, graph, visited, -1)) && isConnected(graph, n));
    }
};
