#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (root == NULL || root->left == NULL)
            return root;

        TreeNode* newRoot = upsideDownBinaryTree(root->left);

        root->left->left = root->right;
        root->left->right = root;

        root->left = NULL;
        root->right = NULL;

        return newRoot;
    }
};


void inorder(TreeNode* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
   

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution obj();

    Solution sol;
    TreeNode* newRoot = sol.upsideDownBinaryTree(root);

    cout << "Inorder Traversal of New Tree: ";
    inorder(newRoot);

    return 0;
}