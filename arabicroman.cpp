#include <iostream>
#include <string>


using namespace std;

//divide by 1000
//divide by 500
//divide by 100
//divide by 50
//divide by 10
//divide by 5
// 1, 2, 3

void arabicToRoman(int arab);

int main(){

	arabicToRoman(900);
	arabicToRoman(1000);
	arabicToRoman(400);
	arabicToRoman(500);
	arabicToRoman(90);
	arabicToRoman(100);
	arabicToRoman(40);
	arabicToRoman(50);
	arabicToRoman(9);
	arabicToRoman(10);
	arabicToRoman(4);
	arabicToRoman(5);
	arabicToRoman(2);

	return 0;
}

void arabicToRoman(int arab){
	
	if (arab >= 900){
		if (arab >= 1000){
				cout << "M";
				arab -= 1000;
		}
			else{
				cout << "CM"; arab -= 900;
		}


	}else if (arab >= 400){
			if (arab >= 500){
				cout << "D"; arab -= 500;

			}
			else {
				cout << "CD"; arab -= 400;
			}

		}
		else if (arab >= 90){
			if (arab >= 100){
				cout << "C"; arab -= 100;
			}
			else{
				cout << "XC"; arab -= 90;
			}


		}else if (arab >= 40){
			if (arab >= 50){
				cout << "L"; arab -= 50;
			}
			else {
				cout << "XL"; arab -= 40;
			}


		}else if (arab >= 9){
			if (arab >= 10){
				cout << "X"; arab -= 10;
			}
			else { 
				cout << "IX"; arab -= 9;
			}


		}else if (arab >= 4){
			if (arab >= 5){
				cout << "V"; arab -= 5; 
			}
			else {
				cout << "IV"; arab -= 4;
			}


		}else if (arab >= 1)
		{
				cout << "I";
				--arab;
		}else {

			cout << "ERROR";
		}

	cout << endl;
}