#include <iostream>

using namespace std;

struct Node{
    char letter;
    int priority;
    Node* next;

};

Node *head = new Node();
Node *p = new Node();
Node *oldp = new Node();

void pushNode(Node** head, char x, int prio){
    Node* n = new Node();
    n->letter = x;
    n->priority = prio;
    n->next = (*head);
    *head = n;
}

void insertNode(Node* p, char x, int prio){
    if (p == NULL){
        return;
    }
    Node* n = new Node();
    n->letter = x;
    n->priority = prio;
    n->next = p->next;
    p->next = n;
}

void input(){
    char x;
    int prio;
    cout<<"Add letters (ctrl + Z = stop)"<<endl;
    cout<<"Letter: ";cin>>x;
    cout<<"Frequency: ";cin>>prio;
    head->letter = x;
    head->priority = prio;
    head->next = NULL;

    cout<<"Letter: ";
    while (cin>>x){
        cout<<"Frequency: ";cin>>prio;
        Node *p = head;

        if (prio < head->priority)
            pushNode(&head, x, prio);
        else
            while (p!=NULL){
                if(prio >= p->priority)
                    if(p->next == NULL || p->next->priority > prio)
                    {
                        insertNode(p, x, prio);
                        break;
                    }
                p = p->next;
            }

        cout<<"Letter: ";
    }
}

void print(Node *node){
    if(node == NULL)
        cout<<"empty queue";
    while(node != NULL){
        cout<<node->data<<"("<<node->priority<<")  ";
        node = node->next;
    }
    cout<<endl;
}


int main() {
    input();
    cout<<endl;
    print(head);
    cout<<endl;
    return 0;
}
