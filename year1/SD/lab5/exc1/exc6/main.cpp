#include <iostream>
#include <algorithm>
using namespace std;

struct node{
    int data;
    int height;
    node* left;
    node* right;
};


node* root = NULL;

node* newNode(int data){
    node* aux = new node;
    aux->data = data;
    aux->height = 1;
    aux->left = NULL;
    aux->right = NULL;
    return aux;
}

int getHeight(node *n){
    if(n == NULL)
        return 0;
    return n->height;
}

node* insertNode(node* root, int data){
    node* newnode = newNode(data);
    node* p = root;
    node* p1 = NULL;

    while(p != NULL){
        p1 = p;
        if(data < p->data)
            p = p->left;
        else
            p = p->right;
    }

    if(p1 == NULL)
        p1 = newnode;
    else if(data < p1->data)
        p1->left = newnode;
    else
        p1->right = newnode;
    return p1;
}

void setAllHeights(node* root){
    if(root == NULL)
        return;
    else{
        setAllHeights(root->left);
        setAllHeights(root->right);
        root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    }
}

void input(){
    int x;
    cout<<"Add nodes (ctrl + Z = stop)"<<endl;
    cout<<"Node value: ";cin>>x;
    root = insertNode(root, x);

    cout<<"Node value: ";
    while (cin>>x){
            insertNode(root, x);
            cout<<"Node value: ";
    }
}

void readSRD(node* root){
    if(root == NULL)
        return;
    else {
        readSRD(root->left);
        cout<<root->data<<"-"<<root->height<<" ";
        readSRD(root->right);
    }
}

node* rightRotate(node* root){
    node *r = root->left;
    node *extra = r->right;
    root->left = extra;
    r->right = root;

    root->height = max(getHeight(root->left),getHeight(root->right)) + 1;
    r->height = max(getHeight(r->left),getHeight(r->right)) + 1;

    return r;
}

node* leftRotate(node* root){
    node *r = root->right;
    node *extra = r->left;
    root->right = extra;
    r->left = root;

    root->height = max(getHeight(root->left),getHeight(root->right)) + 1;
    r->height = max(getHeight(r->left),getHeight(r->right)) + 1;

    return r;
}

int getBalance(node* root){
    if(root == NULL)
        return 0;
    return getHeight(root->left) - getHeight(root->right);
}

void checkAVL(node* root){
    if(node == NULL)
        return;



}


int main()
{
    input();

    cin.clear();

    setAllHeights(root);



    readSRD(root);
    cout<<endl;

    return 0;
}
