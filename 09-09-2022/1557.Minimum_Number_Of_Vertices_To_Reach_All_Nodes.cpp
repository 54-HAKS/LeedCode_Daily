class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        bool to[100000] = {};
        for (auto& e: edges) to[e[1]] = 1;
        for (int i = 0; i < n; i++)
            if (!to[i]) ans.push_back(i);
        return ans;
    }
};