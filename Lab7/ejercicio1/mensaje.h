#define MAXSIZE 256
typedef struct {
int a; /* operando 1 */
int b; /* operando 2 */
char q_name[MAXSIZE]; /* nombre de la cola cliente donde debe enviar la respuesta el servidor */
}peticion;

typedef struct {
int r;
}respuesta;