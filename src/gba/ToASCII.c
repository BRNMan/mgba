#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

const int UPPER_ALPHA_OFFSET = -122;
const int LOWER_ALPHA_OFFSET = -116;
const int NUMERIC_OFFSET = -113;
const int NUM_SPECIAL_CHAR = 10;

struct Map {
	unsigned char key;;
	unsigned char value;
};

unsigned char *convert(unsigned char[], int, struct Map[]);

int addToMap();

struct Map map[NUM_SPECIAL_CHAR];

int main()
{
	int mapSize = addToMap();

	unsigned char squirtle[] = {0xCD, 0xE5 ,0xE9, 0xDD, 0xe6, 0xCC, 0xCE, 0xC6, 0xBF, 0xA1, 0xAA, 0xAB};

	unsigned char *new = convert(squirtle, strlen(squirtle), map);

	printf("%s\n", new);
}

unsigned char *convert(unsigned char en_string[], int length, struct Map map[])
{
  unsigned char *ascii_string = malloc(length);

  bool lower_alpha;
  bool upper_alpha;
  bool numeric;
  bool special;

  for (int i = 0; i < length; i++)
  {
    unsigned char c = en_string[i];
    upper_alpha = (c >= 187) && (c <= 212);
    lower_alpha = (c >= 213) && (c <= 238);
    numeric = (c >= 0xA1) && (c <= 0xAA);
    special = !upper_alpha && !lower_alpha && !numeric;

    if (upper_alpha)
    {
      c += UPPER_ALPHA_OFFSET;
    }
    else if (lower_alpha)
    {
      c += LOWER_ALPHA_OFFSET;
    }
    else if (numeric)
    {
      c += NUMERIC_OFFSET;
    }
    else if(special)
    {
      for (int i = 0; i < 1 ; i++)
      {
     	if (c == map[i].key)
	{
		c = map[0].value;
		break;	
	}
      }

      c = 0x20; //space
    }

    ascii_string[i] = c;
  }

  return ascii_string;
}

int addToMap()
{
	int count = 0;
	map[0].key = 0xAB;	//!
	map[0].value = 0x21;
	count++;
	map[1].key = 0xAC;	//?
	map[1].value = 0x3F;  
	count++;

	return count;
}
