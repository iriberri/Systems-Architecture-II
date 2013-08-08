#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <mqueue.h>
#include <errno.h>

#include "mensaje.h"

int main(int argc, char **argv)
{
	printf("----- Server running -----\n");

//Inicialización recursos

	int sum1;
	int sum2;
// - Cola servidor (mqd_t)

// - Cola cliente (mqd_t)

// - Mensaje petición

// - Mensaje respuesta

	mq_unlink("/servqueue");
	mq_unlink("/queue");

	struct mq_attr attr;

	attr.mq_flags = 0;
	attr.mq_maxmsg = 3;
	attr.mq_msgsize = sizeof(peticion);
	attr.mq_curmsgs = 0;
	mqd_t queue = mq_open("/queue", O_CREAT | O_RDONLY, 0666, &attr);

//Inicialización de atributos para envío de la petición (struct mq_attr attr)

	struct mq_attr attr2;

	attr2.mq_flags = 0;
	attr2.mq_maxmsg = 3;
	attr2.mq_msgsize = sizeof(respuesta);
	attr2.mq_curmsgs = 0;
	mqd_t servqueue = mq_open("/servqueue", O_CREAT | O_WRONLY, 0666, &attr2);

//Servidor abre la cola de servidor para esperar mensajes de petición

//Comprueba apertura correcta
	if (servqueue==-1){
		printf("Error abriendo la cola servidor.\n");
		exit(-1);
	}

	peticion msg;
	respuesta msgr;
//Inicio bucle infinito para espera de mensajes de petición
	while(1){
	//Servidor recibe petición
		printf("Waiting for messages..\n");


		unsigned int prio;
		int result = mq_receive(queue, (char *)&msg, sizeof(peticion), &prio);
		if (result != -1){
			printf("Message read from queue: %d + %d\n",msg.a, msg.b);
		} else {
			printf("There has been an error while reading: %s.\n", strerror(errno));
			exit(-1);

		}
//Servidor extrae información del mensaje recibido
		sum1=msg.a;
		sum2=msg.b;
		char name[MAXSIZE];
		strcpy(name, msg.q_name);
//Prepara mensaje de respuesta para cliente
		msgr.r=sum1+sum2;
//Servidor abre cola de mensaje de cliente para enviar respuesta

//Servidor comprueba apertura correcta cola mensajes del cliente
		
//Envía mensaje de respuesta a cliente
		int send_result = mq_send(servqueue,(char*) &msgr, sizeof(respuesta), 1);

		if (send_result != -1){
			printf("Message sent correctly: %d\n", msgr.r);
		} else {
			printf("There has been an error while sending: %s.\n", strerror(errno));
			exit(-1);
		}
	}

//Cierra cola de cliente
	if (mq_close(queue)==0){

	}else{
		printf("Error cerrando cola\n");
		exit(-1);

	}

}