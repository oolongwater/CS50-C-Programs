#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Get string from user
    string name = get_string("What is your name? ");

    //print string with user's name
    printf("hello, %s/n", name);

}