class Solution {

    bool detectCycle(int currNode, vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& recentlyVisited) {
        visited[currNode] = true;
        recentlyVisited[currNode] = true;

        for(int neighbour: graph[currNode]) {
            if(recentlyVisited[neighbour] || ((!visited[neighbour]) && detectCycle(neighbour, graph, visited, recentlyVisited))) {
                return true;
            }
        }

        recentlyVisited[currNode] = false;

        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // If I have a prerequisite condition let's say [a, b] then this means that if I want to sit in the course b I first need to finish course a, right?
        // And we have to figure out if we can finish all the courses eventually.
        // Let's brainstorm upon the situations where one might not be able to finish all the courses.
        // For example, if we have a prerequisite list [[a, b], [b, c], [c, a]] then in this case to pursue course b one needs to first finish course a, and to pursue course a one needs to pursue c and to pursue c finishing course b is required - thus, we are back to square because all these courses are interdependent, one cannot order them in an order where all of them can be pursued one after another.
        // Thus, it makes sense to create a directed graph from these courses where a directed edge [a -> b] would mean one needs to finish course a in order to pursue course b.
        // If we find a cycle in this directed graph it will create a condition like the one we witnessed above, and it will be difficult for a student to arrange the courses in a valid order so as to follow them all.

        vector<vector<int>> graph(numCourses);

        for(vector<int> prerequisite: prerequisites) {
            graph[prerequisite[0]].push_back(prerequisite[1]); // prerequisite[0] depends on prerequisite[1].
        }

        vector<bool> visited(numCourses, false);
        vector<bool> recentlyVisited(numCourses, false);

        for(int i = 0; i < numCourses; i++) {
            if((!visited[i]) && detectCycle(i, graph, visited, recentlyVisited)) {
                return false;
            }
        }

        return true;
    }
};