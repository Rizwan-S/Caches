#include<stdio.h>
#include "inc/HexToBin.h"
#include "inc/BinToDec.h"
#include "inc/DirectMapped.h"
#include "inc/SetAssociative.h"

int main()
{
	//Open the file and compute the corresponding hit and miss ratio
	printf("DIRECT MAPPED CACHE:\n");

	fp = fopen("traces/gcc.trace", "r");
	if(fp == NULL)
	{
		printf("INPUT FILE MISSING => 'gcc.trace'\n");
	}
	else
	{
		printf("gcc.trace: ");
		DirectMapped();
		fclose(fp);
	}
	
	fp = fopen("traces/gzip.trace", "r");
	if(fp == NULL)
	{
		printf("INPUT FILE MISSING => 'gzip.trace'\n");
	}
	else
	{
		printf("\ngzip.trace: ");
		DirectMapped();
		fclose(fp);
	}	

	fp = fopen("traces/mcf.trace", "r");
	if(fp == NULL)
	{
		printf("INPUT FILE MISSING => 'mcf.trace'\n");
	}
	else
	{
		printf("\nmcf.trace: ");
		DirectMapped();
		fclose(fp);
	}
	
	fp = fopen("traces/swim.trace", "r");
	if(fp == NULL)
	{
		printf("INPUT FILE MISSING => 'swim.trace'\n");
	}
	else
	{	
		printf("\nswim.trace: ");
		DirectMapped();
		fclose(fp);
	}
	
	fp = fopen("traces/twolf.trace", "r");
	if(fp == NULL)
	{
		printf("INPUT FILE MISSING => 'twolf.trace'\n");
	}
	else
	{
		printf("\ntwolf.trace: ");
		DirectMapped();
		fclose(fp);
	}

	printf("\n4 WAY SET ASSOCIATIVE CACHE (Least Recently Used Policy):\n");
	
	fp = fopen("traces/gcc.trace", "r");
	if(fp != NULL)
	{
		printf("gcc.trace: ");
		SetAssociative();
		fclose(fp);
	}
	else
	{
		printf("INPUT FILE MISSING => 'gcc.trace'\n");
	}

	fp = fopen("traces/gzip.trace", "r");
	if(fp != NULL)
	{
		printf("\ngzip.trace: ");
		SetAssociative();
		fclose(fp);
	}
	else
	{
		printf("INPUT FILE MISSING => 'gzip.trace'\n");
	}
	
	fp = fopen("traces/mcf.trace", "r");
	if(fp != NULL)
	{
		printf("\nmcf.trace: ");
		SetAssociative();
		fclose(fp);
	}
	else
	{
		printf("INPUT FILE MISSING => 'mcf.trace'\n");
	}
	
	fp = fopen("traces/swim.trace", "r");
	if(fp != NULL)
	{
		printf("\nswim.trace: ");
		SetAssociative();
		fclose(fp);
	}
	else
	{
		printf("INPUT FILE MISSING => 'swim.trace'\n");
	}

	fp = fopen("traces/twolf.trace", "r");
	if(fp != NULL)
	{
		printf("\ntwolf.trace: ");
		SetAssociative();
		fclose(fp);
	}	
	else
	{
		printf("INPUT FILE MISSING => 'twolf.trace'\n");
	}
	printf("\n");
}
