#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include<mgba/internal/gba/ToASCII.h>

const int UPPER_ALPHA_OFFSET = -122;
const int LOWER_ALPHA_OFFSET = -116;
const int NUMERIC_OFFSET = -113;

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
      for (int j = 0; j < 1 ; j++)
      {
     	if (c == map[j].key)
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

unsigned char *revert( char ascii_string[], int length, struct Map map[])
{
  unsigned char *encoded_string = malloc(length);

  bool lower_alpha;
  bool upper_alpha;
  bool numeric;
  bool special;

  for (int i = 0; i < length; i++)
  {
    char c = ascii_string[i];
    upper_alpha = (c >= 65) && (c <= 90);
    lower_alpha = (c >= 97) && (c <= 122);
    numeric = (c >= 48) && (c <= 57);
    special = !upper_alpha && !lower_alpha && !numeric;

    if (upper_alpha)
    {
      c -= UPPER_ALPHA_OFFSET;
    }
    else if (lower_alpha)
    {
      c -= LOWER_ALPHA_OFFSET;
    }
    else if (numeric)
    {
      c -= NUMERIC_OFFSET;
    }
    else if(special)
    {
      for (int j = 0; j < 1 ; j++)
      {
     	if (c == map[j].value)
	{
		c = map[0].key;
		break;	
	}
      }

      c = 0x20; //space
    }

    encoded_string[i] = c;
  }

  return encoded_string;
}

int addToMap()
{
	int count = 0;
	poke_char_map[0].key = 0xAB;	//!
	poke_char_map[0].value = 0x21;
	count++;
	poke_char_map[1].key = 0xAC;	//?
	poke_char_map[1].value = 0x3F;  
	count++;

	return count;
}
