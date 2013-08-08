#ifndef __CineTicketServiceI_h__
#define __CineTicketServiceI_h__

#include <CineTicketService.h>

namespace UC3M
{



class CineTicketServiceI : virtual public CineTicketService
{
public:

    virtual ::UC3M::consultasesion consulta(::Ice::Int,
                                            const Ice::Current&);

    virtual ::Ice::Int reserva(::Ice::Int,
                               ::Ice::Int,
                               const Ice::Current&);

    virtual ::Ice::Int cancela(::Ice::Int,
                               ::Ice::Int,
                               const Ice::Current&);
};

}

#endif
