#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

char document[2501];
char word[51];

int main()
{
    int documentLength;
    int wordLength;

    scanf("%s", document);
    scanf("%s", word);

    documentLength = strlen(document);
    wordLength = strlen(word);

    for(int i = 0; i < documentLength; ++i) {
        if(strncmp(word, document, documentLength / wordLength) == 0)
            printf("%s\n", word);
    }

    return 0;
}
