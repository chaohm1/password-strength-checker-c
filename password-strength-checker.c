#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int no_space(char *password, int password_length);
int is_lower(char *password, int password_length);
int is_upper(char *password, int password_length);
int is_digit(char *password, int password_length);
int is_special(char *password, int password_length);
int main(void)
{
  char *password = malloc(100 * sizeof(char));
  char *absence = malloc(100 * sizeof(char));
  if (password == NULL || absence == NULL) 
  {
    printf("Failed");
    if(password) free(password);
    if(absence) free(absence);
    return 1;
  }
  absence[0] = '\0';
  int score = 0;
  printf("Enter Your Password : ");
  fgets(password, 100, stdin);
  int password_length = strlen(password);
  if (password_length > 0 && password[password_length - 1] == '\n')
  {
    password[password_length - 1] = '\0';
    password_length--;
  }
  char *temp_password = realloc(password, (password_length + 1) * sizeof(char));
  if (temp_password == NULL)
  {
    printf("Failed");
    free(password);
    free(absence);
    return 1;
  }
  password = temp_password;
  if (password_length >= 8)
  {
    score += 25;
     if (no_space (password, password_length))
    {
      score += 25;
    } else 
    {
      absence = strcat(absence, ".Remove Spaces\n");
    }
    if (is_lower(password, password_length))
    {
      score += 25;
    } else 
    {
      absence = strcat(absence, ".Add lower Cases\n");
    }
    if (is_upper(password, password_length))
    {
      score += 25;
    } else 
    {
      absence = strcat(absence, ".Add Upper Cases\n");
    }
    if (is_digit(password, password_length))
    {
      score += 25;
    } else 
    {
      absence = strcat(absence, ".Add Digits\n");
    }
    if (is_special(password, password_length))
    {
      score += 25;  
    } else 
    {
      absence = strcat(absence, ".Add Special characters\n");
    }
  } 
  else 
  {
    printf("After reviewing : %s\n", password);
    absence = strcat(absence, "Use longer password (8+ characters)\n");
    printf("Fixes : \n%s", absence);
    free(password);
    free(absence);
    return -1;
  }
  int absence_length = strlen(absence);
  char *temp_absence = realloc(absence, (absence_length + 1) * sizeof(char));
  if (temp_absence == NULL)
  {
    printf("Failed");
    free(password);
    free(absence);
    return 1;
  }
  absence = temp_absence;
  printf("After reviewing : %s\n", password);
  if (score < 150)
  {
    printf("Fixes : \n%s", absence);
  }
  else 
  {
    printf("Your Password is Strong\n");
  }
  free(password);
  free(absence);
  return 0;
}
int no_space(char *password, int password_length)
{
  for (int i = 0; i < password_length; i++)
  {
    if (password[i] == ' ')
    {
      return 0;
    }
  }
  return 1;
}
int is_lower(char *password, int password_length)
{
  for (int i = 0; i < password_length; i++)
  {
    if (password[i] >= 'a' && password[i] <= 'z')
    {
      return 1;
    }
  }
  return 0;
}
int is_upper(char *password, int password_length)
{
  for (int i = 0; i < password_length; i++)
  {
    if (password[i] >= 'A' && password[i] <= 'Z')
    {
      return 1;
    }
  }
  return 0;
}
int is_digit(char *password, int password_length)
{
  for (int i = 0; i < password_length; i++)
  {
    if (password[i] >= '0' && password[i] <= '9')
    {
      return 1;
    }
  }
  return 0;
}
int is_special(char *password, int password_length)
{
  for (int i = 0; i < password_length; i++)
  {
    if(
    password[i] >= 33 && password[i] <= 47 || 
    password[i] >= 58 && password[i] <= 64 || 
    password[i] >= 91 && password[i] <= 96 || 
    password[i] >= 123 && password[i] <= 126)
    {
      return 1;
    }
  }
  return 0;
}