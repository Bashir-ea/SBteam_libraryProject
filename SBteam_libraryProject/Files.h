#pragma once
#ifndef Files_H
#define Files_H

#include"Common.h"
typedef struct {
	int id;
	char name[MAX_STRING_LEN];
	int age;
} Record;
//Create Binary file
int createBinaryFile(const char* filename);
//Write record
int writeRecord(const char* filename, Record* record);
//Read record
int readRecord(const char* filename, Record* record, int index);

#endif // !Files_H