class Solution {
public:

    bool canFinish(vector<int>& piles, int k, int h){
        long long hours = 0;
        for(int pile: piles){
            hours += ceil((double)pile/k);
        }
        return hours<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        //how many items inside the array?
        //if number of items is more than number of hours, then find the 
        //if there are 4 items and the hours is 3, then need to find the second largest item?

        //find the maximum eating pace
        int right = 0;
        for(int pile : piles) {
            if(pile>right) {
                right = pile;
            }
        }
        int left = 1;

        int result = right;

        while(left<=right){
            int mid = left + (right-left) /2;

            if(canFinish(piles,mid,h)){
                result = mid;
                right = mid-1;
            }
            else{
                left = mid + 1;
            }
        }
        return result;

        //so we have the min and max as 1 and maxPile

    }
};