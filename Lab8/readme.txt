

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


 EJERCICIO 1

EN SERVIDOR

setenv ICE_HOME /usr
gcc -I. -c Server.cpp StringService.cpp StringServiceI.cpp


gcc -o server StringServiceI.o StringService.o Server.o -L$ICE_HOME/lib -lIce -lIceUtil



EN CLIENTE
gcc -I. -c Client.cpp StringService.cpp

gcc -o client StringService.o Client.o -L$ICE_HOME/lib -lIce -lIceUtil





%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%



 EJERCICIO 2

 
EN SERVIDOR
gcc -I. -c Server.cpp CineTicketService.cpp CineTicketServiceI.cpp
setenv ICE_HOME /usr

gcc -o server CineTicketServiceI.o CineTicketService.o Server.o -L$ICE_HOME/lib -lIce -lIceUtil


EN CLIENTE 1

gcc -I. -c Client1.cpp CineTicketService.cpp

gcc -o client CineTicketService.o Client1.o -L$ICE_HOME/lib -lIce -lIceUtil

EN CLIENTE 2

gcc -I. -c Client2.cpp CineTicketService.cpp

gcc -o client CineTicketService.o Client2.o -L$ICE_HOME/lib -lIce -lIceUtil



