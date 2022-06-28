class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int j = 0, i = 0;
        int k = n + n-1;
        int fuel = 0;
        while(j < k && i < n)
        {
            fuel += (gas[j%n] - cost[j%n]);
            while(fuel < 0 && i < n)
            {
                fuel -= (gas[i] - cost[i]);
                i++;
            }
            if(j-i == n-1)
                return i;
            j++;
        }
        return -1;
    }
};