#include <string>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

enum SymbolStates {GARBAGE=0, OPERAND, CLOSEPAREN, OPENPAREN, OPERATOR};
enum Precedence {NOTSET=0, PAREN = 6, MULTDIV=5, ADDSUB=4 };

struct PostFixCharacter {
        char myChar = ' ';
        SymbolStates myState = GARBAGE;
        Precedence myPrecedence = NOTSET;

private:
        bool isOperator(char input){
                switch (input) {
                case '*':
                case '+':
                case '/':
                case '-':
                        return true;
                        break;
                default:
                        return false;
                        break;
                }
        }
        Precedence whatsMyPrecedence(char input){
                switch (input) {
                case '(':
                        return PAREN;
                        break;
                case '*':
                case '/':
                        return MULTDIV;
                        break;
                case '+':
                case '-':
                        return ADDSUB;
                        break;
                default:
                        cout<<"Error."<<endl;
                        exit(1);
                        break;
                }
        }

        void whatsMyState(char input){
                if (isalpha(input)) {
                        myState = OPERAND;
                }else if (input=='(') {
                        myState =  OPENPAREN;
                        myPrecedence = PAREN;
                }else if (input==')') {
                        myState =  CLOSEPAREN;
                }else if(isOperator(input)) {
                        myState =  OPERATOR;
                        myPrecedence =whatsMyPrecedence(input);
                }else{
                        myState =  GARBAGE;
                }

        }
public:

        PostFixCharacter(char input){
                myChar = input;
                whatsMyState(input);
        }


};

class InfixToPostFix {
string infix="", postfix="";
vector<PostFixCharacter> convertedInfixString;

stack<PostFixCharacter> operatorStack;


bool greaterThanEqualTo(int i){
  return operatorStack.top().myPrecedence>=convertedInfixString[i].myPrecedence||operatorStack.top().myPrecedence!=PAREN;
}

public:
// Default constructure pops in the string to be worked on
InfixToPostFix(string _infix){
  infix = _infix;
        for (size_t i = 0; i < infix.length(); i++) {
                PostFixCharacter temp(infix[i]);
                convertedInfixString.push_back(temp);
        }
        // printConverted();
        generatePostFix();
}
void printConverted(){
  for (int i = 0; i < convertedInfixString.size(); i++) {
    cout<<"myChar is "<<convertedInfixString[i].myChar<<endl;
    // cout<<"SymbolState is "<<convertedInfixString[i].myState<<endl;
    cout<<"Precedence is "<<convertedInfixString[i].myPrecedence<<endl;
  }
}


void generatePostFix(){
        for (int i = 0; i < convertedInfixString.size(); i++) {
                switch (convertedInfixString[i].myState) {
                case OPERAND:
                        postfix = postfix + convertedInfixString[i].myChar;
                        break;
                case OPENPAREN:
                        operatorStack.push(convertedInfixString[i]);
                        break;
                case CLOSEPAREN:
                        //Pop and append until you hit an open paren that you discard
                        while (operatorStack.top().myPrecedence!=PAREN) {
                                postfix = postfix + operatorStack.top().myChar;
                                operatorStack.pop();
                        }
                        operatorStack.pop();
                        break;
                case OPERATOR:
                        while (!operatorStack.empty()) {
                            postfix = postfix + operatorStack.top().myChar;
                            operatorStack.pop();
                        }
                        operatorStack.push(convertedInfixString[i]);
                        break;
                default:
                        break;
                }
        }
}

void getInfix(string input){
        infix=input;
}
void showInfix(){
        cout<<infix<<endl;
}
void showPostfix(){
        cout<<postfix<<endl;
}



};
