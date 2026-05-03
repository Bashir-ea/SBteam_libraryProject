## Function: my_strlen
Problem Understanding (An Example)

    Input: s — character string to measure
    Output: returns number of characters before '\0'
    Edge cases: empty string returns 0, null pointer causes undefined behavior

Algorithm

    Start index i = 0
    While s[i] != '\0'
    Increment i
    Return i

----------------------

## Function: my_strcpy
Problem Understanding (An Example)

    Input: dest — destination array, src — source string
    Output: copies src into dest and returns dest
    Edge cases: empty source copies only '\0', destination must have enough space

Algorithm

    Start index i = 0
    Copy src[i] into dest[i]
    Repeat until '\0'
    Add null terminator
    Return dest

 ----------------------

## Function: my_strncpy
Problem Understanding (An Example)

    Input: ndest — destination array, src — source string, n — max characters
    Output: copies at most n characters into destination
    Edge cases: n <= 0 gives empty string

Algorithm

    Start index i = 0
    While src[i] != '\0' and i < n
    Copy character
    Increment i
    Add '\0'
    Return ndest

----------------------

## Function: my_strcat
Problem Understanding (An Example)

    Input: dest — destination string, src — string to append
    Output: appends src to dest
    Edge cases: empty src changes nothing

Algorithm

    Find end of dest
    Copy src characters after it
    Add '\0'
    Return dest

----------------------

## Function: my_strcmp
Problem Understanding (An Example)

    Input: a, b — two strings
    Output: negative, zero, or positive comparison result
    Edge cases: identical strings return 0

Algorithm

    Compare character by character
    If mismatch found return difference
    If end reached return final difference

----------------------

## Function: my_strncmp
Problem Understanding (An Example)

    Input: a, b — two strings, n — max characters to compare
    Output: compares first n characters only
    Edge cases: n <= 0 returns 0

Algorithm

    Start i = 0
    Compare while i < n
    If mismatch return difference
    If i == n return 0
    Return final difference

----------------------

## Function: my_toUpper
Problem Understanding (An Example)

    Input: s — string
    Output: converts lowercase letters to uppercase
    Edge cases: non-letters unchanged

Algorithm

    Traverse string
    If char is lowercase
    Convert to uppercase
    Continue to end

----------------------

## Function: my_toLower
Problem Understanding (An Example)

    Input: s — string
    Output: converts uppercase letters to lowercase
    Edge cases: non-letters unchanged

Algorithm

    Traverse string
    If char is uppercase
    Convert to lowercase
    Continue to end

----------------------

## Function: reverseStr
Problem Understanding (An Example)

    Input: s — string
    Output: reverses characters in same string
    Edge cases: empty string or one char unchanged

Algorithm

    Set i at start
    Set j at end
    Swap s[i] and s[j]
    Move inward
    Repeat until i < j

----------------------

## Function: countVowels
Problem Understanding (An Example)

    Input: s — string
    Output: returns number of vowels
    Edge cases: empty string returns 0

Algorithm

    Traverse string
    Convert char to lowercase
    If vowel increment count
    Return count

----------------------

## Function: countWords
Problem Understanding (An Example)

    Input: s — sentence string
    Output: returns number of words
    Edge cases: empty string may need special handling

Algorithm

    Traverse string
    Count spaces, tabs, newlines
    Add one final word
    Return total

----------------------

## Function: isPalindrome
Problem Understanding (An Example)

    Input: s — string
    Output: returns 1 if palindrome else 0
    Edge cases: empty string is palindrome

Algorithm

    Set i at start
    Set j at end
    Compare characters
    If mismatch return 0
    Move inward
    If all matched return 1

----------------------

## Function: removeChar
Problem Understanding (An Example)

    Input: s — string, c — character to remove
    Output: removes all c from string
    Edge cases: if c not found string unchanged

Algorithm

    Use read index i and write index j
    If s[i] != c copy to s[j]
    Increment indexes
    Add '\0'

----------------------

## Function: removeSpaces
Problem Understanding (An Example)

    Input: s — string
    Output: removes spaces and tabs
    Edge cases: only spaces gives empty string

Algorithm

    Traverse string
    Keep characters that are not spaces/tabs
    Shift forward
    Add '\0'

 ----------------------

## Function: substring
Problem Understanding (An Example)

    Input: src — source string, start — start position, len — length, dest — result array
    Output: copies selected part into dest
    Edge cases: invalid indexes may cause undefined behavior

Algorithm

    Move to start - 1
    Copy len characters
    Add '\0'

----------------------

## Function: compareIgnoreCase
Problem Understanding (An Example)

    Input: a, b — two strings
    Output: compares strings ignoring case
    Edge cases: "ABC" and "abc" return 0

Algorithm

    Traverse both strings
    Convert chars to lowercase
    Compare them
    If mismatch return difference
    Return final difference