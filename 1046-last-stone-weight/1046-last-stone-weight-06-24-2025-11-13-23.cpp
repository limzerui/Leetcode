class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        //sort the stones first and add them to a priority quue
        //pop two, then minus off, do the checks
        //then add the result back
        //do until there is only one
        priority_queue<int> pq(stones.begin(), stones.end());

        while(pq.size()>1){
            int y = pq.top();pq.pop();
            int x = pq.top();pq.pop();

            if(x!=y){
                pq.push(y-x);
            }
        }
            return pq.empty()?0: pq.top();
    };
};