#pragma once

void startJournaling();

void stopJournaling();

void startFunctionLvlJournaling(char funName[]);

void stopFunctionLvlJournaling(char funName[]);

void logInCmd(char msg[]);