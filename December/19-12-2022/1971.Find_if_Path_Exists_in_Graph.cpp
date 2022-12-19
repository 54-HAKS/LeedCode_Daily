class Solution {
public:
    bool validPath(int n, vector<vector<int>>&nums, int start, int end) 
    {
        vector<int>dp[n+1];
        for(auto it:nums)
        {
            dp[it[0]].push_back(it[1]);
            dp[it[1]].push_back(it[0]);
        }
        vector<bool>vis(n+1,false);
        queue<int>q;
        q.push(start);
        vis[start]=true;
        while(q.size())
        {
            auto temp=q.front();
            q.pop();
            if(temp==end)
            {
                return true;
            }
            for(auto it:dp[temp])
            {
                if(vis[it]==false)
                {
                    q.push(it);
                    vis[it]=true;
                }
            }
        }
        return false;
    }
};