class Solution{
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1; 
        int mid;
        int r = *max_element(piles.begin(),piles.end());
        while(l <= r){
            mid = (l + r) / 2;
            if(Possible(piles, h, mid))
                r = mid - 1;
            else
                l = mid + 1;
        }
        return l;   
    }
    bool Possible(vector<int>&piles, int h, int mid){
        long long sum = 0;
        for(int i = 0; i < piles.size(); i++){
            sum += (piles[i] + mid - 1) / mid; 
        }
        if(sum <= h) return true;
        else return false;
    }
};
