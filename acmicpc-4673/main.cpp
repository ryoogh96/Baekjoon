#include <cstdio>

bool selfNum[10001];

void SelfNumber(int constructors) {


        if(constructors < 10)
            constructors = constructors + constructors % 10;
        else if(constructors < 100)
            constructors = constructors + constructors / 10 + constructors % 10;
        else if(constructors < 1000)
            constructors = constructors + (constructors / 10) / 10 + constructors % 100 / 10 + constructors % 10;
        else if(constructors < 10000)
            constructors = constructors + ((constructors / 10) / 10) / 10 + (constructors / 100) % 10 + constructors % 100 / 10 + constructors % 10;

        selfNum[constructors] = true;




}

int main() {


    for(int i = 1; i < 10000; i++) {
        SelfNumber(i);
        if(!selfNum[i]) printf("%d\n",i); // http://blog.naver.com/PostView.nhn?blogId=occidere&logNo=220814758752&parentCategoryNo=&categoryNo=13&viewDate=&isShowPopularPosts=false&from=postView
    }



    /*
    printf("%d\n\n", nonSelfNumber = selfNumber + selfNumber % 10);


    nonSelfNumber = 0;
    selfNumber = 11;

    printf("%d\n\n", nonSelfNumber = selfNumber + selfNumber / 10 + selfNumber % 10);

    nonSelfNumber = 0;
    selfNumber = 111;

    printf("%d\n\n", nonSelfNumber = selfNumber + (selfNumber / 10) / 10 + selfNumber % 100 / 10 + selfNumber % 10);

    nonSelfNumber = 0;
    selfNumber = 1111;

    printf("%d\n\n", nonSelfNumber = selfNumber + ((selfNumber / 10) / 10) % 10 + (selfNumber % 100) / 10 + selfNumber % 1000 / 100 + selfNumber % 10);
    */




    return 0;
}
