#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;

        if (root == NULL)
            return result;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            int maxVal = INT_MIN;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                maxVal = max(maxVal, node->val);

                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);
            }

            result.push_back(maxVal);
        }

        return result;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);

    Solution obj;
    vector<int> ans = obj.largestValues(root);

    cout << "Largest values in each row: ";
    for (int x : ans)
        cout << x << " ";

    return 0;
}