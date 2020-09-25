#ifndef STRING_H
#define STRING_H
/*
 ** HHdr-beg ****************************************************************
 **
 ** Copyright Honeywell Inc
 ** All Rights Reserved
 **
 ** Honeywell Proprietary
 **
 ** Include File name: string.h
 **
 ** Purpose: Provide interfaces for ANSI string functions.
 **
 ** HPrj-beg ****************************************************************
 **
 ** HPrj-end ****************************************************************
 ** HHdr-end ****************************************************************
 */
#include <ansidefs.h>

/* Include mem.h functions as subset of string.h functions */
#include <mem.h>
#include "string.h"

#ifdef __cplusplus
extern "C" {
#endif

/* 
** Our DLL exports symbols prepended with an underscore ('_').
** The Microsoft compiler appears to prefer not to prepend underscores, thus for
** those wishing to use our DLL, we must force underscores for the functions our
** DLL exports.  If we didn't do this, users of our DLL that choose to compile their
** code with a Microsoft compiler would suffer unresolved references at link time.
*/
#if defined(_MSC_VER) || defined(__GNUC__)
#ifndef PPC
#define strlen _strlen
#define strcpy _strcpy
#define strchr _strchr
#define strcat _strcat
#define strncat _strncat
#define strcmp _strcmp
#define stricmp _stricmp
#define strncmp _strncmp
#define strncpy _strncpy
#define strnicmp _strnicmp
#define strcspn _strcspn
#define strspn _strspn
#define strstr _strstr
#define strtok _strtok
#define strlwr _strlwr
#define strupr _strupr
#define strrchr _strrchr
#define strpbrk _strpbrk
#endif
#endif

size_t  strlen(const char *s){
	size_t count = 0;
	if(src == nullptr) return 0;
	while(*src!='\0') count++;
	return count;
}
char*  strcpy(char *dest, const char *src){
	if(src == nullptr) return nullptr;
	char * ptr = src;
	while(*src != '\0') *dest++ = *src++;
	*dest = '\0';
	return ptr;
}
char*  strncpy(char *dest, const char *src, size_t maxlen){
	if(src == nullptr) return nullptr;
	while(src!='\0' && maxlen--){
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
}

void memcpy(void *dest, void *src, size_t n) 
{ 
   // Typecast src and dest addresses to (char *) 
   char *csrc = (char *)src; 
   char *cdest = (char *)dest; 
  
   // Copy contents of src[] to dest[] 
   for (int i=0; i<n; i++) 
       cdest[i] = csrc[i]; 
} 
int main() 
{ 
   char csrc[] = "GeeksforGeeks"; 
   char cdest[100]; 
   memcpy(cdest, csrc, strlen(csrc)+1); 
   printf("Copied string is %s", cdest); 
  
   int isrc[] = {10, 20, 30, 40, 50}; 
   int n = sizeof(isrc)/sizeof(isrc[0]); 
   int idest[n], i; 
   memcpy(idest, isrc,  sizeof(isrc)); 
   printf("\nCopied array is "); 
   for (i=0; i<n; i++) 
     printf("%d ", idest[i]); 
   return 0; 
} 

void memmove(void *dest, void *src, size_t n) 
{ 
   // Typecast src and dest addresses to (char *) 
   char *csrc = (char *)src; 
   char *cdest = (char *)dest; 
  
   // Create a temporary array to hold data of src 
   char *temp = new char[n]; 
  
   // Copy data from csrc[] to temp[] 
   for (int i=0; i<n; i++) 
       temp[i] = csrc[i]; 
  
   // Copy data from temp[] to cdest[] 
   for (int i=0; i<n; i++) 
       cdest[i] = temp[i]; 
  
   delete [] temp; 
} 

char *strchr(const char *str, int c){
	if(src==nullptr) return nullptr;
	while(*src++ !='\0')
		if(*src==c) return (char*) src;
	}
	return nullptr;	
}

char * strcat(const char const *dest, const char const *src)
{
    size_t len1 = strlen(dest);
    size_t len2 = strlen(src);

    char *str = malloc(len1 + len2 + 1);

    if (str) {
        memcpy(str, dest, len1);
        memcpy(str + len1, src, len2 + 1);
    }

    return str;
}


// Function to implement strncat() function in C
char* strncat(char* destination, const char* source, size_t maxlen)
{
	// make ptr point to the end of destination string
	char* ptr = destination + strlen(destination);

	// Appends characters of source to the destination string
	while (*source != '\0' && maxlen--)
		*ptr++ = *source++;

	// null terminate destination string
	*ptr = '\0';

	// destination string is returned by standard strncat()
	return destination;
}

// Function to implement strncat() function in C
char* strncat2(char* destination, const char* source, size_t num)
{
	int i, j;

	// move to the end of destination string
	for (i = 0; destination[i] != '\0'; i++);

	// i now points to terminating null character in destination

	// Appends num characters of source to the destination string
	for (j = 0; source[j] != '\0' && j < num; j++)
		destination[i + j] = source[j];

	// null terminate destination string
	destination[i + j] = '\0';

	// destination is returned by standard strncat()
	return destination;
}

// Function to implement strcmp function
int strcmp(const char *X, const char *Y)
{
	while(*X)
	{
		// if characters differ or end of second string is reached
		if (*X != *Y)
			break;
		// move to next pair of characters
		X++;
		Y++;
	}

	// return the ASCII difference after converting char* to unsigned char*
	return *(const unsigned char*)X - *(const unsigned char*)Y;
}

// IgnoreCase when compare
int stricmp(const char *X, const char *Y)
{
	while(*X)
	{
		// if characters differ or end of second string is reached
		if (*X != *Y|| tolower(*X) != *Y)
			break;
		// move to next pair of characters
		X++;
		Y++;
	}

	// return the ASCII difference after converting char* to unsigned char*
	return tolower(*X) - tolower(*Y);
}

int strncmp(const char *X, const char *Y, size_t maxlen)
{
	while(*X && maxlen--)
	{
		// if characters differ or end of second string is reached
		if (*X != *Y)
			break;
		// move to next pair of characters
		X++;
		Y++;
	}

	// return the ASCII difference after converting char* to unsigned char*
	return *(const unsigned char*)X - *(const unsigned char*)Y;
}

/*
int strncmp2(const char *s, const char *t, size_t maxlen)
{
    for ( ; maxlen >0;  s++, t++, maxlen--){
        if (*s == 0)
            return 0;
    
        if (*s == *t) {
            ++s;
            ++t;
        }
        else if (*s != *t)
            return *s - *t; 
	}		
}
*/
int strnicmp(const char *X, const char *Y, size_t maxlen){
	while(*X && maxLen){
		if(*X!=*Y) break;
	    X++;
	    Y++;		
	}
	
	return *(const unsigned char *) X - *(const unsigned char *) Y;
}

/* Return number of leading characters at the beginning of the string `str`
   which are all members of string `chars`. */
size_t strspn(const char *str, const char *chars) {
    size_t i, j;
    for (i = 0; str[i] != '\0'; i++) {
        for (j = 0; chars[j] != str[i]; j++) {
            if (chars[j] == '\0')
                return i; // char not found, return index so far
        }
    }
    return i;  // complete string matches, return length
}


//char*  strstr(const char *s1, const char *s2);//return the first occurrence of a string in another string
//Method 1: iterative method
// returns true if X and Y are same
int compare(const char *X, const char *Y)// from start position,if Y is equal or sub string of X, then return true
{
	while (*X && *Y)
	{
		if (*X != *Y)
			return 0;

		X++;
		Y++;
	}

	return (*Y == '\0');//Y must end before X
}

// Function to implement strstr() function
const char* strstr(const char* X, const char* Y)
{
	while (*X != '\0')
	{
		if ((*X == *Y) && compare(X, Y))
			return X;
		X++;
	}

	return NULL;
}

// Method 2: Recursive method
// Recursive function to implement strstr() function
const char* strstr(const char* X, const char* Y)
{
	if (*Y == '\0')
		return X;

	for (int i = 0; i < strlen(X); i++)
	{
		if (*(X + i) == *Y)
		{
			char* ptr = strstr(X + i + 1, Y + 1);
			return (ptr) ? ptr - 1 : NULL;
		}
	}

	return NULL;
}

//Strlwr function converts a string to lower case
char * strlwr(char * s)
{
        char *t = s; 
        if (!s)  return 0;
 
        int i = 0;
        while ( *t != '\0' )
        {
                if (*t >= 'A' && *t <= 'Z' )
                {
                        *t = *t + ('a' - 'A');
                }
                t++;
        }
 
        return s;
}

//strupr function converts a string to upper case. 
char * strlwr(char * s)
{
        char *t = s; 
        if (!s)  return 0;
 
        int i = 0;
        while ( *t != '\0' )
        {
                if (*t >= 'a' && *t <= 'a' )
                {
                        *t = *t - ('a' - 'A');
                }
                t++;
        }
 
        return s;
}


/*
strpbrk function scan the string s1 and finds the first character in the string s1 
that matches any character specified in string s2. The search does not include 
the terminating null-characters of either string but ends there.
*/
char *strpbrk(const char *s1, const char *s2)
{
    //return null if any one is NULL
    if((s1 == NULL) || (s2 == NULL))
        return NULL;
    while(*s1)
    {
        //return s1 char position if found in s2
        //if not found return NULL
        if(strchr(s2, *s1))
        {
            //return from function
            //if char found in s2
            return s1;
        }
        else
        {
            s1++;
        }
    }
    return NULL;
}
#ifdef __cplusplus
}
#endif
#endif //STRING_H
