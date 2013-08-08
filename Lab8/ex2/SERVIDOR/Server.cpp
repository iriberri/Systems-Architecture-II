#include "CineTicketServiceI.h"
#include <Ice/Ice.h>
#include <iostream>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;
using namespace UC3M;

int sesion22[10];
int sesion01[10];

pthread_mutex_t ses22_m;
pthread_mutex_t ses01_m; 

int
main(int argc, char* argv[])
{
  int status = 0;

  pthread_attr_t attr;
  pthread_mutex_init(&ses22_m, NULL);
  pthread_mutex_init(&ses01_m, NULL);

  Ice::CommunicatorPtr ic;
  try {
    ic = Ice::initialize(argc, argv);
    Ice::ObjectAdapterPtr adapter = 
    ic->createObjectAdapterWithEndpoints("asii2_adapter", "default -p 10800");
    Ice::ObjectPtr object = new CineTicketServiceI;
    adapter->add(object, ic->stringToIdentity("asii2_adapter"));
    adapter->activate();
    ic->waitForShutdown();


  } catch (const Ice::Exception& e) {
   cerr << e << endl;
   status = 1;
 } catch (const char* msg) {
   cerr << msg << endl;
   status = 1;
 }

 if (ic) {
  try {
   ic->destroy();
 } catch (const Ice::Exception& e) {
   cerr << e << endl;
   status = 1;
 }
}


pthread_mutex_destroy(&ses22_m);
pthread_mutex_destroy(&ses01_m);

return status;
}