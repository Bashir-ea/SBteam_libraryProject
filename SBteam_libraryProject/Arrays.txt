Function: initArray
Problem Understanding (An Example)

    Input: arr[] — the array storage, *size — current element count (output parameter)
    Output: sets *size = 0 (array becomes “logically empty”)
    Edge cases: size == nullptr (would crash; caller must pass a valid pointer)

Algorithm

    Set *size to 0

Function: printArray
Problem Understanding (An Example)

    Input: ary[] — array to display, size — number of elements to print
    Output: prints elements to stdout in a bracketed format
    Edge cases: size <= 0 (prints empty-ish format), ary == nullptr with size > 0 (undefined behavior)

Algorithm

    Print a header
    Loop i = 0 .. size-1 and print ary[i] with commas between items
    Print closing bracket/line break

Function: insertAt
Problem Understanding (An Example)

    Input: arr[] — array storage, *size — current element count, index — insertion position, value — element to insert
    Output: returns 0 on success, -1 on error; shifts elements right; updates arr[] and increments *size
    Edge cases: index < 0 or index > *size; array full (*size >= MAX_1D); size == nullptr

Algorithm

    Validate index in [0, *size]
    Validate capacity (*size < MAX_1D)
    Shift elements one position right from the end down to index
    Set arr[index] = value
    Increment *size and return 0

Function: deletAt
Problem Understanding (An Example)

    Input: arr[] — array storage, *size — current element count, index — position to delete
    Output: returns 0 on success, -1 on error; shifts elements left; decrements *size
    Edge cases: invalid index; size == nullptr; note: your check index > *size should usually be index >= *size (otherwise index == *size is incorrectly allowed)

Algorithm

    Validate index is within valid range (intended [0, *size-1])
    Shift elements left from index+1 to the end
    Decrement *size
    Return 0

Function: linearSearch
Problem Understanding (An Example)

    Input: arr[] — array to search, size — number of elements, value — target
    Output: returns the index of the first match; returns -1 if not found
    Edge cases: size <= 0; arr == nullptr with size > 0

Algorithm

    For each i from 0 to size-1, compare arr[i] to value
    If equal, return i
    If loop ends, return -1

Function: binarySearch
Problem Understanding (An Example)

    Input: arr[] — sorted array (ascending), size — number of elements, value — target
    Output: returns index if found, otherwise -1
    Edge cases: array not sorted (result undefined/incorrect); size <= 0

Algorithm

    Set low = 0, high = size - 1
    While low <= high:
        Compute mid = (low + high) / 2
        If arr[mid] == value, return mid
        If value < arr[mid], set high = mid - 1
        Else set low = mid + 1
    Return -1

Function: bubbleSort
Problem Understanding (An Example)

    Input: arr[] — array to sort, size — number of elements
    Output: sorts arr[] in ascending order (in-place)
    Edge cases: size <= 1 (already sorted); arr == nullptr with size > 0

Algorithm

    For i = 0 .. size-2:
    For j = 0 .. size-i-2:
    If arr[j] > arr[j+1], swap them

Function: selectionSort
Problem Understanding (An Example)

    Input: arr[], size
    Output: sorts arr[] in ascending order (in-place)
    Edge cases: size <= 1

Algorithm

    For each position i from 0 to size-2:
    Find the index of the smallest element in arr[i..size-1]
    Swap it with arr[i]

Function: insertionSort
Problem Understanding (An Example)

    Input: arr[], size
    Output: sorts arr[] in ascending order (in-place)
    Edge cases: size <= 1

Algorithm

    For i = 1 .. size-1:
    Move arr[i] left by swapping while it is smaller than the element before it

Function: mergeSortedArrays
Problem Understanding (An Example)

    Input: a[] and b[] — sorted arrays, sizeA, sizeB — lengths, out[] — output buffer (must have size at least sizeA + sizeB)
    Output: writes merged sorted sequence into out[]
    Edge cases: inputs not sorted; out overlaps incorrectly (unless carefully intended)

Algorithm

    Use pointers i (for a), j (for b), k (for out)
    While both arrays have remaining elements, copy the smaller next element to out
    Copy any remaining tail of a
    Copy any remaining tail of b

Function: merge
Problem Understanding (An Example)

    Input: arr[] — array being merge-sorted, left, middle, right — indices delimiting two sorted halves
    Output: merges the two sorted halves back into arr[left..right] (in-place via temporary arrays)
    Edge cases: requires 0 <= left <= middle < right; requires temporary buffers sized sufficiently (uses MAX_1D)

