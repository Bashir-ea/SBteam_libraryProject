
Function: createBinaryFile

Problem Understanding

    Input: filename — C-string path/name of the file to create
    Output: creates (or overwrites) a binary file; returns 0 on success, -1 on failure
    Edge cases:
        filename == NULL (would likely crash/behave undefined inside fopen; caller must pass a valid string)
        if fopen(filename, "wb") fails (permissions, invalid path, etc.) → returns -1
        "wb" truncates an existing file (overwrites contents)

Algorithm

    Open file with mode "wb"
        If open fails, return -1
    Close the file
    Return 0

Function: writeRecord

Problem Understanding

    Input:
        filename — binary file name/path
        record — pointer to a Record to append
    Output: appends one Record at the end of the file; returns 0 on success, -1 on failure
    Edge cases:
        filename == NULL or record == NULL (would cause undefined behavior; caller must pass valid pointers)
        if fopen(filename, "ab") fails → returns -1
        if fwrite fails (disk full, I/O error) → returns -1

Algorithm

    Open file with mode "ab" (append binary)
        If open fails, return -1
    Write one record using fwrite(record, sizeof(Record), 1, file)
        If write count is not 1, close file and return -1
    Close file
    Return 0

Function: readRecord

Problem Understanding

    Input:
        filename — binary file name/path
        record — output pointer where the read Record will be stored
        index — 0-based record index to read
    Output: reads the record at position index into *record; returns 0 on success, -1 on failure
    Edge cases:
        filename == NULL or record == NULL (undefined behavior; caller must pass valid pointers)
        invalid index (negative) can cause incorrect fseek offset (undefined/incorrect behavior)
        if file open fails → -1
        if fseek fails (index beyond file size, or other error) → -1
        if fread returns not 1 (index out of range / EOF) → -1

Algorithm

    Open file with mode "rb"
        If open fails, return -1
    Seek to byte offset index * sizeof(Record) using fseek
        If seek fails, close file and return -1
    Read one record using fread(record, sizeof(Record), 1, file)
        If read count is not 1, close file and return -1
    Close file
    Return 0

Function: countRecords

Problem Understanding

    Input: filename — binary file name/path
    Output: returns the number of Record elements stored in the file; returns -1 on failure
    Edge cases:
        filename == NULL (undefined behavior; caller must pass valid pointer)
        if file open fails → returns -1
        if file size is not an exact multiple of sizeof(Record), the result is truncated (integer division)
        if ftell fails it returns -1L (this code does not check that; could produce incorrect count)

Algorithm

    Open file with mode "rb"
        If open fails, return -1
    Seek to end of file (fseek(file, 0, SEEK_END))
    Get file size in bytes using ftell(file)
    Close file
    Return fileSize / sizeof(Record)

Function: searchRecordById

Problem Understanding

    Input:
        filename — binary file name/path
        id — record id to search for
        result — output pointer where the found record will be copied
    Output: sequentially searches the file; if found, writes the matching record into *result and returns its 0-based index; otherwise returns -1
    Edge cases:
        filename == NULL or result == NULL (undefined behavior; caller must pass valid pointers)
        file open fails → returns -1
        if no record matches, returns -1

Algorithm

    Open file with mode "rb"
        If open fails, return -1
    Initialize index = 0
    While fread(&temp, sizeof(Record), 1, file) == 1
        If temp.id == id
            Copy temp into *result
            Close file
            Return index
        Increment index
    Close file
    Return -1 (not found)

Function: updateRecord

Problem Understanding

    Input:
        filename — binary file name/path
        index — 0-based index of record to overwrite
        newData — pointer to replacement Record
    Output: overwrites the record at index with *newData; returns 0 on success, -1 on failure
    Edge cases:
        filename == NULL or newData == NULL (undefined behavior)
        negative index can cause invalid seek offset (undefined/incorrect behavior)
        if file open fails → -1
        if fseek fails → -1
        if fwrite fails → -1

Algorithm

    Open file with mode "r+b" (read/write binary)
        If open fails, return -1
    Seek to byte offset index * sizeof(Record)
        If seek fails, close file and return -1
    Write one record using fwrite(newData, sizeof(Record), 1, file)
        If write count is not 1, close file and return -1
    Close file
    Return 0

Function: copyBinaryFile

Problem Understanding

    Input:
        sourceFilename — path/name of the source binary file
        destFilename — path/name of the destination binary file
    Output: copies records from source to destination; returns 0 on success, -1 on failure
    Edge cases (as the code is written):
        sourceFilename == NULL or destFilename == NULL (undefined behavior)
        There is a syntax/variable bug in the provided code: it declares FILE* sourceFile twice and attempts to open destFilename into sourceFile. This would not compile / work correctly as-is.
        destination open fails → closes source and returns -1
        write errors are not checked (the code ignores fwrite return value)

Algorithm (intended)

    Open source file "rb"
        If open fails, return -1
    Open destination file "wb"
        If open fails, close source and return -1
    While reading one Record from source succeeds
        Write that Record to destination
    Close both files
    Return 0
