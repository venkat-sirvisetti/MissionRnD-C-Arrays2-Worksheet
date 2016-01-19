/*
OVERVIEW: You are given 2 bank statements that are ordered by date. Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include<malloc.h>
#include<string.h>
int compare_date_common(char *, char *);
struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int compare_date_common(char *s, char *t)
{
int year1 = 0, year2 = 0, month1 = 0, month2 = 0, day1 = 0, day2 = 0;
year1 = s[6] * 1000 + s[7] * 100 + s[8] * 10 + s[9];
year2 = t[6] * 1000 + t[7] * 100 + t[8] * 10 + t[9];
if (year1 < year2)
{
return -1;
}
else if (year1 == year2)
{
month1 = s[3] * 10 + s[4];
month2 = t[3] * 10 + t[4];
if (month1 < month2)
return -1;
else if (month1 == month2)
{
day1 = s[0] * 10 + s[1];
day2 = t[0] * 10 + t[1];
if (day1 < day2)
{
return -1;
}
else if (day1 == day2)
return 0;
else
return 1;
}
else
return 1;
}
else
return 1;
return 1;
}

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A==NULL||B==NULL)
	return NULL;
	struct transaction *C=NULL;
	int i = 0, j = 0, k = 0;
	while (i < ALen&&j < BLen)
	{
		switch(compare_date_common(A[i].date, B[j].date))
		{
		case -1:i++;
			break;
		case 0:
			k++;
			j++;
			k++;
			i++;
			break;
		case 1:j++;
			break;
		}
	}
	if (k != 0)
	{
		C = (struct transaction *)malloc(sizeof(struct transaction)*k);
		i = j = k = 0;
		while (i < ALen&&j < BLen)
		{
			switch (compare_date_common(A[i].date, B[j].date))
			{
			case -1:i++;
				break;
			case 0:C[k].amount = B[j].amount;
				strcpy(C[k].date, B[j].date);
				strcpy(C[k].description, B[j].description);
				k++;
				j++;
				i++;
				break;
			case 1:j++;
				break;
			}
		}
	}
	return C;
}

