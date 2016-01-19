/*
OVERVIEW: You are given 2 bank statements that are ordered by date - Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include<stddef.h>
#include<string.h>
#include<malloc.h>
int compare_date(char *, char *);
struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A==NULL||B==NULL)
	return NULL;
	struct transaction *C;
	int i = 0, j = 0,k=0;
	C = (struct transaction *)malloc(sizeof(struct transaction)*(ALen + BLen));
	while (i < ALen&&j < BLen)
	{
		switch (compare_date(A[i].date, B[j].date))
		{
		case -1:C[k].amount = A[i].amount;
			strcpy(C[k].date, A[i].date);
			strcpy(C[k].description, A[i].description);
			k++;
			i++;
			break; 
		case 0:C[k].amount = B[j].amount;
			strcpy(C[k].date, B[j].date);
			strcpy(C[k].description, B[j].description);
			k++;
			j++;
			C[k].amount = A[i].amount;
			strcpy(C[k].date, A[i].date);
			strcpy(C[k].description, A[i].description);
			k++;
			i++;
			break;
		case 1:C[k].amount = B[j].amount;
			strcpy(C[k].date, B[j].date);
			strcpy(C[k].description, B[j].description);
			k++;
			j++;
			break;
		} 
	}
	while (i < ALen)
	{
		C[k].amount = A[i].amount;
		strcpy(C[k].date, A[i].date);
		strcpy(C[k].description, A[i].description);
		k++;
		i++;
	}
	while (j < BLen)
	{
		C[k].amount = B[j].amount;
		strcpy(C[k].date, B[j].date);
		strcpy(C[k].description, B[j].description);
		k++;
		j++;
	}
	return C;
}

int compare_date(char *s, char *t)
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
