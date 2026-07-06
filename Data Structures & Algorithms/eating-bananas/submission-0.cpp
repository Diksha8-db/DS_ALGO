class Solution {
public:
    int n;
    bool isPossible(int rate,vector<int>& piles,int h){
        int timeTaken = 0;
        
        for(int i = 0; i < n; i++){
            timeTaken += (piles[i] + rate - 1)/rate;
        }
        return (timeTaken <= h);
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        // binary search on answer
        n = piles.size();

        int maxBanana = INT_MIN;
        for(int banana : piles){
            maxBanana = max(maxBanana,banana);
        }

        int low = 1, high = maxBanana;
        int ans = 0;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(isPossible(mid,piles,h)){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }

        return ans;
    }
};
