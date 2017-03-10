#include <queue>
#include "ServerList.h"
using namespace std;

class Simulation{
private:
  //Needs two queues one per server
  queue<Customer> aliceQueue;
  queue<Customer> bobQueue;


  // Hour is minutes divided by 60
  int currentHour = 0;
  //currentMinute
  int currentMinute = 1;

  // Wait time
  int runningAVGWaitTime = 0;
  // Simulation Time
  int simulationTimeLimit = 4320;

public:
  void runSimulation(){
    Server alice((int[]){1,2,3,4,5},(int[]){8,9,10,11,12});
    Server bob((int[]){4,5,6,7,8},(int[]){6,7,8,9,10});

    for (currentMinute; currentMinute < simulationTimeLimit; currentMinute++) {
      // Generate customers if neccesary
      generateCustomers(currentMinute);
      cout<<"Current minute is "<<currentMinute<<endl;
      // Check alice's queue

      // Check bob's queue



    // End of for loop
    }
    cout<<"aliceQueue: \n";
    while (aliceQueue.size()) {
      aliceQueue.front().printMe();
      aliceQueue.pop();
    }
    cout<<"bobQueue: \n";
    while (bobQueue.size()){
      bobQueue.front().printMe();
      bobQueue.pop();
    }



    }



// Line that the customers choose is random

//Customer generation
void generateCustomers(int inputTime){
  if (inputTime%5==0) {
    //Generate Customers every five minutes
    Customer temp((rand()%101)+1,inputTime);
    // Randomly into each line
    if (rand()%2==0) {
      aliceQueue.push(temp);
    }else{
    bobQueue.push(temp);
  }
  }
}
};
