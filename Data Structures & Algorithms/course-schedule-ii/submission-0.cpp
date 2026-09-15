class Solution {

    bool isValid(
        int currNode, vector<vector<int>>& depGraph, vector<bool>& compVisited, vector<bool>& visited
    ) {
        for(int neighbour: depGraph[currNode]) {
            if(visited[neighbour]) {
                return false;
            }

            if(!compVisited[neighbour]) {
                compVisited[neighbour] = true;
                visited[neighbour] = true;
                if(!isValid(neighbour, depGraph, compVisited, visited)) {
                    return false;
                }
                visited[neighbour] = false;
            }
        }

        return true;
    }
    
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> depGraph(numCourses);
        vector<vector<int>> revDepGraph(numCourses);

        for(auto prerequisite: prerequisites) {
            depGraph[prerequisite[0]].push_back(prerequisite[1]);
            revDepGraph[prerequisite[1]].push_back(prerequisite[0]);
        }

        vector<bool> compVisited(numCourses, false);

        vector<bool> visited(numCourses, false);

        for(int i = 0; i < numCourses; i++) {
            if(!compVisited[i]) {
                compVisited[i] = true;
                visited[i] = true;
                if(!isValid(i, depGraph, compVisited, visited)) {
                    return {};
                }
                visited[i] = false;
            }
        }

        // Now that we have validated, if we can pursue all the courses, what we can do now is, to map the prerequisites with the courses, that this is a prerequisite of.
        // this way, what we can do is that we can identify the courses that do not have any prerequisites at all. After we have identified all the courses that do not have any prerequisites, we do those courses, and we, as we do one course, we kind of eliminate the prerequisite of another course that this course was a prerequisite of.
        // Uh-huh. So this way we can, you know, cross keep crossing off those prerequisites. And as we keep crossing off those prerequisites. Eventually, um, the list of prerequisites for, for the list of prerequisites, for a number of courses would clear up, then we can do those, and this goes on.

        vector<int> reqRemain(numCourses, 0);

        queue<int> pursueCourses;

        vector<int> ans;

        for(int i = 0; i < numCourses; i++) {
            reqRemain[i] = depGraph[i].size();
            if(reqRemain[i] == 0) {
                pursueCourses.push(i);
            }
        }

        while(!pursueCourses.empty()) {
            int course = pursueCourses.front();
            pursueCourses.pop();

            ans.push_back(course);

            for(int nextCourse: revDepGraph[course]) {
                reqRemain[nextCourse] -= 1;
                if(reqRemain[nextCourse] == 0) {
                    pursueCourses.push(nextCourse);
                }
            }
        }

        return ans;
    }
};