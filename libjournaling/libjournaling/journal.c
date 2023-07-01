#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
time_t startTime;
time_t startTimeFunLvl;
FILE* ptrToJournal;
int ifExit  = 1;
int recursionCount = 0;

#include<time.h>


void startJournaling()
{
	ptrToJournal = fopen("C:\\Temp\\journal.txt", "w");
	fprintf(ptrToJournal, "Entered the programme through main function \n\n ");
	startTime = time(NULL);
	fclose(ptrToJournal);
}

void stopJournaling()
{
	ptrToJournal = fopen("C:\\Temp\\journal.txt", "a");
	fprintf(ptrToJournal, "Exiting the programme through main function\n\n");
	fclose(ptrToJournal);
}

void startFunctionLvlJournaling(char funName[])
{
	ptrToJournal = fopen("C:\\Temp\\journal.txt", "a");
	static int recursionCount = 0;
	fprintf(ptrToJournal, "\t\tEntering the function %s\n\n", funName);
	if (ifExit == 0)//   0 -- > not exitd   1 -- exited
	{
		recursionCount++;
		fprintf(ptrToJournal, "\t\trecursion count  %d\n\n", recursionCount);
	}
	else
		ifExit = 0;    // ifExit = 0
	fclose(ptrToJournal);

}

void stopFunctionLvlJournaling(char funName[])
{
	ptrToJournal = fopen("C:\\Temp\\journal.txt", "a");
	fprintf(ptrToJournal, "\t\tExiting the function %s\n\n", funName);
	fclose(ptrToJournal);
	ifExit = 1;   //if Exit = 1
	recursionCount = 0;
}

void logInFile(char msg[])
{
	ptrToJournal = fopen("C:\\Temp\\journal.txt", "a");
	fprintf(ptrToJournal,"\t\t\t");
	fputs(msg, ptrToJournal);
	fprintf(ptrToJournal,"\n\n");
	fclose(ptrToJournal);
}

void listFunctionParameters(void* ptrToParameter,int dataType)//1- Int 2- float 3- char 4-double 5 - pointer/Array
{
	ptrToJournal = fopen("C:\\Temp\\journal.txt", "a");	
	if (dataType == 1)
	{
		int a ;
		int* ptrToInt = &a;
		memcpy(ptrToInt, ptrToParameter , sizeof(int) * 1);
		fprintf(ptrToJournal, "\t\t\tparameter type int and value %d \n\n", * ptrToInt);
		fclose(ptrToJournal);
	}
	else if (dataType == 2)
	{
		float b;
		int* ptrToFloat = &b;
		memcpy(ptrToFloat, ptrToParameter, sizeof(float) * 1);
		fprintf(ptrToJournal, "\t\t\tparameter type float and value %d \n\n", *ptrToFloat);
		fclose(ptrToJournal);
	}
	else if(dataType == 3)
	{
		double c;
		double* ptrTodouble = &c;
		memcpy(ptrTodouble, ptrToParameter, sizeof(double) * 1);
		fprintf(ptrToJournal, "\t\t\tparameter type float and value %d \n\n", *ptrTodouble);
		fclose(ptrToJournal);
	}
	else if (dataType == 4)
	{
		fprintf(ptrToJournal,"\t\t\tThe address passed is %d\n\n", ptrToParameter);
		fclose(ptrToJournal);
	}
}
