#include <iostream>
#include <queue>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
Node* buildTree(Node* root){
    cout<<"Enter the data for root node\n";
    int data;
    cin>>data;
    //create node now
    root=new Node(data);
    //base case
    if(data==-1){
        return NULL;
    }
    //for left node 
    cout<<"Enter value for left node"<<data<<endl;
    root->left=buildTree(root->left);
    //for right node 
    cout<<"Enter value for right node"<<data<<endl;
    root->right=buildTree(root->right);
    return root;
}
void levelOrderTraversal(Node* root){
    //first make a queue for LvlOrderTraversal
    queue<Node*> q;
    q.push(root);
    q.push(NULL); //for root case (separator)
    while (!q.empty()){
        Node* temp=q.front(); //for root node (all parents)
        q.pop();
        //check for separator
        if(temp==NULL){
            cout<<"\n";
            if(!q.empty()){ //if true that means it have more to come so put NULL(separator) there too
                q.push(NULL);
            }
        }else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
    

}
int main()
{
    Node* root=NULL;
    root=buildTree(root);
    levelOrderTraversal(root);
    return 0;
}