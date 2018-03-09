#include <iostream>

using namespace std;

class ColorPapers {

public:
    //int xAxis[101] = {0,}, yAxis[101] = {0,};
    int Start_X_Axis, Start_Y_Axis, width, height, area;

};

ColorPapers colorpapers[105];

int main()
{
    int WorldMap[101][101];
    int N; cin >> N;
    int Area_Table[105] = {0,};

    for(int i = 0; i < 101; i++) {
            for(int j = 0; j < 101; j++){
                WorldMap[i][j] = -1;
            }
        }

    for(int i = 0; i < N; i++)  cin >> colorpapers[i].Start_X_Axis >> colorpapers[i].Start_Y_Axis >> colorpapers[i].width >> colorpapers[i].height;

    //tempX에 총 너비값과 값과 tempY에 총 넓이값을 넣습니다.
    for(int i = 0; i < N; i++) {
        int temp_Start_X = colorpapers[i].Start_X_Axis;
        int temp_Start_Y = colorpapers[i].Start_Y_Axis;
        int tempX = temp_Start_X + colorpapers[i].width;
        int tempY = temp_Start_Y + colorpapers[i].height;
        for(int j = temp_Start_Y; j < tempY; j++)  {
        for(int k = temp_Start_X; k < tempX; k++)  WorldMap[j][k] = i;
        }
    }

        for(int i = 0; i < 101; i++) {
            for(int j = 0; j < 101; j++){
                int idx = WorldMap[i][j];
                if(WorldMap[i][j] != -1)
                Area_Table[idx]++;
            }
        }


    for(int i = 0; i < N; i++) {
        cout << Area_Table[i] << endl;

    }

    return 0;
}
