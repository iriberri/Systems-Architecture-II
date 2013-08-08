#include "StringServiceI.h"
#include <Ice/Ice.h>
#include <iostream>

using namespace std;
using namespace UC3M;

int
main(int argc, char* argv[])
{
  int status = 0;
  Ice::CommunicatorPtr ic;
  try {
      ic = Ice::initialize(argc, argv);
      Ice::ObjectAdapterPtr adapter = 
           ic->createObjectAdapterWithEndpoints("asii2_adapter", "default -p 10800");
      Ice::ObjectPtr object = new AgendaServiceI;
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
   return status;
}