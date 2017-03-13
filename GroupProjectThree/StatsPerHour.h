#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

class StatsPerHour {
int currentHour;
float globalAVGHotdog;
float globalAVGHamburger;
float globalAVGCustomers;
float globalAVGWait;
vector<double> timesToServeAHotdog;
vector<double> timesToServeAHamburger;
// NOTE: should be careful to increment only a single index across an hour for customersInAnHour
// NOTE: Total customers served is just adding up each vector member without dividing
vector<double> customersInAnHour;
vector<double> waitTimesForCustomer;
void printStatsInColumns(string hour, string avgHotdog, string avgHamburger, string avgCustomers,string avgWait){
        cout<<left<<setw(7)<<hour<<setw(14)<<avgHotdog<<setw(15)
            <<avgHamburger<<setw(15)<<avgCustomers
            <<setw(12)<<avgWait<<endl;
}
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
                printStatsInColumns(to_string(currentHour),to_string(globalAVGHotdog),to_string(globalAVGHamburger),to_string(globalAVGCustomers),to_string(globalAVGWait));
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
float populateAverage(vector<double> input){
        if (input.size()==0) {
                return 0;
        }

        double sum=0;
        for(int i=0; i<input.size(); i++) {
                sum+=input[i];
        }
        return sum/input.size();
}


};
