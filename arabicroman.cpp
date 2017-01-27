#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void arabicToRoman(int arab);
int romanToArabic(string roman);
void checkBadFormat(string roman);


int main(){

			int i = 1;
			//open file if not created yet
			ifstream infile("output4000.txt");
			if (infile.is_open()){
				string line = "";

				while(getline(infile, line)){
					cout << line <<" : ";
					cout << romanToArabic(line);
					cout << " :  i" << i;
					cout << endl;
					if(i >= 3999){
						break;

					}
					//Check if convertedLine is equal to counter
					if(romanToArabic(line) != i) {
						cout << "ERROR: ArabicConversion NOT EQUAL to counter" << endl;
						break;
					}
					++i;


				}

				infile.close();
				if(i >= 3999){
					cout << endl << "----TESTING for BAD FORMAT. These SHOULD produce errors-------" << endl;
					cout << "VV" << " : ";
					cout << romanToArabic("VV");
					cout << endl;
					cout << "MMMM" << " : ";
					cout << romanToArabic("MMMM");
					cout << endl;
					cout << "CCCXCC" << " : ";
					cout << romanToArabic("CCCXCC");
					cout << endl;
					cout << "XXL" << " : ";
					cout << romanToArabic("XXL");
					cout << endl;
					cout << "CCM" << " : ";
					cout << romanToArabic("CCM");
					cout << endl;
					cout << "VL" << " : ";
					cout << romanToArabic("VL");
					cout << endl;
					cout << "ID" << " : ";
					cout << romanToArabic("ID");
					cout << endl;
					cout << "VX" << " : ";
					cout << romanToArabic("VX");
					cout << endl;
					cout << "DM" << " : ";
					cout << romanToArabic("DM");
					cout << endl;
				}


			}
		// Creating Roman Numerals with 1-3999
		if (i == 1){
			for(int j = 1; j < 4000; ++j ){
						//cout << i << " : ";
				arabicToRoman(j);
			}


		}


	return 0;
}
int romanToArabic(string roman){
	int arab = 0;
	int nexti = 0;

	//check for Bad Format
	checkBadFormat(roman);


	for(int i = 0; i < roman.length(); ++i){
		if(i == roman.length() - 1)
			nexti = i;
		else	
			nexti = i + 1;

		if(roman[i] == 'C' &&  roman[nexti] == 'M' ) {
			arab += 900; ++i;

		}
		else if (roman[i] == 'M') {
			arab += 1000;
		}
		if(roman[i] == 'C' &&  roman[nexti] == 'D' ) {
			arab += 400; ++i;

		}
		else if (roman[i] == 'D') {
			arab += 500;
		}
		if(roman[i] == 'X' &&  roman[nexti] == 'C' ) {
			arab += 90; ++i;

		}
		else if (roman[i] == 'C') {
			arab += 100;
		}
		if(roman[i] == 'X' &&  roman[nexti] == 'L' ) {
			arab += 40; ++i;

		}
		else if (roman[i] == 'L') {
			arab += 50;
		}
		if(roman[i] == 'I' &&  roman[nexti] == 'X' ) {
			arab += 9; ++i;

		}
		else if (roman[i] == 'X') {
			arab += 10;
		}
		if(roman[i] == 'I' &&  roman[nexti] == 'V' ) {
			arab += 4; ++i;

		}
		else if (roman[i] == 'V') {
			arab += 5;
		}else if(roman[i] == 'I'){
			arab += 1;
		}


	}

	return arab;
}

void arabicToRoman(int arab){

	//Start out with Number, print partial value and then subtract values. Repeat until full value is generated
	while(arab > 0){
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

	}


	cout << endl;

}

