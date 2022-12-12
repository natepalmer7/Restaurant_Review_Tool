#include <memory>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <iostream>
using namespace std; 
class Node {
public:
    string data;

    Node* next;
    
    Node* prev;
};

void printDLL(struct Node* head);
void bubbleSort(struct Node *start);
void deleteNode(Node** head_r, Node* del);
int search(Node** head, string x);
void insert(struct Node** head_ref, string new_data);