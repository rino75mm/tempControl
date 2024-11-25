#include "LiquidOperation.h"

#include <cwctype>
#include <iostream>
using namespace std;

int main()
{
	int trigger = 0;
	while ( 1 ) {
		cout << ">操作番号を選んで下さい" << endl;
		cout << " 1:水の混合と除去" << endl;
		cout << " 2:水の加熱" << endl;
		cout << " 3:プログラムの終了" << endl;

		cin >> trigger;
		switch ( trigger )
		{
		case 1:
			LiquidOperation::doExperiment();
			continue;
		case 2:
			LiquidOperation::heatWater();
			continue;
		case 3:
			cout << ">プログラムを終了します" << endl;
			return 0;
		default:
			cout << ">※もう一度入力し直してください" << endl;
			continue;
		}
	}

	return 0;
}
