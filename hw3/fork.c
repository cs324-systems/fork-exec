#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[]) {
	int pid;
	FILE *fptr;
	FILE *strmChild;
	FILE *strmParent;
	int pipefd[2];

	printf("Starting program; process has pid %d\n", getpid());

	fptr = fopen("fork-output.txt", "w");

	if (fptr == NULL) {
		fprintf(stderr, "Could not open file");
		exit(1);
	}
	fprintf(fptr, "%s", "BEFORE FORK\n");

	pipe(pipefd);

	if ((pid = fork()) < 0) {
		fprintf(stderr, "Could not fork()");
		exit(1);
	}

	/* BEGIN SECTION A */
	fprintf(fptr, "%s", "SECTION A\n");

	printf("Section A;  pid %d\n", getpid());
	//sleep(30);

	/* END SECTION A */
	if (pid == 0) {
		/* BEGIN SECTION B */
		close(pipefd[0]);
		strmChild = fdopen(pipefd[1], "w");
		fputs("hello from Section B\n", strmChild);
		fprintf(fptr, "%s", "SECTION B\n");
		printf("Section B\n");
		//sleep(30);
		//sleep(30);
		printf("Section B done sleeping\n");

		/* EXEC.C */
		char *newenviron[] = { NULL };

		printf("Program \"%s\" has pid %d. Sleeping.\n", argv[0], getpid());
		//sleep(30);

		if (argc <= 1) {
			printf("No program to exec.  Exiting...\n");
			exit(0);
		}

		printf("Running exec of \"%s\"\n", argv[1]);
		dup2(fileno(fptr), fileno(strmChild));
		execve(argv[1], &argv[1], newenviron);
		printf("End of program \"%s\".\n", argv[0]);

		exit(0);

		/* END SECTION B */
	} else {
		/* BEGIN SECTION C */
		//wait(NULL);

		fprintf(fptr, "%s", "SECTION C\n");
		char str[60];
		close(pipefd[1]);
		strmParent = fdopen(pipefd[0], "r");
		fgets(str, 60, strmParent);
		puts(str);
		printf("Section C\n");
		wait(NULL);
		//sleep(30);
		//sleep(30);
		printf("Section C done sleeping\n");

		exit(0);

		/* END SECTION C */
	}
	/* BEGIN SECTION D */
	fprintf(fptr, "%s", "SECTION D\n");
	printf("Section D\n");
	//sleep(30);

	/* END SECTION D */
	fclose(fptr);
}
