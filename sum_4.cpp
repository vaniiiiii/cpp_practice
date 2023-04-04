class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int tg) {
        int n = nums.size();
        vector<vector<int>>ans;
        set<vector< int>>st;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3 ; i++) {
            if (i > 0 && (nums[i - 1] == nums[i])) continue;
            for (int j = i + 1; j < n - 2; j++) {
                if (j >  i + 1 && nums[j - 1] == nums[j]) continue;
                int l = j + 1; 
                int r = n - 1;
                long long int tg_nw = nums[i] + nums[j];
                while (l < r) {
                    long long int rem = tg - tg_nw;
                    long long int now = nums[l] + nums[r];
                    if (rem == now) {
                        st.insert({
                            nums[i],
                            nums[j],
                            nums[l],
                            nums[r]
                        });
                        ++l;
                    }
                    if (now < rem) l++;
                    if (now > rem) r--;
                }
            }
        }
        for (auto it : st) ans.push_back(it);
        return ans;
    }
};4