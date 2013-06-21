#include "bool.h"
#ifndef BIG_INTEGER_H
#define BIG_INTEGER_H

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
BIG* newBIG(char*);
BIG* addBIG(BIG*,BIG*);
BIG* subBIG(BIG*,BIG*);
char* toStringBIG(BIG*);
bool equalBIG(BIG* , BIG*);

#endif
