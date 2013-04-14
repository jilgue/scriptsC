/*This is rsyn-script V0.2 that pushes and pulles*/
/*written by M00kaw at teh-geek dot com */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char server[80];
char username[80];
char port[80];
char l_path[200];
char r_path[200];
char totaldata[1400];


void getData()
{

printf("Enter the IP/domain of the server:\n");
//fgets(server,sizeof(server),stdin);
gets(server);
printf("Enter the username for the server:\n");
//fgets(username,sizeof(username),stdin);
gets(username);
printf("Enter the port for SSH (eg 22):\n");
//fgets(port,sizeof(port),stdin);
gets(port);
printf("Enter the full local path:\n");
//fgets(l_path,sizeof(l_path),stdin);
gets(l_path);
printf("Enter the full remote path:\n");
//fgets(r_path,sizeof(r_path),stdin);
gets(r_path);
}

void push()
{
	getData();

	sprintf(totaldata, "rsync -avz -e 'ssh -p %s' %s %s@%s:%s", port, l_path, username, server, r_path);
	
	system(totaldata);
/*rsync -avz -e 'ssh -p portNo' /local/path/ username@remotehost:/remote/path */ 
}

void pull()
{
	getData();
	sprintf(totaldata, "rsync -avz -e 'ssh -p %s' %s@%s:%s %s", port, username, server, r_path, l_path);
	
	system(totaldata);
	/*rsync -avz -e 'ssh -p portNo' remoteuser@remotehost:/remote/dir /this/dir/ */			
}


int main()

{
	char choice[10];

	printf("\n[>]Press 1 for push data via Rsync\n");
	printf("[>]Press 2 for pull data via Rsync\n");

	fgets(choice,sizeof(choice),stdin);
	//fgets("%s",&choice);
	//choice = fgetc(stdin);
	
switch (choice[0])
{
	case '1': 
	push();
	break;
	
	case '2':
	pull();
	break;

	default:
 	printf("[>]Press 1 for push data via Rsync\n");
        printf("[>]Press 2 for pull data via Rsync\n");
	break;

}

return 0;
}
