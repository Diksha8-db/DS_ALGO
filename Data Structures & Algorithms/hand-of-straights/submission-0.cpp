class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // 1. Store the frequency of each character in a hash map
        unordered_map<int,int> freqMap;
        for(int num : hand){
            freqMap[num]++;
        }

        // 2. Sort the array as the min value will act as the starting element of the grp
        sort(hand.begin(),hand.end());

        // 3. Check if we can form a group with the starting element or not
        for(int i = 0; i < hand.size(); i++){
            if(freqMap[hand[i]] == 0) continue;
            else{
                int cnt = 0;
                int val = hand[i];
                while(cnt != groupSize){
                    if(freqMap.count(val)){
                        cnt++;
                        freqMap[val]--;
                        val++;
                    }
                    else return false;
                }
            } 
        }
        return true;
    }
};
