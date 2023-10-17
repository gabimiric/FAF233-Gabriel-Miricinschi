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
void email(char s[MAX])
{
    int i=0, k=0, j=0, valid=0, at=0, m=0;
    while (i<strlen(s))
    {
        if (s[i]=='@') {at++; k=i;}
        i++;
    }
    if (at>1||k==0||k==strlen(s)||strchr("~!$%^&*_=+}{'?-.", s[k+1])||strchr("~!$%^&*_=+}{'?-.", s[strlen(s)-1])||strchr("~!$%^&*_=+}{'?-.", s[0]))goto jump;
    else
    {
        for (j=k+1; j<strlen(s); j++)
        {
            if (s[j]=='.') m++;
            if (strchr("~!$%^&*_=+}{'?-.", s[j]) || ((s[j]>='a' || s[j]<='z') || (s[j]>='A' && s[j]<='Z') || (s[j]>='0' && s[j]<='9')))
                valid=1;
            else {valid=0; break;}
        }
        for (j=k-1; j>=0; j--)
        {
            if (strchr("~!$%^&*_=+}{'?-.", s[j]) || ((s[j]>='a' || s[j]<='z') || (s[j]>='A' && s[j]<='Z') || (s[j]>='0' && s[j]<='9')))
                valid=1;
            else {valid=0; break;}
        }
        if (m<1) valid=0;
    }
    jump:
    if (valid) printf("The given string CAN be an email.\n");
    else printf("The given string CANNOT be an email.\n");
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
    int i=0;

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

    printf("\nInput your string: ");
    scanf("%s",&str);
    email(str);
    upper(str);
}
