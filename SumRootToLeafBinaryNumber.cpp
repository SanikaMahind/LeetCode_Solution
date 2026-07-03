#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = right = nullptr;
    }
};

class Solution {
public:
    int dfs(TreeNode* root, int current) {
        if (root == nullptr)
            return 0;

        current = (current << 1) | root->val;

        if (root->left == nullptr && root->right == nullptr)
            return current;

        return dfs(root->left, current) + dfs(root->right, current);
    }

    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }
};

int main() {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(1);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(1);

    Solution obj;
    cout << obj.sumRootToLeaf(root) << endl;

    return 0;
}