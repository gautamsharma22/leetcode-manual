#include<queue>
#include<iostream>
#include<stdio.h>
#include<map>
#include<sstream>
using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node *buildTree(string str) {
    if (str.length() == 0 || str[0] == 'N')
        return NULL;
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
        Node* mapparent(Node* root,map<Node*,Node*> &parent,int target){
          parent[root]=NULL ;
          Node* result=NULL;
          queue<Node*> q;
          q.push(root);
          while(!q.empty()){
              Node* temp=q.front();
              q.pop();
              if(temp->data==target){
                  result=temp;
              }
              if(temp->left){
                  parent[temp->left]=temp;
                  q.push(temp->left);
              }
              if(temp->right){
                  parent[temp->right]=temp;
                  q.push(temp->right);
              }
          }
          return result;
      }
      int burn(Node* root,map<Node*,Node*> &parent){
          int count=0;
          map<Node*,bool> visited;
          queue<Node*> q;
          q.push(root);
          visited[root]=true;
          while(!q.empty()){
              bool check=false;
              int size=q.size();
              for(int i=0;i<size;i++){
                    Node* temp=q.front();
                    q.pop();
                    if(temp->left && !visited[temp->left]){
                        check=true;
                        visited[temp->left]=true;
                        q.push(temp->left);
                      }
                    if(temp->right && !visited[temp->right]){
                        check=true;
                        visited[temp->right]=true;
                        q.push(temp->right);
                      }
                      if(parent[temp] && !visited[parent[temp]]){
                          check=true;
                        q.push(parent[temp]);
                        visited[parent[temp]]=true;
                      } 
        }
            if(check)count++;
          }
          return count;
      }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        if(root==NULL){
              return 0;
          }
        map<Node*,Node*> parent;
        Node* targetval=mapparent(root,parent,target);
        return burn(targetval,parent);
        
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends