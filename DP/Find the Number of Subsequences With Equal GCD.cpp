/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=9HLmfC-nyNU
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/find-the-number-of-subsequences-with-equal-gcd
*/

/*********************************************************** C++ **************************************************/
//Approach-1 (Recursion + Memoization)
//T.C : O(n * M * M), M = max element 
//S.C : O(n * M * M), M = max element
class Solution {
    int MOD = 1e9 + 7;
    int t[201][201][201];
public:
    int solve(vector<int> &nums,int i, int first, int second){
        if (i == nums.size()) {
            bool bothNonEmpty = (first != 0 && second != 0);
            bool gcdsMatch    = (first == second);
            return (bothNonEmpty && gcdsMatch) ? 1 : 0;
        }
        
        if(t[i][first][second] != -1) 
            return t[i][first][second];
        
        // Skip this index entirely
        int skip = solve(nums, i + 1, first, second);

        // Include this index in seq1
        int take1 = solve(nums, i + 1, __gcd(first, nums[i]), second);

        // Include this index in seq2
        int take2 = solve(nums, i + 1, first, __gcd(second, nums[i]));
        
        // Summing up all the possibilites
        return t[i][first][second] = (0LL + skip + take1 + take2) % MOD;
    }
    
    int subsequencePairCount(vector<int>& nums) {
        memset(t, -1, sizeof(t));
        return solve(nums, 0, 0, 0);
    }
};



//Approach-2 (Bottom Up)
//T.C : O(n * M * M), M = max element 
//S.C : O(n * M * M), M = max element
class Solution {
    int MOD = 1e9 + 7;
public:
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();

        int maxEl = -1;
        for (int x : nums) 
            maxEl = max(maxEl, x);
        
        int dp[n+1][maxEl+1][maxEl+1];

        // Base case
        for (int first = 0; first <= maxEl; first++) {
            for (int second = 0; second <= maxEl; second++) {
                bool bothNonEmpty = (first != 0 && second != 0);
                bool gcdsMatch    = (first == second);
                dp[n][first][second] = (bothNonEmpty && gcdsMatch) ? 1 : 0;
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int first = maxEl; first >= 0; first--) {
                for (int second = maxEl; second >= 0; second--) {

                    // Skip this index entirely
                    int skip  = dp[i + 1][first][second]; //solve(i+1, first, second);

                    // Include this index in seq1
                    int take1 = dp[i + 1][__gcd(first, nums[i])][second]; 

                    // Include this index in seq2
                    int take2 = dp[i + 1][first][__gcd(second, nums[i])];

                    dp[i][first][second] = (0LL + skip + take1 + take2) % MOD;
                }
            }
        }
 
        return dp[0][0][0]; //return solve(nums, 0, 0, 0);
    }
};



//Approach-3 (Bottom Up - 2D DP, space optimized)
//T.C : O(n * M * M), M = max element
//S.C : O(M * M), M = max element
class Solution {
    int MOD = 1e9 + 7;
public:
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();

        int maxEl = -1;
        for (int x : nums) 
            maxEl = max(maxEl, x);

        // prev = layer i+1, curr = layer i   (2D instead of 3D)
        vector<vector<int>> prev(maxEl+1, vector<int>(maxEl+1, 0));

        // Base case
        for (int first = maxEl; first >= 0; first--) {
            for (int second = maxEl; second >= 0; second--) {
                bool bothNonEmpty = (first != 0 && second != 0);
                bool gcdsMatch    = (first == second);
                prev[first][second] = (bothNonEmpty && gcdsMatch) ? 1 : 0;
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            vector<vector<int>> curr(maxEl+1, vector<int>(maxEl+1, 0));
            for (int first = maxEl; first >= 0; first--) {
                for (int second = maxEl; second >= 0; second--) {

                    // Skip this index entirely
                    int skip  = prev[first][second];

                    // Include this index in seq1
                    int take1 = prev[__gcd(first, nums[i])][second];

                    // Include this index in seq2
                    int take2 = prev[first][__gcd(second, nums[i])];

                    curr[first][second] = (0LL + skip + take1 + take2) % MOD;
                }
            }
            prev = move(curr);
        }

        return prev[0][0];
    }
};


