#include <iostream>
using namespace std;

enum FoodOrder {UNDECIDED = 0,HOTDOG, HAMBURGER};

class Customer {
private:
FoodOrder order;
int arrivalTime;
int timeWaiting;

public:
Customer(){
        order  = UNDECIDED;
        arrivalTime = 0;
        timeWaiting = 0;
}

Customer(int foodOrderInt,int _arrivalTime){
        if (foodOrderInt<=60) {
                order = HAMBURGER;
        }else{order = HOTDOG;}
        arrivalTime = _arrivalTime;
}
void setWaitTime(int currentTime){
        timeWaiting = currentTime-arrivalTime;
}

FoodOrder getOrder(){
        return order;
}

void printMe(){
        cout<<arrivalTime<<endl;
}

//



};
