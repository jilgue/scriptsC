#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct lista{
	char *quien;
	char *donde;
};

typedef struct lista Lista;

int main()
{
	char totaldata[1400];
	char resultado[10];

        int mes,anio;

        time_t real;
        struct tm *actual;
        time(&real);

        actual= localtime (&real);

        anio=(actual->tm_year)+1900;
        mes=(actual->tm_mon)+1;

	Lista copias[2];

	char *quien[]= {"charo","laura"};
	char *donde[]={"Usuario@192.168.1.19:doc/","Usuario@192.168.1.19:doc/laura"};

	int i;

	for(i=0;i<2;i++)
	{
		copias[i].quien=quien[i];
		copias[i].donde=donde[i];

		sprintf(totaldata, "rsync -va %s /media/datos/backup/%s/%d-%d/ > 1.txt",copias[i].donde,copias[i].quien,anio,mes);
	//	totaldata="rsync -va Usuario@192.168.1.19:doc/ /media/datos/backup/charo/2012-11/";
	//	system(totaldata);
		printf("%s\n", totaldata);	
	}

	


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
