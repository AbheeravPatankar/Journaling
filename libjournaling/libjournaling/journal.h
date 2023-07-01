#pragma once

void startJournaling();

void stopJournaling();

void startFunctionLvlJournaling(char funName[]);

void stopFunctionLvlJournaling(char funName[]);

void logInFile(char msg[]);

void listFunctionParameters(void* ptrToParameter, int dataType);