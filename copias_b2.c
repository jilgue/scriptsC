#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


int main()
{
	char totaldata[1400];
	char resultado[10];
        char donde[20];

        int mes,anio;

        time_t real;
        struct tm *actual;
        time(&real);

        actual= localtime (&real);

        anio=(actual->tm_year)+1900;
        mes=(actual->tm_mon)+1;

        sprintf(donde,"Usuario@192.168.1.19:doc/");

	sprintf(totaldata, "rsync -va %s /media/datos/backup/charo/%d-%d/ > 1.txt",donde,anio,mes);
//	totaldata="rsync -va Usuario@192.168.1.19:doc/ /media/datos/backup/charo/2012-11/";
	system(totaldata);
//	printf("resultado %s\n", resultado);


	FILE *archivo;
 
  
 
        archivo = fopen("1.txt","r");
 
        if (archivo == NULL)
                exit(1);
 
       
                fgets(resultado,10,archivo);
            

         if(strcmp(resultado,"receiving")==0)
         		printf("copia hecha con exito\n");
 
        fclose(archivo);

        return 0;
}
