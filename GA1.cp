#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;
//Take input from the user
//Remove every other letter
//Print how long it took
//Print the removal list backwards

struct node{
    char myLetter;
    bool isHead;
    node *next;
    node *previous;
};

class List {
    node* head = NULL;
public:
    List(){
        
    }
    void addToHead(char c) {
        node *temp = new node();
        temp->previous = NULL;
        temp->next = head;
        temp->myLetter = c;
        if(head!=NULL) {
            head->previous = temp;
        }
    }
    void addToTail(char c) {
        if (isEmpty()) {
            addToHead(c);
        } else {
            node* current = head;
            while(current->next!=NULL) {
                current = current->next;
            }
            node* temp = new node();
            temp->previous = current;
            temp->next = NULL;
            temp->myLetter = c;
            current->next = temp;
        }
    }
    bool isEmpty() {
        if(head==NULL) {
            return true;
        } else {
            return false;
        }
    }
    void set(string s){
        for (int i=0; i<s.length(); i++) {
            addToTail(s[i]);
        }
    }
    void print(){
        node *current = head;
        while (current!=NULL) {
            cout<<current->myLetter;
            current= current->next;
        }
    }
};


int main(int argc, char *argv[]) {
    string userInput;
    getline(cin,userInput);
    List ourList;
    
    
        return 0;
}