Algorithm

    Copy left half into temporary a[]
    Copy right half into temporary b[]
    Call mergeSortedArrays(a, b, sizeA, sizeB, arr + left)

Function: mergeSort
Problem Understanding (An Example)

    Input: arr[], left, right — range to sort (inclusive)
    Output: sorts arr[left..right] ascending
    Edge cases: invalid indices; left >= right (base case)

Algorithm

    If left >= right, return
    Compute middle = (left + right) / 2
    Recursively sort left half
    Recursively sort right half
    Merge the halves with merge()

Function: quickSort
Problem Understanding (An Example)

    Input: arr[], start, end — range to sort (inclusive), uses arr[end] as pivot
    Output: sorts arr[start..end] ascending (in-place)
    Edge cases: start >= end (base case); worst-case performance on already sorted data depending on pivot choice

Algorithm

    If start >= end, return
    Choose pivot as arr[end]
    Partition: move all elements < pivot to the left side
    Put pivot in its final position
    Recursively quicksort left partition
    Recursively quicksort right partition

Function: findMax
Problem Understanding (An Example)

    Input: arr[], size (must be > 0)
    Output: returns the maximum value in the array
    Edge cases: size <= 0 (your code would read arr[0] — undefined behavior)

Algorithm

    Initialize maxVal = arr[0]
    For each remaining element, update maxVal if a larger value is found
    Return maxVal

Function: findMin
Problem Understanding (An Example)

    Input: arr[], size (must be > 0)
    Output: returns the minimum value in the array
    Edge cases: size <= 0 (undefined behavior)

Algorithm

    Initialize minVal = arr[0]
    For each remaining element, update minVal if a smaller value is found
    Return minVal

Function: sumArray
Problem Understanding (An Example)

    Input: arr[], size
    Output: returns sum of all elements
    Edge cases: integer overflow if values/size are large; size <= 0 returns 0

Algorithm

    Initialize sum = 0
    Add each element to sum
    Return sum

Function: avergeArray
Problem Understanding (An Example)

    Input: arr[], size
    Output: returns the arithmetic mean as double
    Edge cases: size == 0 causes division by zero (undefined behavior / crash)

Algorithm

    Compute sumArray(arr, size)
    Convert sum to double
    Divide by size and return

Function: reversarray
Problem Understanding (An Example)

    Input: ary[], size
    Output: reverses the array in-place
    Edge cases: size <= 1 no change

Algorithm

    For i = 0 .. (size/2 - 1), swap ary[i] with ary[size - i - 1]

Function: reserveArray
Problem Understanding (An Example)

    Input: arr[] — source array, size — number of elements to copy, reservedarr[] — destination buffer
    Output: copies first size elements from arr into reservedarr
    Edge cases: destination buffer too small; null pointers

Algorithm

    For i = 0 .. size-1, set reservedarr[i] = arr[i]

Function: restoreArray
Problem Understanding (An Example)

    Input: arr[] — target array, reservedarr[] — saved elements, size — target array size, k — number of elements to restore
    Output: writes reservedarr[0..k-1] into the last k slots of arr
    Edge cases: k > size (writes out of bounds)

Algorithm

    For i = 0 .. k-1, assign arr[size - k + i] = reservedarr[i]

Function: rotateLeft
Problem Understanding (An Example)

    Input: arr[], size — array length, k — number of positions to rotate left
    Output: rotates array left by k in-place (using a temporary buffer)
    Edge cases: size == 0 (mod by zero); k may be larger than size (handled by k %= size)

Algorithm

    Compute k = k % size
    Copy first k elements into a temporary buffer
    Shift the remaining size-k elements left by k
    Copy saved k elements to the end of the array

