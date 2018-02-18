#include <iostream>  // cin, cout
#include <fstream> // ifstream, ofstream
#include <bitset> // bitset<8>
#include <sstream> // istringstream
using namespace std;

bool readFile(const char *filename);

int main() 
{   
	char filename[] = { "crypto.txt" }; // initializing name of file that we will read from
	
	readFile(filename); // calling function to read from file we named
	return 0;
}

	// function to read txt-file
bool readFile(const char *filename)
{
	const int CHAR_LENGTH = 8; // text length temp char array
	ifstream infile;  // declare file to read from
	infile.open(filename); // open .txt file
	char ch; // declare char as we will read the txt-file char by char
	int message_size = 0;
	char* message = new char[message_size]; // pointer to char array with dynamically allocated memory initially 0
	
	if(!infile.is_open()) 
	{
		return false; // exit function if file can not be opened
	}
	
	while(!infile.eof()) // until we reach the end of line
	{
		char binary[CHAR_LENGTH] = {	"" }; // initialize a temp char array 
		if(infile.read(binary, CHAR_LENGTH)) // if we can read in another 8 chars to array
		{
			istringstream in(binary); // converting cstring to string buffer
			bitset<8> bs; // declaring a bitset of 8 bits
			message_size++; // increase memory space for message array
		
			while(in >> bs) // converting string to bits
			{
				message[message_size - 1] = char(bs.to_ulong()); // converting bitset to its char representation and storing it current message pointer space
			}
		}
	}
	for(int i = 0; i < message_size; i++)
	{
		cout << message[i]; // when we have translated the entire txt-file, message is printed in full
	}
	
	infile.close();
	
	return true;
}
