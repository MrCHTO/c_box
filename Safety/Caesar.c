#include <stdio.h>
#include <string.h>
int number = 0;
int dnumber = 0;
char password[100];
char dpassword[100];
void input(int k)
{
    int i;
    printf("please input the password:\n");
    gets(password);
    number = strlen(password);
    for (i = 0; i < number; i++)
    {
        if (password[i] == 32)
        {
            password[i] = 123;
        }
        if (password[i] > 64 && password[i] < 91)
        {
            password[i] = password[i] - 65;
            password[i] = password[i] + k;
            password[i] = password[i] % 52;
        }
        if (password[i] > 96 && password[i] < 123)
        {
            password[i] = password[i] - 71;
            password[i] = password[i] + k;
            password[i] = password[i] % 52;
        }
    }
    for (i = 0; i < number; i++)
    {
        if (password[i] >= 0 && password[i] <= 25)
        {
            password[i] = password[i] + 65;
        }
        if (password[i] >= 26 && password[i] <= 52)
        {
            password[i] = password[i] + 71;
        }
        if (password[i] == 123)
        {
            password[i] = 32;
        }
    }
    puts(password);
}

void output(int k)
{
    int i;
    printf("please input the dpassword:\n");
    gets(dpassword);
    dnumber = strlen(dpassword);
    for (i = 0; i < number; i++)
    {
        if (dpassword[i] == 32)
        {
            dpassword[i] = 123;
        }
        if (dpassword[i] > 64 && dpassword[i] < 91)
        {
            dpassword[i] = dpassword[i] - 65;
            dpassword[i] = dpassword[i] - k;
            if (dpassword[i] < 0)
            {
                dpassword[i] = dpassword[i] + 52;
            }
            dpassword[i] = dpassword[i] % 52;
        }
        if (dpassword[i] > 96 && dpassword[i] < 123)
        {
            dpassword[i] = dpassword[i] - 71;
            dpassword[i] = dpassword[i] - k;
            dpassword[i] = dpassword[i] % 52;
        }
    }
    for (i = 0; i < number; i++)
    {
        if (dpassword[i] >= 0 && dpassword[i] <= 25)
        {
            dpassword[i] = dpassword[i] + 65;
        }
        if (dpassword[i] >= 26 && dpassword[i] <= 52)
        {
            dpassword[i] = dpassword[i] + 71;
        }
        if (dpassword[i] == 123)
        {
            dpassword[i] = 32;
        }
    }
    puts(dpassword);
}

int main()
{
    input(2);
    printf("\n");
    output(2);
    getchar();
}