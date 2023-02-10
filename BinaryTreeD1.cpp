#include<iostream>
#include<queue>
using namespace std;
class node{
public:
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node* createTree(node* root){
    cout << "Enter Data : ";
    int data;

    int rightdata;
    cin >> data;
    root = new node(data);
    if(data==-1){
        return NULL; 
    }
    cout << "Enter Values for left :";
    root->left = createTree(root->left);
    cout << "Enter Values for right :";
    root->right = createTree(root->right);
    return root;
}
int main(){
    cout<<"hello world";
    return 0;
}