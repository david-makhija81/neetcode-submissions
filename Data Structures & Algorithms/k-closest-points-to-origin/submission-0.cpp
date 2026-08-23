long long euclideanDistance(int x, int y) {
    return ((x * x) + (y * y));
}

struct comp {
    bool operator()(vector<int>& point1, vector<int>& point2) {
        return 
        euclideanDistance(point1[0], point1[1]) < 
        euclideanDistance(point2[0], point2[1])
        ;
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // We have to find k closest points to the origin, right?
        // We can start with a list k closest points and whenever we come across a new point we can determine if this should included in the k closest points or not based on the comparison between the distance of this point from the origin and the distance of the farthest point from origin out of the k closest points.
        // If it is farther than the farthest point among the k closest points then it must not be included in the k closest points, else if it is closer than that farthest point then it must be included in the k closest points.

        priority_queue<vector<int>, vector<vector<int>>, comp> kClosestPoints;

        for(vector<int> point: points) {
            if(kClosestPoints.size() < k) {
                kClosestPoints.push(point);
                continue;
            }

            kClosestPoints.push(point);

            kClosestPoints.pop();
        }

        vector<vector<int>> ans;

        while(!kClosestPoints.empty()) {
            ans.push_back(kClosestPoints.top());
            kClosestPoints.pop();
        }

        return ans;
    }
};