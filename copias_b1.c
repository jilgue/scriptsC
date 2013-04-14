#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{
	char totaldata[1400];
	char resultado[10];

	sprintf(totaldata, "rsync -va Usuario@192.168.1.19:doc/ /media/datos/backup/charo/2012-11/ > 1.txt");
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
