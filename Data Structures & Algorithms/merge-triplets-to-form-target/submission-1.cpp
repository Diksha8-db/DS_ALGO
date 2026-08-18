class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();

        vector<int> temp(3,INT_MIN);
        for(vector<int> v : triplets){
            if((target[0] < v[0]) || (target[1] < v[1]) || (target[2] < v[2])) continue;
            temp[0] = max(v[0],temp[0]);
            temp[1] = max(v[1],temp[1]);
            temp[2] = max(v[2],temp[2]);

            if(temp == target) return true;
        }
        return false;
    }
};
