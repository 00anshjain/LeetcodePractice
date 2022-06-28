class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int i = 0;
        int fuel = 0;
        int deficit = 0;
        for(int j = 0; j < n; j++)
        {
            fuel += (gas[j] - cost[j]);
            while(fuel < 0)
            {
                deficit += fuel;
                fuel = 0;
                i = j+1;
            }
        }
        if(fuel + deficit >= 0)
            return i;
        return -1;
    }
};