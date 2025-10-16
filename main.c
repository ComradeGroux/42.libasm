#include "libasm.h"

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
	unsigned  numString = sizeof(strings) / sizeof(strings[0]);

	printf(BOLD "Testing ft_strlen\n" RESET);
	{
		for(unsigned int i = 0; i < numString; i++)
		{
			int expect = strlen(strings[i]);
			int result = ft_strlen(strings[i]);

			printf(expect == result ? GREEN "OK" RESET : RED "KO" RESET);
			printf("\t Expect: %d\t Result: %d\n", expect, result);
		}
	}

	printf(BOLD "\nTesting ft_strcmp\n" RESET);
	{

	}

	printf(BOLD "\nTesting ft_strcpy\n" RESET);
	{

	}

	printf(BOLD "\nTesting ft_strdup\n" RESET);
	{

	}

	printf(BOLD "\nTesting ft_write\n" RESET);
	{
		ft_write(0, "oh shit", strlen("oh s"));
	}

	printf(BOLD "\nTesting ft_read\n" RESET);
	{

	}

	return 0;
}
