class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        bool nullFound = false;

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node == nullptr) {
                nullFound = true;
            } else {
                if (nullFound)
                    return false;

                q.push(node->left);
                q.push(node->right);
            }
        }

        return true;
    }
};