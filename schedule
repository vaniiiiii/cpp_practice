class Solution {
public:
    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        std::unordered_map<int, std::vector<int>> mp;
        for (const auto& pre : prerequisites) {
            mp[pre[0]].push_back(pre[1]);
        }
        std::vector<int> bl(numCourses, 0);
        for (const auto& pre : prerequisites) {
            int a = pre[0];
            if (bl[a] == 0) {
                if (test(a, mp, bl)) {
                    return false;
                }
            }
        }
        return true;
    }

private:
    bool test(int ind, const std::unordered_map<int, std::vector<int>>& mp, std::vector<int>& bl) {
        if (bl[ind] == 1) {
            return true;
        }
        if (bl[ind] == 2) {
            return false;
        }
        bl[ind] = 1;

        auto it = mp.find(ind);
        if (it != mp.end()) {
            for (int i : it->second) {
                if (test(i, mp, bl)) {
                    return true;
                }
            }
        }

        bl[ind] = 2;
        return false;
    }
};
