#ifndef BIG_INTEGER
#define BIG_INTEGER

/* Structure To Store The New BIG Data Type.It Includes
   The Character Array That stores the Data.
   The Current Length of the New Data.
   The Sign of the Data
*/
typedef struct {
	char *data;
	size_t length;
	short sign;
} BIG;
BIG* newBIG(char *,size_t);
BIG* add(BIG*,BIG*);
BIG* sub
