/* ����̴� ���� �������忡�� ������ ����ϰ� �ִ�. ����̴� ���� �������Կ� ������ ��Ȯ�ϰ� Nų�α׷��� ����ؾ� �Ѵ�.


�������忡�� ����� ������ ������ ����� �ִ�.


������ 3ų�α׷� ������ 5ų�α׷� ������ �ִ�. /3 /5


����̴� ������ ������, �ִ��� ���� ������ ��� ������ �Ѵ�. ���� ���, 18ų�α׷� ������ ����ؾ� �� ��, 3ų�α׷� ���� 6���� �������� ������,


5ų�α׷� 3���� 3ų�α׷� 1���� ����ϸ�, �� ���� ������ ������ ����� �� �ִ�.


����̰� ������ ��Ȯ�ϰ� Nų�α׷� ����ؾ� �� ��, ���� �� ���� �������� �Ǵ��� �� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

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
