class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // So, the signal transmitters make a kind of network and each edge goes only one way and that is from source to target.
        // Thus, this network of signal transmitters and recievers can be depicted as a unidirectional graph.
        // So, let me make an adjacency list first which makes things clearer.

        vector<vector<vector<int>>> network(n + 1);

        for(vector<int> edge: times) {
            network[edge[0]].push_back({edge[1], edge[2]});
        }

        queue<int> nodes;
        vector<int> minimumTime(n + 1, INT_MAX);

        minimumTime[k] = 0;
        nodes.push(k);

        while(!nodes.empty()) {
            int currNode = nodes.front();
            nodes.pop();

            for(auto edge: network[currNode]) {
                if((minimumTime[currNode] + edge[1]) < minimumTime[edge[0]]) {
                    minimumTime[edge[0]] = minimumTime[currNode] + edge[1];
                    nodes.push(edge[0]);
                }
            }
        }

        int ans = 0;

        for(int i = 1; i <= n; i++) {
            ans = max(ans, minimumTime[i]);
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};