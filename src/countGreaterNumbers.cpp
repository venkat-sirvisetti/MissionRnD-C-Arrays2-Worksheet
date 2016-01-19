/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include<stddef.h>
#include<string.h>
bool compare(char *, char *);
struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	if (Arr == NULL || date == NULL)
		return NULL;
	if (len < 0||*date=='\0')
		return NULL;
	int i = 0;
	while (i < len)
	{
		if (!compare(Arr[i].date, date))
			break;
		i++;
	}
	return len - i;
}

bool compare(char *s, char *t)
{
	int year1 = 0,year2=0,month1=0,month2=0,day1=0,day2=0;
	year1 = s[6] * 1000 + s[7] * 100 + s[8] * 10 + s[9];
	year2 = t[6] * 1000 + t[7] * 100 + t[8] * 10 + t[9];
	if (year1 < year2)
	{
		return true;
	}
	else if (year1 == year2)
	{
		month1 = s[3] * 10 + s[4];
		month2 = t[3] * 10 + t[4];
		if (month1 < month2)
			return true;
		else if (month1 == month2)
		{
			day1 = s[0] * 10 + s[1];
			day2 = t[0] * 10 + t[1];
			if (day1 <= day2)
			{
				return true;
			}
		}
		else
			return false;
	}
	else
		return false;
	return false;
}
