#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include "factor.h"
#include "strnum.h"

#define MAX_INPUT_LENGTH 20

void factor(FILE *ifp, FILE *ofp)
{
	char str_num[MAX_INPUT_LENGTH + 2];/* 2 additional characters, '\n' from input and '\0' form fgets */

	while((fgets(str_num, MAX_INPUT_LENGTH + 2, ifp)) != NULL)
	{
		if (*str_num == '\n') continue;/* check for empty input */
		if (str_num[strlen(str_num) - 1] != '\n')
		{
			printf("%17.10s...   is too long. Enter at most %d digits.\n", str_num, MAX_INPUT_LENGTH);
			fflush(ofp);
			int c;
			while ((c = getc(ifp)) != EOF) {	
				if (c == '\n') break;
			}
			continue;
		}/* check if input is too long */

		str_num[strlen(str_num) - 1] = '\0';/* remove '\n' from input */

		if (!is_number(str_num))
		{
			printf("%20.20s   contains invalid character(s). Please enter a natural number with no sign or space!\n", str_num);
			fflush(ofp);
			continue;
		}

		if (larger_than_llu(str_num))
		{
			printf("%20.20s   is larger than the upperbound %llu(2^%lu-1).\n", str_num, (uint64_t) -1, sizeof(uint64_t) * 8);
			fflush(ofp);
			continue;
		}

		/* checking done, now calculate */

		uint64_t num;
		sscanf(str_num, "%llu", &num);
		fprintf(ofp, "%20llu = ", num);
		fflush(ofp);

		if (num == 1 || num == 0)
		{
			fprintf(ofp, "%llu\n", num);/* 1 and 0 are special cases */
			fflush(ofp);
		}
		else
		{
			if (num % 2 == 0)
			{
				int repeat_count = 0;
				for (; num % 2 == 0; repeat_count++) num >>= 1;

				if (repeat_count == 1)
				{
					fprintf(ofp, "2");
					fflush(ofp);
				}
				else 
				{
					fprintf(ofp, "2^%d", repeat_count);
					fflush(ofp);
				}


				if (num == 1)
				{
					fprintf(ofp, "\n");
					fflush(ofp);
				}
				else
				{
					fprintf(ofp, " × ");
					fflush(ofp);
				}
			}

			for (uint64_t i = 3; i <= (uint64_t) sqrt((double) num); i += 2)
			{
				int repeat_count = 0;
				for (; num % i == 0; repeat_count++) num /= i;

				if (repeat_count != 0)
				{
					if (repeat_count == 1)
					{
						fprintf(ofp, "%llu", i);
						fflush(ofp);
					}
					else
					{
						fprintf(ofp, "%llu^%d", i, repeat_count);
						fflush(ofp);
					}

					if (num == 1)
					{
						fprintf(ofp, "\n");
						fflush(ofp);
					}
					else
					{
						fprintf(ofp, " × ");
						fflush(ofp);
					}	
				}
			}

			if (num != 1)
			{
				fprintf(ofp, "%llu\n", num);
				fflush(ofp);
			}
		}
	}
}
