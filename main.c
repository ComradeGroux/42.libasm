#include "libasm.h"

#define RESET "\033[0m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define BOLD "\033[1m"

#define BUFFER_SIZE 100

int main()
{
	char	*strings[] = {
		"1",
		"12345",
		"1234567890",
		"test",
		"",
		"\n",
		"oooooooooooooooooooooooooooooooooooooooooh ca c'est long"
	};
	unsigned int numString = sizeof(strings) / sizeof(strings[0]);

	printf(BOLD "Testing ft_strlen\n" RESET);
	{
		for(unsigned int i = 0; i < numString; i++)
		{
			int expect = strlen(strings[i]);
			int result = ft_strlen(strings[i]);

			printf(expect == result ? GREEN "OK" : RED "KO");
			printf(RESET "\t Expect: %d\t Result: %d\n", expect, result);
		}
	}

	printf(BOLD "\nTesting ft_strcmp\n" RESET);
	{
		char	*cmpStrings[] = {
			"1",
			"123456",
			"1234567890",
			"tesT",
			"",
			"\n",
			"ooooooooooooooooooooooooooooooooooooooh ca c'est long"
		};
		unsigned int numCmpString = sizeof(cmpStrings) / sizeof(cmpStrings[0]);
		(void)numCmpString;
		
		// for(unsigned int i = 0; i < numString && i < numCmpString; i++)
		// {
		// 	int expect = strcmp(strings[i], cmpStrings[i]);
		// 	int result = ft_strcmp(strings[i], cmpStrings[i]);

		// 	printf(expect == result ? GREEN "OK" : RED "KO");
		// 	printf(RESET "\t Expect: %d\t Result: %d\n", expect, result);
		// }
	}

	printf(BOLD "\nTesting ft_strcpy\n" RESET);
	{
		printf("Testing return value\n");
		for(unsigned int i = 0; i < numString; i++)
		{
			char	dummy_dest[BUFFER_SIZE];

			void *ref_ptr = strcpy(dummy_dest, strings[i]);
			void *test_ptr = ft_strcpy(dummy_dest, strings[i]);

			printf(ref_ptr == test_ptr ? GREEN "OK" : RED "KO");
			printf(RESET "\tExpect: %p\tResult: %p\n", ref_ptr, test_ptr);
		}

		printf("\nTesting destination string\n");
		for(unsigned int i = 0; i < numString; i++)
		{
			char	ref_dest[BUFFER_SIZE];
			char	test_dest[BUFFER_SIZE];

			strcpy(ref_dest, strings[i]);
			strcpy(test_dest, strings[i]);

			printf(strcmp(ref_dest, test_dest) == 0 ? GREEN "OK" : RED "KO");
			printf(RESET "\tExpect: %s\tResult: %s\n", ref_dest, test_dest);
		}
	}

	printf(BOLD "\nTesting ft_strdup\n" RESET);
	{

	}

	printf(BOLD "\nTesting ft_write\n" RESET);
	{
		
	}

	printf(BOLD "\nTesting ft_read\n" RESET);
	{

	}

	return 0;
}
