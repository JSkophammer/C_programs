#include <math.h>
#include <stdio.h>
#include <cs50.h>

double pow(double x, double y);
double fmod(double x, double y);
int num_length(double number);
int get_dig(double number, double digit);
int digit_sum(int multiply, int digit_value);
int checksum(double number);
void det_credit(double number);


int main(void)
{
  double number;
  int check;
  do 
  {
    printf("Number: ");
    number = GetDouble();
    check = checksum(number);
  }
  while (number < 0);

  if ((check % 10) == 0)
    det_credit(number);
  else
    printf("%s\n", "INVALID");

  return 0;
}

int num_length(double number)
{
  int count = 0;
  double modn = 0;
  while (modn != number)
    {
      count++;
      modn = fmod(number, pow(10, count));
    }
  return count;
}

int get_dig(double number, double digit)
{
  double value;
  double ten = 10;
  if (digit <= 0)
    value = 0;
  else if (digit == 1)
    value = fmod(number, ten);
  else
    {
      double power10 = pow(ten, digit - 1);
      value = (fmod(number, pow(ten, digit))-fmod(number, power10))/power10;
    }
  return (int) value;
}

int digit_sum(int multiply, int digit_value)
{
  if (multiply == 1)
    {
      if (digit_value >= 5)
        return 1 + ((2 * digit_value) % 10);
      else
        return 2 * digit_value;
    }
  else
    return digit_value;
}

int checksum(double number)
{
  int even = 0;
  int odd = 0;
  int odd_sum = 0;
  int even_sum = 0;
  int length = num_length(number);
  
  if ((length % 2) == 0)
    odd = 1;
  else
    even = 1;
    
  for (int i = 1; i <= length; i++)
    {    
      int digit_value = get_dig(number, i);
      if ((i % 2) == 0)
        even_sum = even_sum + digit_sum(even, digit_value);
      else
	odd_sum = odd_sum + digit_sum(odd, digit_value);
    }
      
  return even_sum + odd_sum;
}

void det_credit(double number)
{
  int d13 = get_dig(number, 13);
  int d14 = get_dig(number, 14);
  int d15 = get_dig(number, 15);
  int d16 = get_dig(number, 16);
  int length = num_length(number);
      
  if ((length == 15) && (d15 == 3) && ((d14 == 4) || (d14 == 7)))
    printf("%s\n", "AMEX");
  else if ((length == 16) && (d16 == 5) && (d15 < 6) && (d15 > 0))
    printf("%s\n", "MASTERCARD");
  else if (((length = 16) && (d16 == 4)) || ((length = 13) && (d13 == 4)))
    printf("%s\n", "VISA");
  else
    printf("%s\n", "INVALID");
}
