/*         Scroll below to see JAVA code as well        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Tbx_AJaDTUg
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/remove-covered-intervals/
*/


/************************************************************************ C++ ************************************************************/
//Approach-1 (Using O(n) space and sorting)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        vector<vector<int>> result;

        int n = intervals.size();

        auto lambda = [](vector<int>& vec1, vector<int>& vec2) {
            if(vec1[0] == vec2[0]) {
                return vec1[1] > vec2[1];
            }

            return vec1[0] < vec2[0];
        };

        sort(begin(intervals), end(intervals), lambda);

        result.push_back(intervals[0]);

        for(int i = 1; i < n; i++) {
            if(result.back()[0] <= intervals[i][0] && result.back()[1] >= intervals[i][1]) {
                continue;
            }

            result.push_back(intervals[i]);
        }

        return result.size();
    }
};


//Approach-2 (Using O(n) space and sorting + Simplified condition check)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        vector<vector<int>> result;

        int n = intervals.size();

        auto lambda = [](vector<int>& vec1, vector<int>& vec2) {
            if(vec1[0] == vec2[0]) {
                return vec1[1] > vec2[1];
            }

            return vec1[0] < vec2[0];
        };

        sort(begin(intervals), end(intervals), lambda);

        result.push_back(intervals[0]);

        for(int i = 1; i < n; i++) {
            if(result.back()[1] >= intervals[i][1]) { //simplified
                continue;
            }

            result.push_back(intervals[i]);
        }

        return result.size();
    }
};

//Approach-3 (Using constant space and sorting)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {

        int n = intervals.size();

        auto lambda = [](vector<int>& vec1, vector<int>& vec2) {
            if(vec1[0] == vec2[0]) {
                return vec1[1] > vec2[1];
            }

            return vec1[0] < vec2[0];
        };

        sort(begin(intervals), end(intervals), lambda);

        //result.push_back(intervals[0]);
        int lastIntervalKaEnd = intervals[0][1];
        int count = 1;

        for(int i = 1; i < n; i++) {
            if(lastIntervalKaEnd >= intervals[i][1]) {
                continue;
            }

            lastIntervalKaEnd = intervals[i][1];
            count++;
        }

        return count;
    }
};


/************************************************************************ JAVA ************************************************************/
//Approach-1 (Using O(n) space and sorting)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
    public int removeCoveredIntervals(int[][] intervals) {
        int n = intervals.length;

        Arrays.sort(intervals, (vec1, vec2) -> {
            if (vec1[0] == vec2[0]) {
                return vec2[1] - vec1[1]; // end descending on ties
            }
            return vec1[0] - vec2[0];     // start ascending
        });

        List<int[]> result = new ArrayList<>();
        result.add(intervals[0]);

        for (int i = 1; i < n; i++) {
            int[] back = result.get(result.size() - 1);
            if (back[0] <= intervals[i][0] && back[1] >= intervals[i][1]) {
                continue;
            }
            result.add(intervals[i]);
        }

        return result.size();
    }
}

//Approach-2 (Using O(n) space and sorting + Simplified condition check)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
    public int removeCoveredIntervals(int[][] intervals) {
        int n = intervals.length;

        Arrays.sort(intervals, (vec1, vec2) -> {
            if (vec1[0] == vec2[0]) {
                return vec2[1] - vec1[1];
            }
            return vec1[0] - vec2[0];
        });

        List<int[]> result = new ArrayList<>();
        result.add(intervals[0]);

        for (int i = 1; i < n; i++) {
            int[] back = result.get(result.size() - 1);
            if (back[1] >= intervals[i][1]) { // simplified
                continue;
            }
            result.add(intervals[i]);
        }

        return result.size();
    }
}

//Approach-3 (Using constant space and sorting)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
    public int removeCoveredIntervals(int[][] intervals) {
        int n = intervals.length;

        Arrays.sort(intervals, (vec1, vec2) -> {
            if (vec1[0] == vec2[0]) {
                return vec2[1] - vec1[1];
            }
            return vec1[0] - vec2[0];
        });

        int lastIntervalKaEnd = intervals[0][1];
        int count = 1;

        for (int i = 1; i < n; i++) {
            if (lastIntervalKaEnd >= intervals[i][1]) {
                continue;
            }
            lastIntervalKaEnd = intervals[i][1];
            count++;
        }

        return count;
    }
}
