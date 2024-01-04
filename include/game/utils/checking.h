#include <stdio.h>

#define PRINT(level ,format, ...) \
{ \
	printf("[%s]", level);\
	printf(format, ##__VA_ARGS__);\
	printf("\n");\
}

#define CHECK(c, retVal, format, ...) \
{ \
	if (!(c)) { \
		PRINT("CHECK", format, ##__VA_ARGS__); \
		return retVal; \
	} \
}

#define CHECKRETNONE(c, format, ...) \
{ \
	if (!(c)) { \
		PRINT("CHECK", format, ##__VA_ARGS__); \
		return; \
	} \
}

