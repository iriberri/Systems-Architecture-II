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

int main(int argc, char **argv)
{
	
	mqd_t actor2 = init_queue("/actor2", O_CREAT | O_RDONLY);

	message msgreceived;
	//printf("Waiting to receive something\n");

	msgreceived = read_queue(actor2);
	//printf("I got something\n");


	char order[34];
	int me = 0;
	char content[256];
	char nextq[7];
	strcpy(order, msgreceived.order);
	printf("%s order \n", order);

	strcpy(content, msgreceived.content);
	printf("%s content \n", content);
	int i;
	for(i = 0; i<33; i++){
		if (order[i]=='2'){
			if (i <=7){
			//I am the first actor
				me = 1;
			//next = atoi(order[i+9]);
				strncpy(nextq, &order[i]+4, 7);
				nextq[6] = '\0';

			}else if(i<=17){
			//I am the second actor
				me = 2;
				strncpy(nextq, &order[i]+4, 7);
				nextq[6] = '\0';

			}else if(i <= 26){
			//I am the third actor
				me = 3;
				strncpy(nextq, &order[i]+4, 7);
				nextq[6] = '\0';

			}else if (i <=34){
			//I am the fourth actor
				me = 4;
			}
		}
	}


	//write message
	message msg;

	char text[256];
	strcpy(text, msgreceived.content);
	printf("%s text\n", text);
	strcpy(msg.order, order);

	if (me != 4){
		if (me==1){ strcpy (msg.content, "[EscribiendoActor2-");
		}else{
		strcat(text,"EscribiendoActor2-");
		strcpy(msg.content, text);
		}	
	}else{
		strcat(text, "EscribiendoActor2]");
		strcpy(msg.content, text);

	}
	//We know the name of the following queue we have to send to
	char nextqueue[7];
	sprintf(nextqueue, "/%s", nextq);
	mqd_t next;
	if (me!=4){
	
			next = init_queue(nextqueue, O_WRONLY);
	
	}else{
		printf("I'm opening to director\n");
		next = init_queue("/director", O_WRONLY);

	}

	
	write_queue(next, msg);

	printf("I sent\n");

	return 0;

}




