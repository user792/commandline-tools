#include <stdio.h>
#include "factor.h"
int main(int argc, const char * argv[])
{
	FILE *fp;
	if (argc == 1)
		factor(stdin, stdout);
	else
		while (--argc > 0)
			if ((fp = fopen(*++argv, "r")) == NULL)
			{
				printf("factor: can't open \"%s\"\n", *argv);
				return 1;
			} 
			else 
			{
				factor(fp, stdout);
				fclose(fp);
			}
	return 0;
}
