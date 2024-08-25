class Solution {
public:
    int longestPalindromeSubseq(string s) {
        
        string a = s;
        std::reverse(s.begin(), s.end());
        string b = s;
        int n = s.size();
        vector<int>curr(n+1,0);
        vector<int>next(n+1,0);
        for(int i = n-1 ; i >=0 ; i--)
        {
            for(int j = n-1 ; j>= 0 ;j--)
            {
                if(a[i]==b[j])
                    curr[j] = 1 + next[j+1];
                else
                    curr[j] = max(next[j],curr[j+1]);
            }
            next=curr;
        }
        return next[0];
    }
};