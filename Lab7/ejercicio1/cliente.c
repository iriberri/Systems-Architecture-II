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
printf("----- Client Running -----\n");
//Inicialización recursos

	int sum;

// - Cola servidor (mqd_t)
// - Cola cliente (mqd_t)

// - Mensaje petición
 peticion peticion1;
// - Mensaje respuesta
//Inicialización de atributos para envío de la petición (struct mq_attr attr)

	struct mq_attr attr;

    attr.mq_flags = 0;
    attr.mq_maxmsg = 3;
    attr.mq_msgsize = sizeof(peticion);
    attr.mq_curmsgs = 0;

    //Cliente abre cola de cliente para esperar respuesta

	mqd_t queue = mq_open("/queue", O_WRONLY | O_CREAT, 0666, &attr);


//Comprobación de apertura correcta
if (queue==-1){
	printf("Error while opening the client queue. %s\n", strerror(errno));
	exit(-1);
}


struct mq_attr attr2;

    attr2.mq_flags = 0;
    attr2.mq_maxmsg = 3;
    attr2.mq_msgsize = sizeof(respuesta);
    attr2.mq_curmsgs = 0;

//Cliente abre cola de servidor para enviar petición
	mqd_t servqueue = mq_open("/servqueue", O_RDONLY | O_CREAT, 0644, &attr2);

//Comprobación de apertura correcta
if (servqueue==-1){
	printf("Error while opening the server queue. %s\n", strerror(errno));
		exit(-1);

}

while(1){
//Cliente rellena mensaje de petición
peticion1.a=rand() % 20;
peticion1.b=rand() % 9;
strcpy(peticion1.q_name, "client");


//Envía mensaje petición a servidor


int send_result = mq_send(queue,(char *)&peticion1, sizeof(peticion), 1);

	if (send_result != -1){
		printf("Message sent correctly. %d + %d\n", peticion1.a, peticion1.b);
	} else {
		printf("There has been an error while sending: %s.\n", strerror(errno));
		exit(-1);

	}

//Cliente espera recepción de respuesta de servidor



printf("Sent. Waiting for message..\n");
		respuesta recvmsg;

		unsigned int prio;
	int result = mq_receive(servqueue, (char *)&recvmsg, sizeof(respuesta), &prio);
	if (result != -1){
		sum = recvmsg.r;
		printf("Message read from queue. %d\n", recvmsg.r);
	} else {
		printf("There has been an error while reading: %s.\n", strerror(errno));
		exit(-1);

	}

sleep(1);
}
//Cierra colas cliente y servidor (close y unlink para el cliente)

if (mq_unlink((char*) servqueue)==0){

 }else{
		printf("There has been an error while unlinking queue: %s.\n", strerror(errno));
 }
 if (mq_close(servqueue)==0){

 }else{

		printf("There has been an error while closing queue: %s.\n", strerror(errno));
 		exit(-1);

 }

if (mq_close(queue)==0){

 }else{


		printf("There has been an error while closing queue: %s.\n", strerror(errno));
 		exit(-1);

 }







}