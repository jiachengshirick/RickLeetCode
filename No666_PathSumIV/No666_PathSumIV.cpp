class Solution {
public:
    int pathSum(vector<int>& nums) {
        vector<int> trees = getValue(nums);
        int sum = 0;
        sum = dfs (sum, 0, trees);

        return sum;
    }

    int dfs(int sum, int index, vector<int> trees){
        if (index * 2 >= 14 || (trees[(index * 2 + 1)] == -1 && trees[(index * 2 + 2)] == -1)) {
            sum += trees[index];
            return sum;
        }
        int sumLeft = 0;
        int sumRight = 0;
        if (trees[(index * 2 + 1)] != -1){
            sumLeft = dfs(sum + trees[index], index * 2 + 1, trees);
        }
        if (trees[(index * 2 + 2)] != -1){
            sumRight = dfs(sum + trees[index], index * 2 + 2, trees);
        }
        return sumLeft + sumRight;
    }

    vector<int> getValue(vector<int>& nums){
        vector<int> trees(16, -1);
        for (int i : nums){
            int v = i % 10;
            i /= 10;
            int p = i % 10;
            int d = i / 10;
            int index = pow(2, d - 1) + p - 2 ;
            trees[index] = v;
        }
        return trees;
    }


};