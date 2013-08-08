#include <mqueue.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <mqueue.h>
#include "queues.h"
#include <time.h>


int main(int argc, char **argv)
{

//We are going to choose the order in which the actors will write randomly
	srand (time(NULL));
	int order = rand() % 10;
	char ordermsg[34];

	unlink_queue("/director");
	//unlink_queue("/actor1");
	//unlink_queue("/actor2");
	//unlink_queue("/actor3");
	//unlink_queue("/actor4");


	mqd_t director = init_queue("/director", O_CREAT | O_RDONLY);


	switch (order){
		case 0:
		strcpy(ordermsg,"actor1 - actor2 - actor3 - actor4");
		break;
		case 1:
		strcpy(ordermsg,"actor2 - actor3 - actor4 - actor1");
		break;
		case 2:
		strcpy(ordermsg,"actor3 - actor4 - actor2 - actor1");
		break;
		case 3:
		strcpy(ordermsg,"actor4 - actor1 - actor2 - actor3");
		break;
		case 4:
		strcpy(ordermsg,"actor1 - actor2 - actor3 - actor4");	
		break;
		case 5:
		strcpy(ordermsg,"actor4 - actor3 - actor2 - actor1");
		break;
		case 6:
		strcpy(ordermsg,"actor3 - actor2 - actor1 - actor4");
		break;
		case 7:
		strcpy(ordermsg,"actor2 - actor1 - actor4 - actor3");
		break;
		case 8:
		strcpy(ordermsg,"actor1 - actor4 - actor3 - actor2");
		break;
		case 9:
		strcpy(ordermsg,"actor2 - actor1 - actor3 - actor4");
		break;
		default:
		strcpy(ordermsg,"actor1 - actor2 - actor3 - actor4");
		break;
	}
	printf("%s\n", ordermsg);
ordermsg[33]='\0';
//Depending on which is the first actor to write, we initialize its queue
	int firstASCII = (int)ordermsg[5];
	int first;
	if (firstASCII == 49) first = 1;
	if (firstASCII == 50) first = 2;
	if (firstASCII == 51) first = 3;
	if (firstASCII == 52) first = 4;

	//first = 1;
	//switch (first){
	//	case 1:
		mqd_t actor1 = init_queue("/actor1", O_CREAT | O_WRONLY);
	//	break;
	//	case 2:
		mqd_t actor2 = init_queue("/actor2", O_CREAT | O_WRONLY);
	//	break;
	//	case 3:
		mqd_t actor3 = init_queue("/actor3", O_CREAT | O_WRONLY);
	//	break;
	//	case 4:
		mqd_t actor4 = init_queue("/actor4", O_CREAT | O_WRONLY);
	//	break;
	//}


	message msg;
	strcpy(msg.order, ordermsg);
	//printf("%s\n", msg.order);
	strcpy(msg.content, "[");
	//printf("%s \n", msg.content);

	printf("first %d \n", first);
	switch (first){
		case 1:
		write_queue(actor1, msg);
			//printf("sent to %d \n", first);

		break;
		case 2:
		write_queue(actor2, msg);
			//printf("sent to %d \n", first);

		break;
		case 3:
		write_queue(actor3, msg);
			//printf("sent to %d \n", first);

		break;
		case 4:
		write_queue(actor4, msg);
			//printf("sent to %d \n", first);

		break;
	}

//We wait for the message to come back again from the last actor
//We can wait for its specific queue because we know which is
	message received;
	//printf("Waiting...\n");

	 received = read_queue(director);
	
	//printf("Received\n");

	printf("%s \n",  received.content);

close_queue(director);
close_queue(actor1);
close_queue(actor2);
close_queue(actor3);
close_queue(actor4);
	return 0;

}