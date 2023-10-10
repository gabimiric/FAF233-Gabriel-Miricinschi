#include <stdio.h>
#include <string.h>

#define MAX 1000

char str[MAX];

//Base Task: Determine the length of the sentence.
void length(char str[MAX])
{
    int k=0, j=0;
    int isword=0;
    for (int i=0; i<strlen(str); i++)
        {
            if ((str[i]>='0' && str[i]<='9') || (str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z'))
            {
                j++;
                isword=1;
            }
            if (((strchr(" ,;!.?:;()[]{}_\"/", str[i])) && ((str[i-1]>='a' || str[i-1]<='z') || (str[i-1]>='A' && str[i-1]<='Z') || (str[i-1]>='0' && str[i-1]<='9'))))
                if (isword)
                {
                    k++;
                    isword=0;
                }
        }
    printf("The sentence is %d words long, with %d characters.\n", k, j);
}

//Medium Task: Find the amount of punctuation marks used.
void punc(char str[MAX])
{
    int k=0;
    for (int i=0; i<strlen(str); i++)
        if (strchr(",;!.?:;()[]{}_\"/", str[i]))
            k++;
    printf("The number of punctuation marks is %d. \n", k);
}

//Medium Task: Check if the given input is a valid email
void email(char str[MAX])
{
    int i=0, j=0, valid;
    for (i=0; i<=strlen(str); i++)
        if (str[i]=='@') break;
    for (j=i; j<strlen(str); j++)
        if (strchr("~!$%^&*_=+}{'?-.", str[j]) || ((str[i-1]>='a' || str[i-1]<='z') || (str[i-1]>='A' && str[i-1]<='Z') || (str[i-1]>='0' && str[i-1]<='9')))
            valid=1;
    for (j=i; j>=0; j--)
        if (strchr("~!$%^&*_=+}{'?-.", str[j]) || ((str[i-1]>='a' || str[i-1]<='z') || (str[i-1]>='A' && str[i-1]<='Z') || (str[i-1]>='0' && str[i-1]<='9')))
            valid=1;
    if (valid) printf("The given string can be an email.\n");
    else printf("The given string cannot be an email.\n");
}

//Easy Task: Convert the lowercase letters into uppercase
void upper(char str[MAX])
{
    for (int i=0; i<strlen(str); i++)
        if (str[i]>='a' && str[i]<='z') str[i]=str[i]-32;
    for (int i=0; i<strlen(str); i++)
        printf("%c", str[i]);
    printf("\n");
}

int main()
{
    int i;

    printf("Input your sentence: ");
    do
    {
        scanf("%c", &str[i]);
        i++;
    }while(str[i-1]!=';'&&str[i-1]!='!'&&str[i-1]!='.'&&str[i-1]!='?'&&i-1<MAX-1);
    printf("\n");
    str[i]='\0';

    length(str);
    punc(str);

    upper(str);
}
