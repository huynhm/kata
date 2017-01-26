#include <iostream>
#include <string>


using namespace std;

//divide by 1000
//divid by 500
//divide by 100
//divide by 50
//divide by 10
//divide by 5
// 1, 2, 3

void arabicToRoman(int arab);

int main(){

	arabicToRoman(900);
	arabicToRoman(1000);
	//arabicToRoman(1);

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


	}

	/*
	if(arab < 1){
		cout << "Undefeined in Roman Numerals" << endl;
	}

	if( arab >= 1 && arab <= 3){

		while(arab > 0){

			cout  << "I";
			arab--;
		}


	}else if (arab == 4) {

		cout <<  "IV";
	}else if (arab == 5 ){

		cout << "V";
	}
	*/
	cout << endl;
}