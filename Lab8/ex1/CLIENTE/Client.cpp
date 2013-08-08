#include "StringService.h"
#include <Ice/Ice.h>

using namespace std;
using namespace UC3M;

int
main(int argc, char* argv[])
{
    int status = 0;
    Ice::CommunicatorPtr ic;

    try {
       ic = Ice::initialize(argc, argv);
       Ice::ObjectPrx base = ic->stringToProxy("asii2_adapter:default -p 10800");
       AgendaServicePrx remoteService = AgendaServicePrx::checkedCast(base);
       
       if (!remoteService)throw "Invalid proxy";
       struct informacionSt inf;
            inf=remoteService->ask();
           std::cout << "Nombre: " << inf.nombre <<endl;
          std::cout << "Apellido: " << inf.apellido <<endl;
          std::cout << "Edad: " << inf.edad <<endl;


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