Function: intMatrix
Problem Understanding (An Example)

    Input: matrix[][MAX_COLS], *rows, *cols
    Output: sets all matrix[i][j] for i < *rows, j < *cols to 0
    Edge cases: rows == nullptr or cols == nullptr; *rows/*cols out of allowed bounds

Algorithm

    For each cell (i, j) within the given dimensions, set it to 0

Function: printMatrix
Problem Understanding (An Example)

    Input: matrix[][MAX_COLS], rows, cols
    Output: prints the matrix in a row-by-row format
    Edge cases: rows <= 0 or cols <= 0

Algorithm

    For each row i, print [ ... ] containing all columns j
    Print separators/newlines for readability

Function: transpoeMatrix
Problem Understanding (An Example)

    Input: matrix[][MAX_COLS], rows (assumes square matrix rows x rows)
    Output: transposes the matrix in-place
    Edge cases: non-square matrix (function only uses rows and assumes columns == rows)

Algorithm

    For each i, for each j > i, swap matrix[i][j] with matrix[j][i]

Function: addMatrices
Problem Understanding (An Example)

    Input: a[][MAX_COLS], b[][MAX_COLS], rows, cols, out[][MAX_COLS]
    Output: out[i][j] = a[i][j] + b[i][j]
    Edge cases: dimension mismatch; aliasing out with a or b (works, but should be intentional)

Algorithm

    For each cell (i, j) compute the sum into out

Function: multiplyMatrices
Problem Understanding (An Example)

    Input: a[][MAX_COLS], b[][MAX_COLS], out[][MAX_COLS], n (assumes all matrices are n x n)
    Output: computes out = a * b using standard matrix multiplication
    Edge cases: n out of bounds; potential integer overflow

Algorithm

    For each output cell (i, j):
    Compute sum = Σ(a[i][k] * b[k][j]) for k = 0..n-1
    Store sum in out[i][j]

Function: sumDiagonal
Problem Understanding (An Example)

    Input: m[][MAX_COLS], size (square matrix size x size)
    Output: returns sum of main diagonal elements m[i][i]
    Edge cases: size <= 0

Algorithm

    Sum m[i][i] for i = 0 .. size-1 and return it

Function: sumAntiDiagonal
Problem Understanding (An Example)

    Input: m[][MAX_COLS], size (square matrix size x size)
    Output: returns sum of anti-diagonal elements
    Edge cases: note: your code currently sums m[size-1-i][size-1-i] which is actually the main diagonal in reverse; intended anti-diagonal is usually m[i][size-1-i]

Algorithm

    For each i, add the anti-diagonal element (intended m[i][size-1-i])
    Return sum

Function: isSymmetric
Problem Understanding (An Example)

    Input: m[][MAX_COLS], size (square matrix)
    Output: returns 1 if symmetric (m[i][j] == m[j][i]), else 0
    Edge cases: non-square matrix not supported by signature/assumption

Algorithm

    For all pairs above the diagonal (j > i), compare m[i][j] and m[j][i]
    If any mismatch, return 0
    Return 1

Function: sortRows
Problem Understanding (An Example)

    Input: m[][MAX_COLS], rows, cols
    Output: sorts each row independently in ascending order
    Edge cases: rows <= 0 or cols <= 1

Algorithm

    For each row i, call bubbleSort(m[i], cols)

Function: initDynamicArray
Problem Understanding (An Example)

    Input: capcity — number of elements to allocate
    Output: returns a pointer to a newly allocated int[]
    Edge cases: capcity <= 0 (allocation behavior may be unexpected); caller must delete[] later

Algorithm

    Allocate new int[capcity]
    Return the pointer

Function: fillArray
Problem Understanding (An Example)

    Input: arr — pointer to dynamic array, size — number of elements to read from stdin
    Output: fills arr[0..size-1] from user input; returns 0
    Edge cases: invalid input handled by clearing std::cin; arr == nullptr

Algorithm

    For each index i:
    Prompt the user and read arr[i]
    If input fails, clear error state and retry until a valid number is entered

Function: printDynamicArray
Problem Understanding (An Example)

    Input: ary — pointer to dynamic array, size
    Output: prints all elements on one line
    Edge cases: size <= 0

Algorithm

    Loop through elements and print them separated by spaces

Function: resizeArray
Problem Understanding (An Example)

    Input: arr — original dynamic array, originalCapacity, newCapacity — requested growth amount (as implemented)
    Output: returns a new pointer with copied elements; deletes old array
    Edge cases: allocation failure; note: your implementation allocates newCapacity + originalCapacity (treats newCapacity as “extra”, not “final capacity”)

Algorithm

    Allocate newArr sized originalCapacity + newCapacity
    Copy the first originalCapacity elements from arr into newArr
    delete[] arr
    Return newArr

Function: freearry
Problem Understanding (An Example)

    Input: arr — pointer to dynamic array allocated with new[]
    Output: frees the dynamic array memory
    Edge cases: setting arr = nullptr inside the function does not update the caller’s pointer because it is passed by value

Algorithm

    Call delete[] arr
    Set local arr to nullptr (local only)
