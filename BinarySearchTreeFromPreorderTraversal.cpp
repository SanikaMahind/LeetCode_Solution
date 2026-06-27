#include <iostream>
#include <vector>
#include <climits>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
private:
    TreeNode* buildBST(vector<int>& preorder, int& index, int bound) {
        if (index == preorder.size() || preorder[index] > bound)
            return nullptr;

        TreeNode* root = new TreeNode(preorder[index++]);

        root->left = buildBST(preorder, index, root->val);
        root->right = buildBST(preorder, index, bound);

        return root;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return buildBST(preorder, index, INT_MAX);
    }
};

void inorder(TreeNode* root) {
    if (!root) return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    Solution obj;

    vector<int> preorder = {8, 5, 1, 7, 10, 12};

    TreeNode* root = obj.bstFromPreorder(preorder);

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    return 0;
}