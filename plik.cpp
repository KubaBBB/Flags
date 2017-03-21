#include"plik.h"
#include<iostream>


// znalezc blad islength() i copystring() bo w pliku comout.txt nie kopiuje
void StrType :: MakeEmpty()
{
letters[0]='\0';

}

void StrType :: GetString(bool skip, InType charsAllowed)
{				//dokonczyc
switch(charsAllowed)
	{
	case ALPHA_NUM:
		GetAlphaNum(skip,letters,std :: cin);
		break;
	case ALPHA:
		GetAlpha(skip,letters, std :: cin);
		break;
	case NON_WHITE:
		GetNonWhite(skip,letters,std :: cin);
		break;
	case NOT_NEW:
		GetTilNew(skip,letters,std :: cin);
	}
return;
}

void StrType :: GetStringFile(bool skip, InType charsAllowed,std::ifstream& inFile)
{
switch(charsAllowed)
	{
	case ALPHA_NUM:
		GetAlphaNum(skip,letters,inFile);
		break;
	case ALPHA:
		GetAlpha(skip,letters,inFile);
		break;
	case NON_WHITE:
		GetNonWhite(skip,letters,inFile);
		break;
	case NOT_NEW:
		GetTilNew(skip,letters,inFile);
	}
return;
}

void StrType :: PrintToScreen(bool newLine)
{
if(newLine)
	cout << endl;
cout << letters;

}

void StrType :: PrintToFile(bool newLine,std::ofstream& outFile)
{
if(newLine)
	outFile << endl;
outFile << letters;

}

void StrType::CopyString(StrType& newString)
// Post: letters has been copied into newString.letters.
{
std::strcpy(newString.letters, letters);
}
 
int StrType::LengthIs()
// Post: Function value = length of letters string
{
return std::strlen(letters);
}

void GetAlphaNum( bool skip, char letters[] , std :: istream & inFile)
{
using namespace std;
char letter;
int count = 0 ;
if(skip)
	{
	inFile.get(letter);
	while(!isalnum(letter) && inFile)
		inFile.get(letter);

	}
else
	inFile.get(letter);
if(!inFile || !isalnum(letter))
	letters[0]='\0';
else
	{
	do
		{
		letters[count] = letter;
		count++;
		inFile.get(letter);
		
		}
	while(isalnum(letter) && inFile && (count <  MAX_CHARS));
	letters[count] = '\0';
	if( count == MAX_CHARS && isalnum(letter))
		do
			{
			inFile.get(letter);
			}
		while(isalnum(letter) && inFile);	
	}

}


void GetTilNew(bool skip, char letters[] , std :: istream & inFile)
{
using namespace std;
char letter;
int count = 0;
if (skip)
	{// Skip newlines.
	inFile.get(letter);
	while ((letter == '\n') &&inFile)
  		inFile.get(letter);
	}
else
	inFile.get(letter);
if (!inFile || letter == '\n')
	letters[0] = '\0';
else
{// Read and collect characters.
 	do
  	{
    		letters[count] = letter;
    		count++;
    		inFile.get(letter);
  	} while ((letter != '\n') && inFile && (count < MAX_CHARS));
 	letters[count] = '\0';
	// Skip extra characters if necessary.
 	if (count == MAX_CHARS && letter != '\n')
  	do
    	{
      		inFile.get(letter);
    	} while ((letter != '\n') && inFile);
  	}
}
 
void GetAlpha(bool skip , char letters[] , std :: istream & inFile)
{
using namespace std;
char letter;
int count = 0 ; 
if(skip)
	{//skip non alpha
	inFile.get(letter);
	while( !isalpha(letter) && inFile)
		inFile.get(letter);
	}
else
	inFile.get(letter);
if(!inFile || !isalpha(letter))
	letters[0]='\0';
else
	{
	do
		{
		letters[count] = letter;
		count++;
		inFile.get(letter);
		
		}
	while(isalpha(letter) && inFile && (count <  MAX_CHARS));
	letters[count] = '\0';
	if( count == MAX_CHARS && isalpha(letter))
		do
			{
			inFile.get(letter);
			}
		while(isalpha(letter) && inFile);	
	}

}

void GetNonWhite(bool skip, char letters[] , std :: istream & inFile)
{
using namespace std;
char letter;
int count = 0;
if (skip)
	{// skip NonWhite.
	inFile.get(letter);
	while (isspace(letter) && inFile)
  		inFile.get(letter);
	}
else
	inFile.get(letter);
if (!inFile || letter == '\n')
	letters[0] = '\0';
else
{// .
 	do
  	{
    		letters[count] = letter;
    		count++;
    		inFile.get(letter);
  	} while (isspace(letter) && inFile && (count < MAX_CHARS));
 	letters[count] = '\0';
	// Skip extra characters if necessary.
 	if (count == MAX_CHARS && letter != '\n')
  	do
    	{
      		inFile.get(letter);
    	} while (isspace(letter) && inFile);
   }


}

