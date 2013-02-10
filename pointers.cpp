#include <iostream>
using namespace std;

void increment(int &a);
char* constructString (const char* input, const char* msg);
void appendString (const char* input, char **output, const char* msg);

/**
 * Passing by reference, C++ style
 */
void increment (int &a)
{
	// no need to derefence pointer; the compiler
	// takes care of this
	a = a + 1;
}

/**
 * Returns a new char pointer that is the result
 * of appending msg to input
 */
char* constructString (const char *input, const char *msg)
{
	char *output;
	appendString (input, &output, msg);
	return output;
}

/**
 * Appends msg to input, and stores the result
 * into the pointer output.
 * To modify pointers, we have to modify its own pointer.
 * Thus **output and not *output.
 */
void appendString (const char *input, char **output, const char *msg)
{
	*output = new char;
	int i = 0,
		j = 0;

	while ( input[i] )
	{
		(*output)[j++] = input[i++];
	}

	i = 0;
	while ( msg[i] )
	{
		(*output)[j++] = msg[i++];
	}
	
	(*output)[j] = '\0';
}

int main ()
{
	int a = 5;
	cout << "a = " << a << endl;
	
	// no need to pass "&a"; the compiler takes
	// care of this
	increment (a);
	
	cout << "a = " << a << endl; 
	
	const char *name = "Github";
	const char *append = " is awesome!";
	char *output;

	appendString (name, &output, append);

	cout << "name = " << name << endl;
	cout << "append = " << append << endl;
	cout << "output = " << output << endl;
	
	char *t = constructString (name, append);
	cout << "t = " << t << endl;

	return 0;
}
