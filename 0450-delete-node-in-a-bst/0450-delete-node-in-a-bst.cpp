/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
bool search(TreeNode *root, int target){
    if(!root){
        return false;
    }
    if(root->val==target){
        return true;
    }
    if(target<root->val){
        return search(root->left,target);
    }
    return search(root->right,target);
}
  TreeNode* minVal(TreeNode* node) {
        while (node && node->left) {
            node = node->left;
        }
        return node;
    }
 
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
        return nullptr;

        if(!search(root,key)){
           root->left = deleteNode(root->left, key);
        }

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else {
            if (!root->left)
                return root->right;
            else if (!root->right)
                return root->left;
            else {
                TreeNode* temp = minVal(root->right);
                root->val = temp->val;
                root->right = deleteNode(root->right, temp->val);
            }
        }
        return root;
    }
};