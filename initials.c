#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
  string name;
  name = GetString();
  char *initials = malloc(50);
  int index = 1;
  int first = name[0];

  if ((first > 64) && (first < 91))
    initials[0] = name[0];
  else if ((first > 96) && (first < 123))
    {
    first = first - 32;
    initials[0] = (char)first;
    }

  for (int i = 1; i < strlen(name); i++)
    {
    int letter = name[i];
    if ((letter == 32) && (name[i+1] < 123) && (name[i+1] > 96))
      {
      letter = name[i+1] - 32;
      initials[index] = (char)letter;
      //printf("%i\n", letter);
      index++;
      }
    else if (letter == 32)
      {
      initials[index] = name[i + 1];
      index++;
      }
    }
  printf("%s\n", initials);

}
