module UC3M {

dictionary<int, int> Seats;

struct consultasesion {
	int hora;
//	int butaca;
	Seats s;
};



interface CineTicketService {

	consultasesion consulta (int horaSesion);
	//Devuelve: 0 si la reserva se ha realizado correctamente o 1 si el asiento pedido ya está ocupado.
	int reserva (int horaSesion, int numeroButaca);
	//Devuelve: 0 si la cancelación se ha realizado correctamente o 1 si el asiento ya estaba libre.
	int cancela (int horaSesion, int numeroButaca);
};

};
