// A C program to demonstrate Orphan Process.
// Parent process finishes execution while the
// child process is running. The child process
// becomes orphan.
#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	// Create a child process	
	int pid = fork();

	if (pid > 0)
		printf("in parent process");

	// Note that pid is 0 in child process
	// and negative if fork() fails
	else if (pid == 0)
	{
		sleep(30);
		printf("in child process");
	}

	return 0;
}



// #include<stdio.h>
// #include<unistd.h>
// #include<sys/types.h>
// int main()
// {
//      pid_t p;
//      p=fork();
//      if(p==0) //child
//      {
//          printf("I am child having PID %d\n",getpid());
//          printf("My parent PID is %d\n",getppid());
//      }
//      else //parent
//      {
//          printf("I am parent having PID %d\n",getpid());
//          printf("My child PID is %d\n",p);
//      }
    
//  }