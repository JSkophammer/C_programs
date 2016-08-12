#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv[])
{
  string plaintext;
  char *ciphertext = malloc(80);

  if (argc != 2)
    {
     printf("Do it right next time!\n");
     return 1; 
    }
  else
    {
     int key = atoi(argv[1]);
     plaintext = GetString();
     for (int i = 0; i < strlen(plaintext); i++)
       {

        // encrypt capital letters
        int temp = plaintext[i];
        if ((temp < 91) && (temp > 64))
         {
          temp = (((temp - 64) + key) % 26) + 64;
          ciphertext[i] = (char)temp;
          printf("%c", ciphertext[i]);
         }

       // encrypt lowercase letters
       else if ((temp < 122) && (temp > 96))
         {
          temp = (((temp - 96) + key) % 26) + 96;
          ciphertext[i] = (char)temp;
          printf("%c", ciphertext[i]);
         }
        
        // pass all other characters without change
        else
          printf("%c", (char)temp);
       }
    }
  printf("\n");
  return 0;

}
