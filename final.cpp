#include "final.h"
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <queue>
#include <bits/stdc++.h>

using namespace std;
// Below is my insert function to put new node at the head
void insert(struct Node** head_ref, string new_data)
{
    // allocate node
    struct Node* new_node =
         (struct Node*)malloc(sizeof(struct Node));
 
    // put data in  
    new_node->data = new_data;
 
    // put next of new node as head and previous as NULL 
    new_node->next = (*head_ref);
    new_node->prev = NULL;
 
    // This changes prev head node to new_node 
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
 
    //This moves the head to point to the new_node 
    (*head_ref) = new_node;
}

// function used for searching int in a Doubly Linked List

int search(Node** head, string x){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    // put next of new node as head and previous as NULL 
    new_node->next = (*head);
    new_node->prev = NULL;
    //set int to 0
    int i = 0;
    bool exit = false;
    // while loop to find index with search function and to exit once index is found
    while(!exit){
    if(new_node->data==x){
        cout<<"Found "<< x<< " at index "<< i;
        exit=true;
        return i;
    }
    else{
        i++;
        new_node=new_node->next;
    }}
    return 0;
}

// Function to delete a node in a doubly linked list
void deleteNode(struct Node** head_ref, struct Node* del)
{
    // base case for return
    if (*head_ref == NULL || del == NULL)
        return;
 
    //If node is going to be deleted, that is head node 
    if (*head_ref == del)
        *head_ref = del->next;
 
    // this changes the next only if node is the one to be deleted is NOT the last node 
       
    if (del->next != NULL)
        del->next->prev = del->prev;
 
    // This does the same but for prev so change prev only if node is the one to deleted is NOT the first node 
       
    if (del->prev != NULL)
        del->prev->next = del->next;
 
    // this then lets free the memory inhabited by del
    free(del);
}
 
// This is my function to delete the node at the given position in DLL
  
void deleteNodeAtGivenPos(struct Node** head_ref, int n)
{
    //this states that if the list in NULL or invalid position is placed
    if (*head_ref == NULL || n <= 0)
        return;
 
    struct Node* current = *head_ref;
    int i;
 
    // traverse up to the node at position 'n' from the beginning 
       
    for (int i = 1; current != NULL && i < n; i++)
        current = current->next;
 
    //this states that if 'n' is greater than the number of nodes in the doubly linked list 
       
    if (current == NULL)
        return;
 
    // delete the node pointed to by variable current
    deleteNode(head_ref, current);
}
//this is my printing function to print full list
void printDLL(struct Node* head)
{
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    
}
//this is my main that primarily holds the menu
int main(){
    Node* head = NULL;
    int input;
    struct restaurant;
    bool exit = false;
    //this is my main menu options
    do{
        cout<< endl << endl <<"Welcome to the Restauraunt Reviewer!" << endl;
        cout<< "Please Enter a Number (or):" << endl;
        cout<< "1) Enter a Review"<< endl;
        cout<< "2) Delete a Review at an Index"<< endl;
        cout<< "3) Search a Review Index"<<endl;
        cout<< "4) View Entire List"<< endl;
        cout<< "5) Press 'E' to exit the program"<< endl;
        cin >> input;
        // this is my switch cases for navigating my menu and functions
        switch(input){ 
            case 1:
            {
                //insert function for menu
                string str;
                cout<< "1) Enter Name and Rating of Restaurant in format (<Rating>_<Name>)"<< endl;
                cin >> str;
                insert(&head, str);
                cout << "Added " << str << endl;
                break;
            }
            case 2:
            {
                //case for my delete node function
                int index;
                cout << "What is the index that you would like to delete? (Enter an Integer)" << endl;
                cin >> index;
                deleteNodeAtGivenPos(&head,index);
                cout << "Deleted index " << index;
                break;          
            }
            case 3: {
                //case for my search by index function
                string str;
                cout << "What restaurant index would you like to search for? Format (<Rating>_<Name>)" << endl;
                cin >> str;
                cout << "Searching..." << endl;
                search(&head,str);
                break;
            }
               
            case 4:
                // case for function that shows print full list 
                cout << "Here is the Reviewed Restaurants: ";
                printDLL(head);
                break;

            default:
                cout << "Thank you for using Restaurant Reviewer, quitting..." << endl;
                continue;
        }
    } while(input&&!exit);
    return 0;
}

