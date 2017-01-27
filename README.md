# kata

## Roman Numerals

### A. Convert from Arabic to Roman

### B. Convert from Roman to Arabic

* Remove any and all current text files (including the 2 output files). 
..*These were not added to .gitignore, in case a backup is desired to compare. 

`rm *.txt`

* Build:

`g++ arabicroman.cpp -o printroman`

* alternatively use Makefile 

`make clean`
'make'


* Create 3999 Roman Numerals and pipe output to file 

`./printroman > output4000.txt`

* Create arabic numbers from previous outputfile's Roman Numerals, 3rd column ensures convertedArabic is same as counter variable i. Last several rows do testing with purposely badly formated Roman Numerals which Should produce error messages

`./printroman > reverseoutput4000.txt`

* Open the output text files with vi or sublime. 



