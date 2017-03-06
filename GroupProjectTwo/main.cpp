#include "InfixToPostFix.h"
#include <fstream>

using namespace std;
int main(int argc, char* argv[]) {
  string inputName = "infixData.txt",line;
  ifstream myFile(inputName);
  if (!myFile.is_open()) {
    cout<<"Error reading file.\n";
    exit(1);
  }
  while (getline(myFile,line)){
    InfixToPostFix myFix(line);

    cout<<"Infix Expression: ";
    myFix.showInfix();
    cout<<"Postfix Expression: ";
    myFix.showPostfix();
  }


  return 0;

}
