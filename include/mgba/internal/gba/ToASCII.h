#ifndef TOASCII_H
#define TOASCII_H

#define NUM_SPECIAL_CHAR 10

struct Map {
	unsigned char key;;
	unsigned char value;
};

unsigned char *convert(unsigned char[], int, struct Map[]);
unsigned char *revert( char[], int, struct Map[]);

int addToMap();

struct Map poke_char_map[NUM_SPECIAL_CHAR];

#endif