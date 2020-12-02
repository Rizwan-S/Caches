#include "../inc/BinToDec.h"

//Converts a segment of binary array to decimal
int BinToDec(char arr[], int s, int e)		
{
	int t = 1;
	int ans = 0;
	for(int i = e; i >= s; i--)
	{
		ans += (arr[i] - '0') * t;
		t *= 2;
	}
	return ans;
}
