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
