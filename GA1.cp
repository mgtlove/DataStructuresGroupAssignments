#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
//Take input from the user
//Remove every other letter
//Print how long it took
//Print the removal list backwards

struct node {
        char myLetter = ' ';
        bool isStartingPoint = false;
        node *next = NULL;
        node *previous = NULL;
};

class List {
node* head = NULL;
vector<char> removedChars;
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
        // Assign temp to be the new head
        head = temp;
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
node * deleteNode(node* _node){
        if (_node==head) {
                head=_node->next;
        }
        node *previousNode = _node->previous;
        previousNode->next = _node->next;
        _node->next->previous = previousNode;
        delete _node;
        _node=NULL;
        // Returns the next node
        return previousNode->next;
}
void resetStartingPointBools(){
        node *current = head;
        current->isStartingPoint=false;
        current=current->next;
        while (current!=head) {
                current->isStartingPoint=false;
                current=current->next;
        }
}
void removeEveryOtherChar(char startingPoint){
        node *current = head;
        bool everyOther;
        while(current->myLetter!=startingPoint) {
                current = current->next;
        }
        /* This is our starting point and if we started looping from here then
           the way I currently have it, the loop would immediately stop, having
           found a node with startingPoint=true. Instead we do this just before
           the loop and move one over. */
        current->isStartingPoint=true;
        current= current->next;
        everyOther=true;
        while (current->isStartingPoint==false) {
                if(everyOther) {
                        // Add node's letter to list of removedChars
                        removedChars.push_back(current->myLetter);
                        current=deleteNode(current);
                        everyOther= false;
                }else{
                        current=current->next;
                        everyOther=true;
                }
        }
}
string circularPrint(){
        node *current = head;
        stringstream ss;
        cout<<current->myLetter;
        ss<<current->myLetter;
        current=current->next;
        while (current!=head) {
                cout<<current->myLetter;
                ss<<current->myLetter;
                current= current->next;
        }
        cout<<endl;
        return ss.str();
}
void makeCircular(){
        node *current=head;
        while (current->next!=NULL) {
                current= current->next;
        }
        current->next=head;
        head->previous=current;
}
void printRemovedCharacters(){
        for (int i = 0; i < removedChars.size(); i++) {
                cout<<removedChars[i];
        }
        cout<<endl;
}
};


int main(int argc, char *argv[]) {
        string userInput;
        List ourList;
        srand(time(NULL));

        // Get our string from the user
        cout<<"Input: ";
        getline(cin,userInput);
        ourList.setChars(userInput);
        ourList.makeCircular();
        cout<<"Round 1:"<<endl;
        ourList.removeEveryOtherChar(userInput[rand()%userInput.length()]);
        ourList.resetStartingPointBools();
        userInput=ourList.circularPrint();
        ourList.printRemovedCharacters();
        cout<<"Round 2:"<<endl;
        ourList.removeEveryOtherChar(userInput[rand()%userInput.length()]);
        ourList.resetStartingPointBools();
        userInput=ourList.circularPrint();
        ourList.printRemovedCharacters();
        cout<<"Round 3:"<<endl;
        ourList.removeEveryOtherChar(userInput[rand()%userInput.length()]);
        ourList.circularPrint();
        ourList.printRemovedCharacters();



        return 0;
}
