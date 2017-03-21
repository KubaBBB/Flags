#include<iostream>
#include<fstream>
#include"fun.h"

void GetAlphaNum( bool skip, char letters[] , std :: ifstream & inFile)
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


void GetTilNew(bool skip, char letters[] , std :: ifstream & inFile)
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
 
