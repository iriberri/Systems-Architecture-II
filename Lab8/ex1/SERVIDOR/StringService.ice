module UC3M {
   struct informacionSt {
       string nombre;
       string apellido;
       int edad;
   };

   interface AgendaService {
       informacionSt ask();
   };

};
  