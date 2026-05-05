#include<stdio.h>
#include<stdlib.h>
#include"Files.h"
#include"Common.h"
#include"pch.h"
//create Binary file
int createBinaryFile(const char* filename) {
	FILE* file = fopen(filename, "wb");
	if (file == NULL) {
		return -1;
	}
	fclose(file);
	return 0;
}
//Write record
int writeRecord(const char* filename, Record* record) {
	FILE* file = fopen(filename, "ab");
	if (file == NULL) {
		return -1;
	}
	if (fwrite(record, sizeof(Record), 1, file) != 1) {
		fclose(file);
		return -1;
	}
	fclose(file);
	return 0;
}
//Read record
int readRecord(const char* filename, Record* record, int index) {
	FILE* file = fopen(filename, "rb");
	if (file == NULL) {
		return -1;
	}
	if (fseek(file, index * sizeof(Record), SEEK_SET) != 0) {
		fclose(file);
		return -1;
	}
	if (fread(record, sizeof(Record), 1, file) != 1) {
		fclose(file);
		return -1;
	}
	fclose(file);
	return 0;
}
// Count records
int countRecords(const char* filename) {
	FILE* file = fopen(filename, "rb");
	if (file == NULL) {
		return -1;
	}
	fseek(file, 0, SEEK_END);
	long fileSize = ftell(file);
	fclose(file);
	return fileSize / sizeof(Record);
}
//Sear ch record by ID
int searchRecordById(const char* filename, int id, Record* result) {
	FILE* file = fopen(filename, "rb");
	if (file == NULL) {
		return -1;
	}
	Record temp;
	int index = 0;
	while (fread(&temp, sizeof(Record), 1, file) == 1) {
		if (temp.id == id) {
			*result = temp;
			fclose(file);
			return index;
		}
		index++;
	}
	fclose(file);
	return -1;
}
//Update record
int updateRecord(const char* filename, int index, Record* newData) {
	FILE* file = fopen(filename, "r+b");
	if (file == NULL) {
		return -1;
	}
	if (fseek(file, index * sizeof(Record), SEEK_SET) != 0) {
		fclose(file);
		return -1;
	}
	if (fwrite(newData, sizeof(Record), 1, file) != 1) {
		fclose(file);
		return -1;
	}
	fclose(file);
	return 0;
}
//Copy Binary file
int copyBinaryFile(const char* sourceFilename, const char* destFilename) {
	FILE* sourceFile = fopen(sourceFilename, "rb");
	FILE* sourceFile = fopen(destFilename, "rb");
	if (sourceFile == NULL) {
		return -1;
	}
	FILE* destFile = fopen(destFilename, "wb");
	if (destFile == NULL) {
		fclose(sourceFile);
		return -1;
	}
	Record temp;
	while (fread(&temp, sizeof(Record), 1, sourceFile) == 1) {
		fwrite(&temp, sizeof(Record), 1, destFile);
	}
	fclose(sourceFile);
	fclose(sourceFile);
	fclose(destFile);
	return 0;
}
