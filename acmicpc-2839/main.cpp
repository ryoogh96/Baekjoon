/* 상근이는 요즘 설탕공장에서 설탕을 배달하고 있다. 상근이는 지금 사탕가게에 설탕을 정확하게 N킬로그램을 배달해야 한다.


설탕공장에서 만드는 설탕은 봉지에 담겨져 있다.


봉지는 3킬로그램 봉지와 5킬로그램 봉지가 있다. /3 /5


상근이는 귀찮기 때문에, 최대한 적은 봉지를 들고 가려고 한다. 예를 들어, 18킬로그램 설탕을 배달해야 할 때, 3킬로그램 봉지 6개를 가져가도 되지만,


5킬로그램 3개와 3킬로그램 1개를 배달하면, 더 적은 개수의 봉지를 배달할 수 있다.


상근이가 설탕을 정확하게 N킬로그램 배달해야 할 때, 봉지 몇 개를 가져가면 되는지 그 수를 구하는 프로그램을 작성하시오.

*/

#include <iostream>

using namespace std;

int main()
{
	int kg5, kg3, suger;

	cin >> suger;

	kg5 = suger / 5;

	if(suger % 5 / 3 != 0)
	{
		kg3 = suger % 5 / 3;
		cout << kg5 + kg3 << endl;
	}
	else
		cout << "-1" << endl;


	return 0;

    /*
	int suger,kg5, kg3, result;

	cin >> suger;

	if(suger < 3 || suger > 5000)
	{
		cout << "-1" << endl;

		return 0;
	}

	if(suger / 5 = 0 || suger / 3 = 0 || suger / 8 = 0 || suger / 15 = 0)
        kg5 = suger / 5;
    */

	/*
	kg5 = suger / 5;
    kg3 = (suger / 5) / 3;

    cout << "5kg : " << kg5 << "\n " << endl;
    cout << "3kg : " << kg3 << "\n " << endl;

	if(((suger%5)/3)!=0 || ((suger%5)/3)!=0)
    {
        cout << "-1" << endl;
        return 0;
    }


    result = kg5 + kg3;

    cout << result << endl;

    */


	return 0;
}
