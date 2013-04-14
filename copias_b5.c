#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct lista{
	char *quien;
	char *donde;
};

typedef struct lista Lista;

void realizarcopias(Lista *flista, char *fquien[], char *fdonde[], int cuantos, int anio, int mes)
{
	char totaldata[1400];
	char resultado[10];

	int i;

	for(i=0;i<cuantos;i++)
	{
		flista[i].quien=fquien[i];
		flista[i].donde=fdonde[i];

		sprintf(totaldata, "rsync -va %s /media/datos/backup/%s/%d-%d/ > %s",flista[i].donde,flista[i].quien,anio,mes,flista[i].quien);
	//	totaldata="rsync -va Usuario@192.168.1.19:doc/ /media/datos/backup/charo/2012-11/";
		system(totaldata);
	//	printf("%s\n", totaldata);	

		FILE *archivo;
 
        archivo = fopen(flista[i].quien,"r");
 
        if (archivo == NULL)
                exit(1);
 
       
                fgets(resultado,10,archivo);
            printf("%s\n",resultado );

         if(strcmp(resultado,"receiving")==0)
         {
         	printf("copia %s hecha con exito\n",flista[i].quien);
         }	
         else
         {
         	printf("copia %s ha fallado\n",flista[i].quien);
         }

       //  system("echo ' ' > 1.txt");
 
        fclose(archivo);
	}
}

int main()
{
	int cuantos=5;

        int mes,anio;

        time_t real;
        struct tm *actual;
        time(&real);

        actual= localtime (&real);

        anio=(actual->tm_year)+1900;
        mes=(actual->tm_mon)+1;

	Lista copias[cuantos];

	char *quien[]= {"charo","laura","yolanda-portatil","lydia","lydia2"};
	char *donde[]={"Usuario@192.168.1.19:doc/","LAURA@192.168.1.75:doc/","Yolanda@192.168.1.14:datos/","Lydia@192.168.1.65:doc/","Usuario@192.168.1.73:doc/"};

	realizarcopias(copias,quien,donde,cuantos,anio,mes);

        return 0;
}
