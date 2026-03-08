#include <iostream>

using namespace std;


struct Node{
    string s;
    Node *prev,*next;

    Node(string input):
        s(input),
        prev(nullptr),
        next(nullptr){}
};
string S_init;
int N;
int command[250000];
string S_value[250000];


void insertFronttoCurNode(Node* cur, Node* newNode)
{
    newNode->prev = cur->prev;
    newNode->next = cur;
    
    if(newNode->next != nullptr)
    {
        newNode->next->prev = newNode;
    }
    if(newNode->prev != nullptr)
    {
        newNode->prev->next = newNode;
    }
}
// cur newNode 
void insertBacktoCurNode(Node* cur, Node* newNode)
{
    newNode->prev = cur;
    newNode->next = cur->next;

    if(nullptr != newNode->next)
    {
        newNode->next->prev = newNode;
    }
    if(nullptr != newNode-> prev)
    {
        newNode->prev->next = newNode;
    }
}


int main() {
    cin >> S_init;
    cin >> N;

    Node *cur = new Node(S_init);


    for (int i = 0; i < N; i++) {
        cin >> command[i];
        if (command[i] == 1 || command[i] == 2) {
            cin >> S_value[i];
            Node* newNode = new Node(S_value[i]);
            //insertFronttoCurNode
            if(command[i] == 1)insertFronttoCurNode(cur, newNode);
            if(command[i] == 2)insertBacktoCurNode(cur, newNode);
        }
            if(command[i] == 3){
                if(cur->prev != nullptr) cur = cur->prev;
            }
            if(command[i] == 4){
                if(cur->next != nullptr)cur = cur->next;
            }
        string p_str = (cur->prev != nullptr) ? cur->prev->s : "(Null)";
        string n_str = (cur->next != nullptr) ? cur->next->s : "(Null)";
        
        cout << p_str << " " << cur->s << " " << n_str << endl;
    }
        
    

    // Please write your code here.

    return 0;
}
