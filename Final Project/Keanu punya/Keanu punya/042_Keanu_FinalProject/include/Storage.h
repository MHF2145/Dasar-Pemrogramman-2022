#ifndef _STORAGE_H
#define _STORAGE_H

#include "Data.h"

int loadData(const char *path, void *dataStruct, size_t dataSize, size_t dataLength);
int saveData(const char *path, void *dataStruct, size_t dataSize, size_t dataLength);
int loadSettings(const char *path, DataSettings *dataSettings);
int saveSettings(const char *path, DataSettings *dataSettings);

#endif