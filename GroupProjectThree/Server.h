#include <cstdlib>
#include <iostream>
#include <algorithm>
#include "Customer.h"
using namespace std;

class Server{
  // Array randomly chosen between 5 values
  int *hotDogServingTimes;
  int *hamburgerServingTimes;
  bool isBusy = false;
  // NOTE: Should currentCust be a pointer to a customer instead of making a copy?
  Customer currentCust;
  int cashierAVGHotDog=0,cashierAVGHamburger=0, cashierAVGOrderTime=0;
public:
  // Constructor
Server(int hotdog[],int hamburger[]){
  hotDogServingTimes = hotdog;
  hamburgerServingTimes = hamburger;
}

};
