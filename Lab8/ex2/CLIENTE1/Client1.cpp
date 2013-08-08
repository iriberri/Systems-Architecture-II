#include "CineTicketServiceI.h"
#include "CineTicketService.h"

#include <Ice/Ice.h>
#include <stdio.h>

using namespace std;
using namespace UC3M;

extern struct consultasesion consulta (int hora);

int main(int argc, char* argv[])
{
  int status = 0;
  Ice::CommunicatorPtr ic;

  try {
   ic = Ice::initialize(argc, argv);
   Ice::ObjectPrx base = ic->stringToProxy("asii2_adapter:default -p 10800");
   CineTicketServicePrx remoteService = CineTicketServicePrx::checkedCast(base);

   if (!remoteService)throw "Invalid proxy";


   int horaSesion;
   struct consultasesion conActual;
   int i;

   while(1){
    horaSesion=0;
        cout<<"Introduzca la hora de la sesión a consultar: (22 o 01)"<< endl;

    while(!(horaSesion==22 || horaSesion==01)){
        cin >> horaSesion;

  }

      conActual = remoteService->consulta(horaSesion);  
      cout<<"Hora sesión:"<< horaSesion<< endl;
      cout<<"Estado de la sala:"<< endl;
      for (i=0; i<10; i++){

        cout<<"["<< i+1 << "]" << conActual.s[i] << endl;

      }

    }
  

} catch (const Ice::Exception& ex) {
 cerr << ex << endl;
 status = 1;
} catch (const char* msg) {
 cerr << msg << endl;
 status = 1;
}
if (ic)
  ic->destroy();

return status;

}
