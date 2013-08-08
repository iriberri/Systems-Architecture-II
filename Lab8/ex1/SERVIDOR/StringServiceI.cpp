
#include <StringServiceI.h>

::UC3M::informacionSt
UC3M::AgendaServiceI::ask(const Ice::Current& current)
{
	struct informacionSt datos;
	datos.nombre="Mike";
       datos.apellido="Wazowsky";
       datos.edad=21;

    return datos;
}
