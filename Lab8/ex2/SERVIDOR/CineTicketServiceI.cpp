
#include <CineTicketServiceI.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

extern pthread_mutex_t ses22_m;
extern pthread_mutex_t ses01_m; 
extern pthread_cond_t ses22_cv;
extern pthread_cond_t ses01_cv;
extern int sesion22[10];
extern int sesion01[10];

::UC3M::consultasesion
UC3M::CineTicketServiceI::consulta(::Ice::Int horaSesion,
	const Ice::Current& current)
{
	struct consultasesion s;
	int i;
	s.hora = horaSesion;
	if (horaSesion==22){
		for (i=0;i<10;i++){
			s.s[i]=sesion22[i];
		}
	}else if (horaSesion==01){
		for (i=0;i<10;i++){
			s.s[i]=sesion01[i];
		}
	}

	return s;

}



::Ice::Int
UC3M::CineTicketServiceI::reserva(::Ice::Int horaSesion,
	::Ice::Int numeroButaca,
	const Ice::Current& current)
{


	if (horaSesion==22){
		pthread_mutex_lock(&ses22_m);


		if(sesion22[numeroButaca]==0){
			sesion22[numeroButaca]=1;
			pthread_mutex_unlock(&ses22_m);
			return 0;
		}else{
			pthread_mutex_unlock(&ses22_m);
			return 1;
		}

			pthread_mutex_unlock(&ses22_m);



	}else if (horaSesion==01){
		pthread_mutex_lock(&ses01_m);

		if(sesion01[numeroButaca]==0){
			sesion01[numeroButaca]=1;
			pthread_mutex_unlock(&ses01_m);
			return 0;
		}else{
			
			pthread_mutex_unlock(&ses01_m);
			return 1;
		}

		pthread_mutex_unlock(&ses01_m);

	}else{
		return 1;
	}

}

::Ice::Int
UC3M::CineTicketServiceI::cancela(::Ice::Int horaSesion,
	::Ice::Int numeroButaca,
	const Ice::Current& current)
{

	if (horaSesion==22){
		pthread_mutex_lock(&ses22_m);

		if(sesion22[numeroButaca]==1){
			sesion22[numeroButaca]=0;
			pthread_mutex_unlock(&ses22_m);
			return 0;
		}else{
			pthread_mutex_unlock(&ses22_m);
			return 1;
		}
		pthread_mutex_unlock(&ses22_m);

	}else if (horaSesion==01){
		pthread_mutex_lock(&ses01_m);

		if(sesion01[numeroButaca]==1){
			sesion01[numeroButaca]=0;
			pthread_mutex_unlock(&ses01_m);
			return 0;
		}else{
			pthread_mutex_unlock(&ses01_m);
			return 1;
		}

		pthread_mutex_unlock(&ses01_m);

	}else{
		return 1;
	}


	return 0;
}