/*********************************************************** JAVA **************************************************/
//Approach-1 (Recursion + Memoization)
//T.C : O(n * M * M), M = max element 
//S.C : O(n * M * M), M = max element
class Solution {
    int MOD = 1_000_000_007;
    int[][][] t;

    private int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    public int solve(int[] nums, int i, int first, int second) {
        if (i == nums.length) {
            boolean bothNonEmpty = (first != 0 && second != 0);
            boolean gcdsMatch    = (first == second);
            return (bothNonEmpty && gcdsMatch) ? 1 : 0;
        }

        if (t[i][first][second] != -1)
            return t[i][first][second];

        // Skip this index entirely
        int skip = solve(nums, i + 1, first, second);

        // Include this index in seq1
        int take1 = solve(nums, i + 1, gcd(first, nums[i]), second);

        // Include this index in seq2
        int take2 = solve(nums, i + 1, first, gcd(second, nums[i]));

        // Summing up all the possibilites
        return t[i][first][second] = (int)((0L + skip + take1 + take2) % MOD);
    }

    public int subsequencePairCount(int[] nums) {
        t = new int[201][201][201];
        for (int[][] row : t)
            for (int[] col : row)
                Arrays.fill(col, -1);
        return solve(nums, 0, 0, 0);
    }
}



//Approach-2 (Bottom Up)
//T.C : O(n * M * M), M = max element 
//S.C : O(n * M * M), M = max element
class Solution {
    int MOD = 1_000_000_007;

    private int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    public int subsequencePairCount(int[] nums) {
        int n = nums.length;

        int maxEl = -1;
        for (int x : nums)
            maxEl = Math.max(maxEl, x);

        int[][][] dp = new int[n + 1][maxEl + 1][maxEl + 1];

        // Base case
        for (int first = 0; first <= maxEl; first++) {
            for (int second = 0; second <= maxEl; second++) {
                boolean bothNonEmpty = (first != 0 && second != 0);
                boolean gcdsMatch    = (first == second);
                dp[n][first][second] = (bothNonEmpty && gcdsMatch) ? 1 : 0;
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int first = maxEl; first >= 0; first--) {
                for (int second = maxEl; second >= 0; second--) {

                    // Skip this index entirely
                    int skip  = dp[i + 1][first][second]; //solve(i+1, first, second);

                    // Include this index in seq1
                    int take1 = dp[i + 1][gcd(first, nums[i])][second];

                    // Include this index in seq2
                    int take2 = dp[i + 1][first][gcd(second, nums[i])];

                    dp[i][first][second] = (int)((0L + skip + take1 + take2) % MOD);
                }
            }
        }

        return dp[0][0][0]; //return solve(nums, 0, 0, 0);
    }
}



//Approach-3 (Bottom Up - 2D DP, space optimized)
//T.C : O(n * M * M), M = max element
//S.C : O(M * M), M = max element
class Solution {
    int MOD = 1_000_000_007;

    private int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    public int subsequencePairCount(int[] nums) {
        int n = nums.length;

        int maxEl = -1;
        for (int x : nums)
            maxEl = Math.max(maxEl, x);

        // prev = layer i+1, curr = layer i   (2D instead of 3D)
        int[][] prev = new int[maxEl + 1][maxEl + 1];

        // Base case
        for (int first = maxEl; first >= 0; first--) {
            for (int second = maxEl; second >= 0; second--) {
                boolean bothNonEmpty = (first != 0 && second != 0);
                boolean gcdsMatch    = (first == second);
                prev[first][second] = (bothNonEmpty && gcdsMatch) ? 1 : 0;
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            int[][] curr = new int[maxEl + 1][maxEl + 1];
            for (int first = maxEl; first >= 0; first--) {
                for (int second = maxEl; second >= 0; second--) {

                    // Skip this index entirely
                    int skip  = prev[first][second];

                    // Include this index in seq1
                    int take1 = prev[gcd(first, nums[i])][second];

                    // Include this index in seq2
                    int take2 = prev[first][gcd(second, nums[i])];

                    curr[first][second] = (int)((0L + skip + take1 + take2) % MOD);
                }
            }
            prev = curr;
        }

        return prev[0][0];
    }
}
