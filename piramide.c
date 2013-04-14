#include <stdio.h>

int impar(int a);

int main()
{
	int a,j,i,mitad,filas,piramide=1;
	printf("cuantas filas quieres que tenga la pirámide?\n");
	scanf("%d",&a);

	a=impar(a);

	mitad=(int)(a/2);
	filas=mitad+1;

	for(i=0;i<filas;i++)
	{
		for(j=0;j<mitad;j++)
		{
			printf("-");
		}
		for(j=0;j<piramide;j++)
		{
			printf("*");
		}
		for(j=0;j<mitad;j++)
		{
			printf("-");
		}
		mitad--;
		piramide=piramide+2;
		printf("\n");
	}

	return 0;
}

int impar(int a)
{
	if(a%2==0)
	{
		printf("no puede usarse con números pares, ponga un impar, gracias!\n");
		a=0;
	}
	return a;
}