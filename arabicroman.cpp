#include <iostream>
#include <string>


using namespace std;

void arabicToRoman(int arab);

int main(){

	arabicToRoman(3);
	arabicToRoman(2);
	arabicToRoman(1);

	return 0;
}

void arabicToRoman(int arab){
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
	cout << endl;
}