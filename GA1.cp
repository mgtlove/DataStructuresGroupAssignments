#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;
//Take input from the user
//Remove every other letter
//Print how long it took
//Print the removal list backwards

struct node {
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
                head->isHead = false;
        }
        // Assign temp to be the new head
        head = temp;
        head -> isHead = true;
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
        return head==NULL;
}
void setChars(string s){
        for (int i=0; i<s.length(); i++) {
                addToTail(s[i]);
        }
}
void removeEveryOtherChar(){

}
void print(){
        node *current = head;
        while (current!=NULL) {
                cout<<current->myLetter;
                current= current->next;
        }
        cout<<endl;
}
void makeCircular(){
        node *current=head;
        while (current->next!=NULL){
          current= current->next;
        }
        current->next=head;
}
};


int main(int argc, char *argv[]) {
        string userInput;
        List ourList;

        // Get our string from the user
        cout<<"Input: ";
        getline(cin,userInput);
        ourList.setChars(userInput);
        ourList.print();
        ourList.makeCircular();
        ourList.print();




        return 0;
}
