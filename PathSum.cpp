#include <iostream>
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL)
            return false;

        if (root->left == NULL && root->right == NULL)
            return (targetSum == root->val);

        return hasPathSum(root->left, targetSum - root->val) ||
               hasPathSum(root->right, targetSum - root->val);
    }
};

int main() {

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);

    Solution obj;
    
    int targetSum = 22;
    
    if (obj.hasPathSum(root, targetSum))
        cout << "True";
    else
        cout << "False";

    return 0;
}