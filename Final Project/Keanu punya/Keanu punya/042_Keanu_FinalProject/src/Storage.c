#include <stdio.h>
#include "../include/ErrorList.h"
#include "../include/Data.h"
#include "../include/Storage.h"

int loadData(const char *path, void *dataStruct, size_t dataSize, size_t dataLength) {
    FILE *fptr = fopen(path, "rb");
    if (fptr == NULL) {
        return ERROR_NOFILE;
    }
    fread(dataStruct, dataSize, dataLength, fptr);
    fclose(fptr);
    return PROCCESS_SUCCESS;
}

int saveData(const char *path, void *dataStruct, size_t dataSize, size_t dataLength) {
    FILE *fptr = fopen(path, "wb");
    if (fptr == NULL) {
        return ERROR_NOFILE;
    }
    fwrite(dataStruct, dataSize, dataLength, fptr);
    fclose(fptr);
    return PROCCESS_SUCCESS;
}

int loadSettings(const char *path, DataSettings *dataSettings) {
    FILE *fptr = fopen(path, "rb");
    if (fptr == NULL) {
        return ERROR_NOFILE;
    }
    fread(dataSettings, sizeof(DataSettings), 1, fptr);
    fclose(fptr);
    return PROCCESS_SUCCESS;
}

int saveSettings(const char *path, DataSettings *dataSettings) {
    FILE *fptr = fopen(path, "wb");
    if (fptr == NULL) {
        return ERROR_NOFILE;
    }
    fwrite(dataSettings, sizeof(DataSettings), 1, fptr);
    fclose(fptr);
    return PROCCESS_SUCCESS;
}