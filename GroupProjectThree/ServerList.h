#include <vector>
#include "Server.h"
using namespace std;

class ServerList{
  int numberOfServers = 0;
  vector<Server> theServers;


void addServer(Server newServer){
  theServers.push_back(newServer);
  numberOfServers++;
}



};
