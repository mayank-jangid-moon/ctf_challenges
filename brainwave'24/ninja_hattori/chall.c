#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    char input[50];
    char passcode1[50] = "xUSheUJDdSheUJdsj";
    char passcode2[50] = "eKSjdhAjnSjdhAjsM";
    char passcode3[50] = "sKdjeMDnFSjdhAjds";
    char passcode4[50] = "xUSheUJDdsSjdhAjj";
    char passcode5[50] = "oWdavKSjdhAnDJSas";
    char passcode6[50] = "xSdsdASjdhAjnVwwj";
    char passcode7[50] = "brainwaved";
    
    printf("Please enter the passcode to proceed: ");
    scanf("%s", input);
    if (!strcmp(input, passcode4))
    {
        printf("CONGRATS! Here is your flag\n");
        printf("\n");
        system("cat flag.txt");
    }
    else
    {
        printf("Oops! Bad luck, try again later....\n");
    }
    return 0;
}
