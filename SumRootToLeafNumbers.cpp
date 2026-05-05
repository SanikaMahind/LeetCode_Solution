#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }

    int dfs(TreeNode* node, int current) {
        if (node == NULL) return 0;

        current = current * 10 + node->val;

        
        if (node->left == NULL && node->right == NULL) {
            return current;
        }

        return dfs(node->left, current) + dfs(node->right, current);
    }
};

int main() {
 

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    Solution obj;
    cout << obj.sumNumbers(root);

    return 0;
}