#include <types.h>
#include <string.h>

uint strlen(char *str) {
  uint i = 0;
  while (str[i])
    i++;
  return i;
}

void its(uint num, char *str) {
    char *head = str;
    while (num != 0) {
        // next number is equal to integer value plus zero value in ascii table
        *str++ = num % 10 + '0';
        // remove last number
        num /= 10;
    }

    str = head;

    if (str) {
        char *end = str + strlen(str) - 1;
        char temp;

        while (str < end) {
            temp = *str;
            *str = *end;
            *end = temp;
            str++;
            end--;
        }
    }

    str = head;
}