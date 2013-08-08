#ifndef __StringServiceI_h__
#define __StringServiceI_h__

#include <StringService.h>

namespace UC3M
{

class AgendaServiceI : virtual public AgendaService
{
public:

    virtual ::UC3M::informacionSt ask(const Ice::Current&);
};

}

#endif
