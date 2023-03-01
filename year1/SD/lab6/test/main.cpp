#include <iostream>
#include <vector>

using namespace std;

struct Node{
        int ctype;
        Node* next;
    };

    Node* head;
    Node* p = new Node();


    void pushNode(int x){
        Node* n = new Node();
        n->ctype = x;
        n->next = head;
        head = n;
    }

    int distributeCandies(vector<int>& candyType) {
        int pickedCandies = 1;
        pushNode(candyType[0]);
        cout<<"push "<<candyType[0]<<endl;
        for(int it = 1; it < candyType.size(); it++){
            if(pickedCandies == candyType.size()/2)
                break;
            cout<<"cont\n";
            int ok = 1;
            p = head;

            while(p!=NULL){
                cout<<candyType[it]<<' '<<p->ctype<<'\n';
                if(candyType[it] == p->ctype){
                    ok = 0;
                    cout<<"ok = 0\n";
                    break;
                }
                if(p->next != NULL)
                    p = p->next;
                else break;
            }

            if(ok == 1){
                cout<<"push\n";
                pushNode(candyType[it]);
                ++pickedCandies;
            }
        }
        return pickedCandies;
    }

int main()
{
    vector<int> vect{ 4, 0, 0, 4};
    cout<<distributeCandies(vect);
    return 0;
}
