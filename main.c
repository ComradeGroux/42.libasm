#include "libasm.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define RESET "\033[0m"
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
		"\t",
		"ooooooooooooooooooooooooooooooooooooh ca c'est long"
	};
	unsigned int numString = sizeof(strings) / sizeof(strings[0]);

	printf(BOLD "⚪️ Testing ft_strlen ⚪️\n" RESET);
	{
		for(unsigned int i = 0; i < numString; i++)
		{
			int expect = strlen(strings[i]);
			int result = ft_strlen(strings[i]);

			printf(expect == result ? "✅" : "❌");
			printf("\t Expect: %d\tResult: %d\n", expect, result);
		}
	}

	printf(BOLD "\n\n⚪️ Testing ft_strcmp ⚪️\n" RESET);
	{
		char	*cmpStrings[] = {
			"1",
			"123456",
			"1234567890",
			"tesT",
			"",
			"\t",
			"ooooooooooooooooooooooooooooooooooooooh ca c'est long"
		};
		unsigned int numCmpString = sizeof(cmpStrings) / sizeof(cmpStrings[0]);
		
		for(unsigned int i = 0; i < numString && i < numCmpString; i++)
		{
			int expect = strcmp(strings[i], cmpStrings[i]);
			int result = ft_strcmp(strings[i], cmpStrings[i]);

			printf(expect == result ? "✅" : "❌");
			printf("\t Expect: %d\tResult: %d\n", expect, result);
		}
	}

	printf(BOLD "\n\n⚪️ Testing ft_strcpy ⚪️\n" RESET);
	{
		printf("◽️ Testing return value ◽️\n");
		for(unsigned int i = 0; i < numString; i++)
		{
			char	dummy_dest[BUFFER_SIZE];

			void *ref_ptr = strcpy(dummy_dest, strings[i]);
			void *test_ptr = ft_strcpy(dummy_dest, strings[i]);

			printf(ref_ptr == test_ptr ? "✅" : "❌");
			printf("\tExpect: %p\tResult: %p\n", ref_ptr, test_ptr);
		}

		printf("\n◽️ Testing destination string ◽️\n");
		for(unsigned int i = 0; i < numString; i++)
		{
			char	ref_dest[BUFFER_SIZE];
			char	test_dest[BUFFER_SIZE];

			strcpy(ref_dest, strings[i]);
			strcpy(test_dest, strings[i]);

			printf(strcmp(ref_dest, test_dest) == 0 ? "✅" : "❌");
			printf("\tExpect: %s\tResult: %s\n", ref_dest, test_dest);
		}
	}

	printf(BOLD "\n\n⚪️ Testing ft_strdup ⚪️\n" RESET);
	{
		for(unsigned int i = 0; i < numString; i++)
		{
			char *refString = strdup(strings[i]);
			char *testString = strdup(strings[i]);

			printf(strcmp(refString, testString) == 0 ? "✅" : "❌");
			printf("\tExpect: %s\tResult: %s\n", refString, testString);
			
			free(refString);
			free(testString);
		}
	}

	printf(BOLD "\n\n⚪️ Testing ft_write ⚪️\n" RESET);
	{
		char *msg = "TESSSSSSST\n";
		ssize_t		refReturn;
		ssize_t		testReturn;
		int			refErrno;
		int			testErrno;

		printf("◽️ Writing to STDOUT ◽️\n");
		refReturn = write(1, msg, strlen(msg));
		refErrno = errno;
		testReturn = ft_write(1, msg, strlen(msg));
		testErrno = errno;
		printf(refReturn == testReturn && refErrno == testErrno ? "✅" : "❌");
		printf("\tExpect: %zd, errno: %d\tResult: %zd, errno: %d\n", refReturn, refErrno, testReturn, testErrno);

		printf("\n◽️ Writing to a file ◽️\n");
		int fd = open("test_file.txt", O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (fd < 0)
		{
			perror("open");
			return (1);
		}
		refReturn = write(fd, msg, strlen(msg));
		refErrno = errno;
		testReturn = ft_write(fd, msg, strlen(msg));
		testErrno = errno;
		printf(refReturn == testReturn && refErrno == testErrno ? "✅" : "❌");
		printf("\tExpect: %zd, errno: %d\tResult: %zd, errno: %d\n", refReturn, refErrno, testReturn, testErrno);
		close(fd);

		printf("\n◽️ Writing to invalid FD (-1) ◽️\n");
		refReturn = write(-1, msg, strlen(msg));
		refErrno = errno;
		testReturn = ft_write(-1, msg, strlen(msg));
		testErrno = errno;
		printf(refReturn == testReturn && refErrno == testErrno ? "✅" : "❌");
		printf("\tExpect: %zd, errno: %d\tResult: %zd, errno: %d\n", refReturn, refErrno, testReturn, testErrno);
	}

	printf(BOLD "\n\n⚪️ Testing ft_read ⚪️\n" RESET);
	{
		char		buf_std[BUFFER_SIZE];
		char		buf_ft[BUFFER_SIZE];
		ssize_t		refReturn;
		ssize_t		testReturn;
		int			refErrno;
		int			testErrno;

		int fd = open("test_file.txt", O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (fd < 0)
		{
			perror("open");
			return (1);
		}
		write(fd, "TEEEEEEEEEEEEEST\n", 18);
		lseek(fd, 0, SEEK_SET);

		memset(buf_std, 0, BUFFER_SIZE);
		refReturn = read(fd, buf_std, BUFFER_SIZE - 1);
		refErrno = errno;

		lseek(fd, 0, SEEK_SET);
		memset(buf_ft, 0, BUFFER_SIZE);
		testReturn = ft_read(fd, buf_ft, BUFFER_SIZE - 1);
		testErrno = errno;


		printf("◽️ Reading from file ◽️\n");
		printf(refReturn == testReturn && refErrno == testErrno ? "✅" : "❌");
		printf("\tExpect: %zd, errno: %d\tResult: %zd, errno: %d\n", refReturn, refErrno, testReturn, testErrno);


		printf("\n◽️ Comparing buffers ◽️\n");
		printf(refReturn == testReturn && memcmp(buf_std, buf_ft, refReturn) == 0 ? "✅" : "❌");
		printf("\tExpect: %s\tResult: %s\n", buf_std, buf_ft);
		close(fd);


		printf("\n◽️ Reading from invalid FD (-1) ◽️\n");
		refReturn = read(-1, buf_std, 10);
		refErrno = errno;
		testReturn = ft_read(-1, buf_ft, 10);
		testErrno = errno;
		printf(refReturn == testReturn && refErrno == testErrno ? "✅" : "❌");
		printf("\tExpect: %zd, errno: %d\tResult: %zd, errno: %d\n", refReturn, refErrno, testReturn, testErrno);


		printf("\n◽️ Reading from pipe() ◽️\n");
		int pipefd[2];
		if (pipe(pipefd) == -1)
		{
			perror("pipe");
			return (1);
		}
		write(pipefd[1], "pipe content\n", 13);
		close(pipefd[1]);
		memset(buf_std, 0, BUFFER_SIZE);
		refReturn = read(pipefd[0], buf_std, BUFFER_SIZE);
		refErrno = errno;
		close(pipefd[0]);

		pipe(pipefd);
		write(pipefd[1], "pipe content\n", 13);
		close(pipefd[1]);
		memset(buf_ft, 0, BUFFER_SIZE);
		testReturn = ft_read(pipefd[0], buf_ft, BUFFER_SIZE);
		testErrno = errno;
		close(pipefd[0]);
		printf(refReturn == testReturn && refErrno == testErrno ? "✅" : "❌");
		printf("\tExpect: %zd, errno: %d\tResult: %zd, errno: %d\n", refReturn, refErrno, testReturn, testErrno);


		printf("\n◽️ Comparing buffers (pipe) ◽️\n");
		printf(refReturn == testReturn && memcmp(buf_std, buf_ft, refReturn) == 0 ? "✅" : "❌");
		printf("\tExpect: %s\tResult: %s\n", buf_std, buf_ft);
	}

	return 0;
}
