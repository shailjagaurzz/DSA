#include<iostream>
#include<vector>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

class Solution {
    public:  
    void traverseLeft(vector<int> &ans,node* root){
        if(root==NULL){
            return;
        }
       if(root->left==NULL&& root->right==NULL){
           return;
       }
       ans.push_back(root->data);
       if(root->left){
       traverseLeft(ans,root->left);
       }
       else{
           traverseLeft(ans,root->right);
       }
    }
    void traverseLeaf(vector<int> &ans,node* root){
        if(root==NULL){
            return;
        }
        else if(root->left==NULL && root->right==NULL){
            ans.push_back(root->data);
            return ;
        }
        traverseLeaf(ans,root->left);
        traverseLeaf(ans,root->right);
        
        //traverse leafnodes
        //leftSubtree
        //right Subtree
      
    }
    void traverseRight(node* root,vector<int> &ans){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            return;
        }
        if(root->right){
            traverseRight(root->right,ans);
        }
        else{
        traverseRight(root->left,ans);
    }
    //wps aa rhe ho
    ans.push_back(root->data);
    }
    
      vector<int> boundaryTraversal(node *root) {
          // codehere
          vector<int> ans;
        if(root==NULL){
            return ans;
        }
        ans.push_back(root->data);
        
        traverseLeft(ans,root->left);
        //left subtree
        traverseLeaf(ans,root->left);
        //right subtree
        traverseLeaf(ans,root->right);
        
        traverseRight(root->right,ans);
        return ans;
      }
  };