/*
 * Implementation of htol fuction.
 * It converts input hex string to long value
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long htol(char *str)
{
  long result = 0;
  int pos_value = 0;
  const int hex_base = 16; // need to multiply result with its base

  // string should start from "0x" or "0X"
  if ((str[0] == '0') && (str[1] == 'x' || str[1] == 'X')) {
    // start from position 2 to skip "0x"
    for (int pos_hex = 2, pos_long = 0; pos_hex < strlen(str); pos_hex++, pos_long++) {
      if ('0' <= str[pos_hex] && str[pos_hex] <= '9') {
        // if value in range '0' - '9', just need to substruct '0'
        pos_value = str[pos_hex] - '0';
      } else if('a' <= str[pos_hex] && str[pos_hex] <= 'f') {
        pos_value = str[pos_hex] - 'a' + 10;
      } else if('A' <= str[pos_hex] && str[pos_hex] <= 'F') {
        pos_value = str[pos_hex] - 'A' + 10;
      } else {
        fprintf(stderr, "wrong symbol - %c\n", str[pos_hex]);
        exit(0);
      }

      result = hex_base * result + pos_value;
    }
  }

  return result;
}

int main(int argc, char *argv[])
{
  char hex[] = "0xABCDEF";
  printf("number, input hex = %s, output dec = %ld\n", hex, htol(hex));

  return 0;
}