void checkBadFormat(string roman){
	int vCount = 0; int lCount = 0; int dCount = 0;
	int iCount = 0; int xCount = 0; int cCount = 0; int mCount = 0; 

	// CAN"T have multiple D, V, L
	//I,X,C,M can only appear 3 times in a row and 4 times total
	for(int j = 0; j< roman.length(); j++){

		if (roman[j] ==  'V'){

			++vCount;

		}else if (roman[j] == 'L'){
			++lCount;

		}else if(roman[j] == 'D') {
			++dCount;


		}else if (roman[j] == 'I'){
			++iCount;	

		}else if( roman[j] == 'X'){
			++xCount;

		}else if (roman[j] == 'C'){
			++cCount;
		}else if (roman[j] == 'M') {

			++mCount;
		}

		if( vCount > 1 || lCount > 1 || dCount > 1){
			cout << "ERROR: ONLY 1 instance of "<< roman[j] << ". You have " << iCount << " at j " << j << endl;

			return;

		}
		int prev1 = j - 1;
		int prev2 = j - 2;
		int prev3 = j - 3;

		if(roman[j] == roman[prev1] && roman[prev1] == roman[prev2] && 
			roman[prev2] == roman[prev3] && roman[prev3] == roman[j]){
			cout << "ERROR: ONLY MAX 3 in ROW of " << roman[j] << endl;
			return;

		}
		if(  (roman[prev1] == 'I' && roman[prev2] == 'I' && roman[j] == 'V' ) ||
			(roman[prev1] == 'I' && roman[prev2] == 'I' && roman[j] == 'X' ) ||
			(roman[prev1] == 'X' && roman[prev2] == 'X' && roman[j] == 'L' ) ||
			(roman[prev1] == 'X' && roman[prev2] == 'X' && roman[j] == 'C' ) ||
			(roman[prev1] == 'C' && roman[prev2] == 'C' && roman[j] == 'D' ) ||
			(roman[prev1] == 'C' && roman[prev2] == 'C' && roman[j] == 'M' )

		)
		{
			cout << "ERROR: ONLY 1 MAX SUBTRACT of " << roman[prev2] << " on " << roman[j] << endl;
			return;
		}

		if(roman.length() > 1){
			if(
				((roman[prev1] == 'V' || roman[prev2] == 'V' || roman[prev3] == 'V') && roman[j] == 'X' ) ||

				((roman[prev1] == 'V' || roman[prev2] == 'V' || roman[prev3] == 'V') && roman[j] == 'L' ) ||
				((roman[prev1] == 'I' || roman[prev2] == 'I' || roman[prev3] == 'I') && roman[j] == 'L' ) ||

				((roman[prev1] == 'L' || roman[prev2] == 'L' || roman[prev3] == 'L') && roman[j] == 'C' ) ||
				((roman[prev1] == 'V' || roman[prev2] == 'V' || roman[prev3] == 'V') && roman[j] == 'C' ) ||
				((roman[prev1] == 'I' || roman[prev2] == 'I' || roman[prev3] == 'I') && roman[j] == 'C' ) ||


				((roman[prev1] == 'L' || roman[prev2] == 'L' || roman[prev3] == 'L') && roman[j] == 'D' ) ||
				((roman[prev1] == 'X' || roman[prev2] == 'X' || roman[prev3] == 'X') && roman[j] == 'D' ) ||
				((roman[prev1] == 'V' || roman[prev2] == 'V' || roman[prev3] == 'V') && roman[j] == 'D' ) ||
				((roman[prev1] == 'I' || roman[prev2] == 'I' || roman[prev3] == 'I') && roman[j] == 'D' ) ||

				((roman[prev1] == 'L' || roman[prev2] == 'L' || roman[prev3] == 'L') && roman[j] == 'M' ) ||
				((roman[prev1] == 'D' || roman[prev2] == 'D' || roman[prev3] == 'D') && roman[j] == 'M' ) ||
				((roman[prev1] == 'X' || roman[prev2] == 'X' || roman[prev3] == 'X') && roman[j] == 'M' ) ||
				((roman[prev1] == 'V' || roman[prev2] == 'V' || roman[prev3] == 'V') && roman[j] == 'M' ) ||
				((roman[prev1] == 'I' || roman[prev2] == 'I' || roman[prev3] == 'I') && roman[j] == 'M' )
			)
			{
				cout << "ERROR: INVALID ORDER " << endl;
				return;

			}

		}

		if( iCount > 3 || xCount > 4 || cCount > 4 || mCount > 4 ){

			cout << "ERROR: ONLY MAX 4 instances of "<< roman[j] << endl;
			return;
		}

	}

}
