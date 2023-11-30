/**
 * @file Prog106.cpp
 * @author Aghamarsh Varanasi
 * @brief 
 * This is a solution for the following problem in Leet code
 * 106. Construct Binary Tree from Inorder and Postorder Traversal
 * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
 * @version 0.1
 * @date 2023-11-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct TreeNode {
      int val;
      TreeNode* left;
      TreeNode* right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
}TreeNode;

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
    int findIndex(vector<int> v, int val, int l, int r) {
        for(int i = l; i <= r; i++) {
            if(v[i] == val) {
                return i;
            }
        }

        return -1;
    }

    TreeNode* getTree(vector<int> inorder, vector<int> postorder, int l, int r, int* pItr) {
        cout << l << " " << r << " " << *pItr << " " << endl;
        if (l > r) {
            return nullptr;
        } else if (l == r) {
            *pItr = *pItr + 1;
            return new TreeNode(inorder[l], nullptr, nullptr);
        }

        int inItr = this->findIndex(inorder, postorder[*pItr], l, r);
        cout << " find idx : " << inItr << endl;
        *pItr = *pItr + 1;
        TreeNode* right = this->getTree(inorder, postorder, inItr + 1, r, pItr);
        TreeNode* left = this->getTree(inorder, postorder, l, inItr - 1, pItr);
        TreeNode* head = new TreeNode(inorder[inItr], left, right);
        return head;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        reverse(postorder.begin(), postorder.end());
        
        int postItr = 0;
        int l = 0, r = inorder.size();
        TreeNode* result = this->getTree(inorder, postorder, l, r-1, &postItr);
        return result;
    }

    void print (TreeNode* h) {
        if(h == nullptr) {
            cout << "nullptr";
            return;
        }

        cout << h->val << " " ;
        print(h->left);
        cout << " ";
        print(h->right);
        cout << " ";
    }
};

int main () {
    Solution sl;
    vector<int> inorder = {1,2,3,4,5};
    vector<int> postorder = {2,1,5,4,3};

    TreeNode *t = sl.buildTree(inorder, postorder);
    sl.print(t);

}