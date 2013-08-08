#include "CineTicketServiceI.h"
#include "CineTicketService.h"
#include <Ice/Ice.h>
#include <time.h>

using namespace std;
using namespace UC3M;

extern int reserva(int time, int ses);
extern int cancela(int time, int ses);
int status = 0;
Ice::CommunicatorPtr ic[3];
Ice::ObjectPrx base[3];
CineTicketServicePrx remoteService[3];

void *cine (void *t); 
int
main(int argc, char* argv[])
{

 ic[0] = Ice::initialize(argc, argv);
 ic[1] = Ice::initialize(argc, argv);
 ic[2] = Ice::initialize(argc, argv);

 pthread_t clientes[3];
 pthread_attr_t attr;
 pthread_attr_init(&attr);

 pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

 pthread_create(&clientes[0], &attr, cine, (void *)(0));
 pthread_create(&clientes[1], &attr, cine, (void *)(1));
 pthread_create(&clientes[2], &attr, cine, (void *)(2));

 pthread_join(clientes[0], NULL);
 pthread_join(clientes[1], NULL);
 pthread_join(clientes[2], NULL);

 pthread_attr_destroy(&attr);



 return status;

}


void *cine(void *id){

  long int tid=(long int) id;

  srand(time(NULL));

  

  try {

    base[tid] = ic[tid]->stringToProxy("asii2_adapter:default -p 10800");
    remoteService[tid] = CineTicketServicePrx::checkedCast(base[tid]);
    int opt;
    int opt2;
    int reservaOk;
    int cancelaOk;
    if (!remoteService[tid])throw "Invalid proxy";

    while(1)
    {


      opt=rand()%2;
      if (opt == 0){
        opt2 = (rand()%10)+1;

        if (opt2%2==0){

          reservaOk= remoteService[tid]->reserva (22, opt2-1);
          if(reservaOk==0){
            cout<<"Reserva correcta. Sesión 22. Butaca: "<< opt2 << endl;
          }else{
           cout<<"Reserva incorrecta. Sesión 22. Butaca: "<< opt2 << endl;

         }
       }else{

        reservaOk= remoteService[tid]->reserva (01, opt2-1);
        if(reservaOk==0){
          cout<<"Reserva correcta. Sesión 01. Butaca: "<< opt2 << endl;
        }else{
         cout<<"Reserva incorrecta. Sesión 01. Butaca: "<< opt2 << endl;

       }
     }

   }else{
    opt2 = rand()%10;

    if (opt2%2==0){

      cancelaOk = remoteService[tid]->cancela (22, opt2-1);

      if (cancelaOk==0){
        cout<<"Cancelación correcta. Sesión 22. Butaca:"<< opt2<< endl;

      }else{
        cout<<"Cancelación incorrecta. Sesión 22. Butaca:"<< opt2<< endl;

      }
    }else{

      cancelaOk= remoteService[tid]->cancela (01, opt2-1);
      if (cancelaOk==0){
        cout<<"Cancelación correcta. Sesión 01. Butaca:"<< opt2<< endl;

      }else{
        cout<<"Cancelación incorrecta. Sesión 01. Butaca:"<< opt2<< endl;

      }
    }

  }

  sleep(1);
}

} catch (const Ice::Exception& ex) {
 cerr << ex << endl;
 status = 1;
} catch (const char* msg) {
 cerr << msg << endl;
 status = 1;
}
if (ic)
  ic[tid]->destroy();

pthread_exit(NULL);

}
