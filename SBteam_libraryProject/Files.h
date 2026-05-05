#pragma once
#ifndef Files_H
#define Files_H

#include"Common.h"

typedef struct {
    int   id;
    char  name[50];
    float score;
    char  category[20];
} Record;

//Create Binary file
int createBinaryFile(const char* filename);
//Write record
int writeRecord(const char* filename, Record* record);
//Read record
int readRecord(const char* filename, Record* record, int index);
//Count records
int countRecords(const char* filename);
//Search record by ID
int searchRecordById(const char* filename, int index, Record* newData);
//Update record
int updateRecord(const char* filename, int index, Record* newData);
//Copy Binary file
int copyBinaryFile(const char* sourceFilename, const char* destFilename);

#endif // !Files_H