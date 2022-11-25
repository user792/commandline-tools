#include <string.h>
#include "strnum.h"

#define MAX_INT64_DIGITS 20
#define MAX_INT64_VALUE_STRING "18446744073709551615"

int is_number(char str[])
{
	for (int i = 0; i < strlen(str); i++)
		if (str[i] > '9' || str[i] < '0') return 0;
	return 1;
}

int larger_than_llu(char str[])
{
	if (strlen(str) < MAX_INT64_DIGITS) return 0;
	if (strlen(str) > MAX_INT64_DIGITS) return 1;

	for (int i = 0; i < MAX_INT64_DIGITS; i++)
	{
		const char max[MAX_INT64_DIGITS] = MAX_INT64_VALUE_STRING;
		if (str[i] == max[i]) continue;
		if (str[i] < max[i]) return 0; 
		if (str[i] > max[i]) return 1; 
	}

	return 0;
}
