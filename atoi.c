#include <stdio.h>
#include <string.h>

int atoi(char *str)
{
  int result = 0;
  int base = 10;
  int sign = 0;

  for(int pos = 0; pos < strlen(str); pos++) {
    if('0' <= str[pos] && str[pos] <= '9') {
      result = result * base + (str[pos] - '0');
    } else if(pos == 0 && str[pos] == '-') {
      sign = 1;
    } else
    {
      fprintf(stderr, "wrong symbol - %c\n", str[pos]);
      return 0;
    }
  }
  if(sign) {
    result *= -1;
  }
  return result;
}

int main(int argc, char *argv[])
{
  char *numbers[] = {"-1234567890",
                    "3623435",
                    "11111",
                    "-343540"};
  for(int i = 0; i < sizeof(numbers) / (sizeof numbers[0]); i++) {
    printf("number[i] = %d\n", atoi(numbers[i]));
  }
  return 0;
}
