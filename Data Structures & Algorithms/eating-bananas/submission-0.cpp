class Solution {
public:
    long EatingHrs(vector<int>& piles, long k) {
        long hours = 0;
        for (long i = 0; i < piles.size(); i++) {
            hours += ceil((double)piles[i] / k);
        }
        return hours;
    }
    long minEatingSpeed(vector<int>& piles, int h) {
        long low = 1;
        long high = *max_element(piles.begin(), piles.end());
        long mid;
        long out;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (EatingHrs(piles, mid) <= h) {
                out = mid; // always save when feasible
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return out;
    }
};