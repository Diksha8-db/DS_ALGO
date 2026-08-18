class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, totalCost = 0;
        for(int i = 0; i < gas.size(); i++){
            totalGas += gas[i];
            totalCost += cost[i];
        }

        if(totalGas < totalCost) return -1; // impossible

        int start = 0;
        int fuel = 0;

        for(int i = 0; i < gas.size(); i++){
            fuel += gas[i] - cost[i]; // net gain/loss at station i

            // if we can't reach next station, reset start
            if(fuel < 0){
                start = i + 1; // next station is new candidate
                fuel = 0; // reset fuel
            }
        }
        return start;
    }
};