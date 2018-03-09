#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

bool determineDirect(char prevPlate , char plate)
{
    if(prevPlate == plate) return true;
    else return false;
}

int getHeight()
{
    //int tmp;
    int height = 0;
    char plate[51];
    char prevPlate;
    //string temp;

    gets(plate);
    //strcpy(plate,temp.c_str());
    //tmp = sizeof(plate);

    //printf("%d\n", tmp);

    for(int i = 0; i < strlen(plate); i++)
    {
        //printf("%c",plate[i]);
        if(i == 0) height += 10;
        else if(determineDirect(prevPlate,plate[i]) == true)
                height += 5;
        else height += 10;

        prevPlate = plate[i];
    }

    return height;
}

int main()
{

    printf("%d", getHeight());

    return 0;
}
