#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include "Customer.h"
using namespace std;

class Server {
// Array randomly chosen between 5 values
int *hotDogServingTimes;
int *hamburgerServingTimes;
int availableAtMin;
bool isBusy=false;
// NOTE: Should currentCust be a pointer to a customer instead of making a copy?
Customer *currentCust;
double cashierAVGHotDog=0,cashierAVGHamburger=0, cashierAVGOrderTime=0;
vector<int> hotDogServingTimesList, hamburgerServingTimesList;

int bookKeeping(int *arrayOfTimes, vector<int> &recordedTimes, int currentTime){
        int waitTime = arrayOfTimes[rand()%5];
        recordedTimes.push_back(waitTime);
        availableAtMin = currentTime + waitTime;
        return waitTime;
}




public:
// Default Constructor
Server(){
        hotDogServingTimes = NULL;
        hamburgerServingTimes = NULL;
        currentCust = NULL;
        isBusy = false;
}
void assignBothServingTimes(int hotdog[],int hamburger[]){
        hotDogServingTimes = hotdog;
        hamburgerServingTimes = hamburger;
}
int serveCustomer (Customer* myCust, int currentTime){

        if (myCust->getOrder()==HAMBURGER) {
                return bookKeeping(hamburgerServingTimes,hamburgerServingTimesList, currentTime);

        }else if(myCust->getOrder()==HOTDOG) {
                return bookKeeping(hotDogServingTimes, hotDogServingTimesList, currentTime);
        }else{exit(1);}


        cashierAVGHotDog = populateAverage(hotDogServingTimesList);
        cashierAVGHamburger = populateAverage(hamburgerServingTimesList);
        isBusy = true;
}
bool serverAvailable(int currentTime){
        if (!isBusy) {
                return true;
        }else{
                if (currentTime>=availableAtMin) {
                        isBusy=false;
                        return true;
                }
                // Should only be reached if busy is true and it isn't time for it to be false yet
                return false;
        }
}
double populateAverage(vector<int> servingTimesList){
  if (servingTimesList.size()==0) {
    return 0;
  }
  double sum=0;
  for(int i=0;i<servingTimesList.size();i++){
    sum+=servingTimesList[i];
  }
  return sum/servingTimesList.size();
}

};
