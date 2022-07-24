class NumberContainers {
public:
    unordered_map<int, set<int>> mp;
    unordered_map<int, int> pos;
    NumberContainers() {
        
    }
    
    void change(int idx, int number) {
        if(pos.find(idx) != pos.end())
        {
            int k = pos[idx];
            mp[k].erase(idx);
        }
        pos[idx] = number;
        mp[number].insert(idx);
    }
    
    int find(int number) {
        if(mp[number].empty())
            return -1;
        return *(mp[number].begin());
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */