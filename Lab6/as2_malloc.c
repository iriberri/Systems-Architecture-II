
#include "as2_malloc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct header_t
{
	allocator_t *ptr_libre ;
	allocator_t *next ;
	size_t size;
};

struct nodes{
	struct header_t header;
	struct nodes *next;
};

typedef struct header_t header_t;


//List of the information of the segments
struct nodes *list;

//definition of the main big header of all the chunk
header_t header_main;

int  headerSize = sizeof(header_t);

allocator_t* as2_init(size_t size)
{ 

	//mem is the complete chunk of memory
	allocator_t *mem = (allocator_t*)malloc(size);
	header_main.next = (mem+headerSize);
	header_main.ptr_libre = mem+headerSize;
	header_main.size = size-headerSize;

	memcpy(mem, &header_main, sizeof(header_t));

	return mem;
}





void* as2_malloc(allocator_t* mem, size_t size)
{ 
//check if there is enough space to allocate the new chunk
	if (header_main.size>size+sizeof(header_t)){

		if (list == NULL){
			struct nodes *list=malloc(sizeof(struct nodes));
			list->next = NULL;

			list->header.ptr_libre=(allocator_t *)((void *)list+headerSize+size);
			list->header.next=(allocator_t *)((void *)list+headerSize+size);
			list->header.size= size;


			header_main.next = (allocator_t *)((void *)list+headerSize+size);
			header_main.ptr_libre = (allocator_t *)((void *)list+headerSize+size);
			header_main.size = header_main.size - size;


		}else{
			struct nodes *aux;

			aux = list;
			while(aux->next!=NULL){
				if (aux->header.ptr_libre==aux->header.next){
					if (aux->header.next - aux->header.ptr_libre >= size+sizeof(header_t)){
						aux->next->next = NULL;
						aux->next->header.ptr_libre=(allocator_t *)((void *)aux+headerSize+size);
						aux->next->header.next=(allocator_t *)((void *)aux+headerSize+size);
						aux->next->header.size= size;

						header_main.next = (allocator_t *)((void *)aux->next+headerSize+size);
						header_main.ptr_libre = (allocator_t *)((void *)aux->next+headerSize+size);
						header_main.size = header_main.size - size;


					}else{



					}
				}
				aux = aux->next;
			}

		}


	}else{

		return NULL;
	}


	return header_main.next;
}


void as2_free(allocator_t* mem, void* ptr)
{ 

	//As we remove the nodes from the list, we add the previous
	//empty segments 


if (ptr == NULL){
	return;
}


struct nodes *aux;
if (list!=NULL){
			while(list->next!=NULL){
				//look for the ptr, we know that the next of aux will be the segment we are looking for
				if (ptr==list->header.next){
					//aux is the node we want to modify			
					aux = list->next;
					list->next=list->next->next;
					header_main.size = header_main.size - aux->header.size - headerSize;
					list->header.ptr_libre=(allocator_t *)((void *)aux->next);
					list->next=aux->next;



				}
			}

/

}
	return;
}




void as2_destroy(allocator_t* mem)
{ 


	free(list);

	free(mem);

	return ;
}

