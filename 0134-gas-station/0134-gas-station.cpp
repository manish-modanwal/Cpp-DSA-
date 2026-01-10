class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int deficit = 0;
        int remaining = 0;
        int idx = 0;
        int n = gas.size();

        for(int i = 0; i < n; i++) {
            remaining += gas[i] - cost[i];

            if(remaining < 0) {
                deficit += remaining;
                remaining = 0;
                idx = i + 1;
            }
        }

        if(remaining + deficit >= 0)
            return idx;

        return -1;
    }
};
