#include <mqueue.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <mqueue.h>
#include "mensaje.h"


mqd_t init_queue (char* queue_name,int open_flags) {
	struct mq_attr attr;

    attr.mq_flags = 0;
    attr.mq_maxmsg = 3;
    attr.mq_msgsize = sizeof(message);
    attr.mq_curmsgs = 0;
	mqd_t queue = mq_open(queue_name, open_flags, 0666, &attr);
	return queue;
};

static void write_queue (mqd_t mq_desc, message data) {

	int send_result = mq_send(mq_desc,(char*) &data, sizeof(message), 1);

	if (send_result != -1){
		
	} else {
		printf("There has been an error while sending: %s.\n", strerror(errno));
	}
}

static message read_queue (mqd_t mq_desc) {
	message message; 
	unsigned int prio;
	int result = mq_receive(mq_desc, (char *)&message, sizeof(message), &prio);
	if (result != -1){
		
	} else {
		printf("There has been an error while reading: %s.\n", strerror(errno));
	}
	return message;
}

static int close_queue (mqd_t mq_desc) {
	return mq_close(mq_desc);
}
static int unlink_queue (char* queue_name) {
	return mq_unlink(queue_name);
};