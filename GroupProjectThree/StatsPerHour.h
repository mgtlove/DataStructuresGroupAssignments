#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

class StatsPerHour{
  int currentHour;
  float globalAVGHotdog;
  float globalAVGHamburger;
  float globalAVGCustomers;
  float globalAVGWait;
  vector<int> timesToServeAHotdog;
  vector<int> timesToServeAHamburger;
  // NOTE: should be careful to increment only a single index across an hour for customersInAnHour
  // NOTE: Total customers served is just adding up each vector member without dividing
  vector<int> customersInAnHour;
  vector<int> waitTimesForCustomer;
public:
  void hourTracker(int time){
    currentHour = time/60;

    if (time%60==0) {
      if (currentHour==1) {
          cout<<left<<setw(7)<<"Hour"<<setw(14)<<"AVG-Hotdog"<<setw(15)
              <<"AVG-Hamburger"<<setw(15)<<"AVG-Customers"
              <<setw(12)<<"AVG-Wait"<<endl;
      }
      // Do all the calculations and output
      globalAVGHotdog = populateAverage(timesToServeAHotdog);
      globalAVGCustomers = populateAverage(customersInAnHour);
      globalAVGHamburger = populateAverage(timesToServeAHamburger);
      globalAVGWait = populateAverage(waitTimesForCustomer);

      // Print them
    }
  }

void setHotdogAndGeneralWait(int wait){
  timesToServeAHotdog.push_back(wait);
  waitTimesForCustomer.push_back(wait);
}
void setHamburgerAndGeneralWait(int wait){
  timesToServeAHamburger.push_back(wait);
  waitTimesForCustomer.push_back(wait);
}
float populateAverage(vector<int> input){
  if (input.size()==0) {
    return 0;
  }
  
  int sum=0;
  for(int i=0;i<input.size();i++){
    sum+=input[i];
  }
  return sum/input.size();
}


};
