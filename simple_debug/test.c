#include "simple_debugs.h"

int	main()
{
	//Test number and string
	int		testnumber = 42;
	char	*teststring;

	//OBVIOUS memory leak since no free and 42 is larger than the string.
	teststring = malloc(42 * sizeof(char));
	strcpy(teststring, "This is a test.");

	//Debugs at work
	debug_number(testnumber, "testnumber");
	debug_str(teststring, "teststring");
	//This debug tells you which part is leaking in ascending order.
	check_leaks();
	free(teststring);
	return (0);
}
