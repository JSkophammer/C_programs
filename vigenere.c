#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

void encrypt(int key, char plain);

int main(int argc, string argv[])
{
  string plain;
  int cipher[80];

  if (argc != 2)
    {
     printf("Do it right next time!\n");
     return 1; 
    }
  else
    {
     for (int i = 0; i < strlen(argv[1]); i++)
       {
         if (isalpha(argv[1][i]) == 0)
           return 1;
       }
    }

  for (int i = 0; i < strlen(argv[1]); i++)
    {
     char temp;
     if (islower(argv[1][i]))
       temp = toupper(argv[1][i]);
     else
       temp = argv[1][i];

     cipher[i] = ((int)temp) - 65;
    }

   plain = GetString();
   int index = 0;
   for (int i = 0; i < strlen(plain); i++)
     {
      if (((plain[i] < 91) && (plain[i] > 64)) || ((plain[i] < 123) && (plain[i] > 96)))
        {
         encrypt(cipher[index % (strlen(argv[1]))], plain[i]);
         index++;
         }
       else
         printf("%c", plain[i]);
     }
  printf("\n");
  return 0;

}

void encrypt(int key, char plain)
{
    // encrypt capital letters
    int temp = plain;
    if ((temp < 91) && (temp > 64))
      {
       temp = (((temp - 65) + key) % 26) + 65;
       printf("%c", (char)temp);
      }

    // encrypt lowercase letters
    else 
      {
       temp = (((temp - 97) + key) % 26) + 97;
       printf("%c", (char)temp);
      }
}
