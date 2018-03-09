#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;


int main()
{
    char arr[1000005];
    int count = 0;



    gets(arr);

    char *word = strtok(arr, " ");

    while(word != NULL) {
        count++;
        word = strtok(NULL, " ");
    }

    printf("%d" , count);

    return 0;
}
