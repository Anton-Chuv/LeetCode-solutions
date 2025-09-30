class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& L, vector<vector<int>>& F) {
        int M = L.size();
        vector<unordered_set<int>> G(M); // people to language
        for (int i = 0; i < M; ++i) {
            for (int n : L[i]) G[i].insert(n - 1);
        }
        unordered_set<int> s;
        for (auto &f : F) {
            int a = f[0] - 1, b = f[1] - 1, i;
            for (i = 0; i < n; ++i) {
                if (G[a].count(i) && G[b].count(i)) break;
            }
            if (i == n) s.insert(a), s.insert(b);
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; ++i) { // try each language
            int cnt = 0;
            for (int p : s) {
                cnt += G[p].count(i) == 0;
            }
            ans = min(ans, cnt);
        }
        return ans;
    }
};
