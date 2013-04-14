#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
time_t real;
struct tm *actual;
time(&real);

actual= localtime (&real);

printf ("Fecha: %d-%02d\n", (actual->tm_year)+1900, (actual->tm_mon)+1);

return 0;
}
