class Solution {
private:
    int f(int n,int m){
        if(n%m !=0 ) return (n/m)+1;
        else return (n/m);
    }
private:
    bool isPossible(int mid,vector<int>& dist, double hour){
        double cnt_hr=0;
        
        for(int i=0;i<dist.size()-1;i++){
            cnt_hr+=f(dist[i],mid);
        }
        
        cnt_hr+=(double)dist.back()/(double)mid;
        
        return cnt_hr<=hour;
    }
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        if((1.0*dist.size()-1) >= hour) return -1; 
        
        int lo=1;
        int hi=1e7;
        
        int ans=hi;
        
        while(lo<=hi){
            
            int mid=lo+(hi-lo)/2;
 
            if(isPossible(mid,dist,hour)){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        
        return ans;
    }
};