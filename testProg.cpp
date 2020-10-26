#include <iostream>
#include <map>
#include <string>
#include <cctype>
#include <fstream>
#include <iomanip>
using namespace std;
// Function Declarations

void readFile(string infile,int letters[]);
void display(int letters[]);
int main() {
   const int SIZE=26;
// Declaring variables
int letters[SIZE]={0};

string infile;
  
//defines an input stream for the data file
ifstream dataIn;

//Getting the file name entered by the user
cout << "Enter name of the file to encrypt :";
cin >> infile;
//calling the functions
readFile(infile, letters);
display(letters);

return 0;
}
void readFile(string infile,int letters[]) {
string line;
char ch, c;
// int letter=0,totChars=0,totAlpha=0;
//defines an input stream for the data file
ifstream dataIn;
//Opening the input file
dataIn.open(infile.c_str());
//checking whether the file name is valid or not
if (dataIn.fail()) {
cout << "'" << infile << "' File Not Found **";
exit(0);
} else {
//counting how many words in the file
while (!dataIn.eof()) {
  
getline(dataIn, line);

for (int i = 0; i < line.length(); i++) {
ch = line[i];
if (isalpha(ch)) {
c = toupper(ch);
letters[(c-65)]++;

}
  
}
}
dataIn.close();
}
}
void display(int letters[]) {
int min=letters[0];
int max=letters[0];
int minIndx=0,maxIndx=0;

cout << "Letter Frequencies in the file are " << endl;
cout << "\nLetter\t\tCount" << endl;
cout << "------\t\t-----" << endl;
for(int i=0;i<26;i++)
{
  
   if(letters[i]!=0)
   {
       if(min>letters[i])
       {
           min=letters[i];
           minIndx=i;
       }
       if(max<letters[i])
       {
           max=letters[i];
           maxIndx=i;
       }
      
   cout<<(char)(65+i)<<"\t\t"<<letters[i]<<endl;  
   }
  
}
  
  
cout<<"Letter "<<(char)(65+maxIndx)<<" is most frequently used."<<endl;
cout<<"Letter "<<(char)(65+minIndx)<<" is least frequently used."<<endl;
  
}