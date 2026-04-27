#include"common.h"
#include"pch.h"
#include <stdio.h>
#include <ctype.h>
#include "stringTool.h"

/* Calcule la longueur d'une chaîne */
int my_strlen(const char* s) {
	int i = 0;
	while (s[i] != '\0') {
		i++;
	} return i;
}

/* Copie une chaîne dans une autre */
char* my_strcpy(char* dest, const char* src) {
	int i = 0;
	while (src[i] != '\0') {
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return dest;
}

/* Copie au maximum n caractères d'une chaîne */
char* my_strncpy(char* ndest, const char* src, int n) {
	int i = 0;
	while (src[i] != '\0' && i != n) {
		if (i < n) {
			ndest[i] = src[i];
		}
		i++;
	}
	ndest[i] = '\0';
	return ndest;
}

/*add a text to copy*/
char* my_strcat(char* dest, const char* src) {
	int j = 0, i = 0;
	while (dest[i] != '\0') {
		i++;
	}
	while (src[j] != '\0') {
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return dest;
}

/* Compare deux chaînes caractère par caractère */
int my_strcmp(const char* a, const char* b)
{
	int i = 0;
	while (a[i] != '\0' && b[i] != '\0')
	{
		if (a[i] != b[i])
			return a[i] - b[i];
		i++;
	}
	return a[i] - b[i];
}

/* Compare les n premiers caractères de deux chaînes */
int my_strncmp(const char* a, const char* b, int n) {
	int i = 0;
	while (i < n && a[i] != '\0' && b[i] != '\0')
	{
		if (a[i] != b[i])
			return a[i] - b[i];
		i++;
	}
	if (i == n)
		return 0;
	return a[i] - b[i];
}

/* Convertit une chaîne en majuscules */
void my_toUpper(char* s) {
	int i = 0;
	while (s[i] != '\0') {
		if (s[i] >= 'a' && s[i] <= 'z') {
			s[i] = toupper(s[i]);
		}i++;
	}
}

/* Convertit une chaîne en minuscules */
void my_toLower(char* s) {
	int i = 0;
	while (s[i] != '\0') {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			s[i] = tolower(s[i]);
		}i++;
	}
}

/*reverse a text*/
void reverseStr(char* s) {
	int i = 0, j = my_strlen(s) - 1;
	char n;
	while (i < j) {
		n = s[i];
		s[i] = s[j];
		s[j] = n;
		i++;
		j--;
	}
}

/*count vowels*/
int countVowels(const char* s) {
	int count = 0, i = 0;
	while (s[i] != '\0') {
		char n = tolower(s[i]);
		if (n == 'a' || n == 'e' || n == 'i' || n == 'u' || n == 'o') {
			count++;
		}i++;
	}return count;
}

/* Compte les mots dans une chaîne*/
int countWords(const char* s) {
	int count = 0, i = 0;
	while (s[i] != '\0') {
		if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t') {
			count++;
		}
		i++;
	}
	if (s[i - 1] != ' ' || s[i - 1] != '\n' || s[i - 1] != '\t') {
		count++;
	}return count;
}

/* Vérifie si une chaîne est un palindrome */
int isPalindrome(const char* s) {
	int i = 0, j = my_strlen(s) - 1;
	while (i < j) {
		if (s[i] != s[j]) {
			i = j;
			return 0;
		}
		else {
			i++;
			j--;
		}
	}return 1;
}

/*remove a char in text*/
void removeChar(char* s, char c) {
	int i = 0, j = 0;
	while (s[i] != '\0') {
		if (s[i] != c) {
			s[j] = s[i];
			j++;
		}
		i++;
	}
	s[j] = '\0';
}

/*remove spaces between word*/
void removeSpaces(char* s) {
	int i = 0, j = 0;
	while (s[i] != '\0') {
		if (s[i] != ' ' && s[i] != '\t') {
			s[j] = s[i];
			j++;
		}
		i++;
	}s[j] = '\0';
}

/*copy a part of text*/
void substring(const char* src, int start, int len, char* dest) {
	int j = start - 1;
	for (int i = 0; i < len; i++) {
		dest[i] = src[j];
		j++;
	}dest[len] = '\0';
}

/* Compare two strings ignoring case sensitivity */
int compareIgnoreCase(const char* a, const char* b) {
	int i = 0;
	while (a[i] != '\0' && b[i] != '\0')
	{
		char c1 = tolower(a[i]);
		char c2 = tolower(b[i]);
		if (c1 != c2)
			return c1 - c2;
		i++;
	}
	return tolower(a[i]) - tolower(b[i]);
}

