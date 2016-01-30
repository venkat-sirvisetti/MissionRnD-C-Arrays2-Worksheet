/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
*/

#include<stddef.h>
int findSingleOccurenceNumber(int *A, int len) {
	if (A==NULL||len<0)
	return -1;
	int i = 0, j = 0,index=-1,temp=0;
	for (i = 0; i < len-1; i++)
	{
		index = i+1;
		for (j = i+1; j < len; j++)
		{
			if (A[index]>A[j])
			{
				index = j;
			}
		}
		if (A[i]>A[index])
		{
			temp = A[index];
			A[index] = A[i];
			A[i] = temp;
		}
	}
	for (i = 0; i < len; )
	{
		if (A[i] != A[i + 1])
			return A[i];
		i = i + 3;
	}
	

}