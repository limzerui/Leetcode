class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //calc all the distance for all points first
        //then put it in a hashmap?
        //then sort according to the key or something
        //then return the top k results

        //initialise the priority queue
        priority_queue<pair<int, vector<int>>> maxHeap;

        for(auto point: points){
            int x = point[0];
            int y = point[1];
            int distSq = x*x + y*y;

            maxHeap.push({distSq, point});
            if(maxHeap.size()>k){
                maxHeap.pop();
            }
        }

        vector<vector<int>> result;
        while(!maxHeap.empty()){
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return result;
    }
};