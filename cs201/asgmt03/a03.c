#include <stdlib.h>
#include <stdio.h>
#include <string.h>         // for strlen();
#include <unistd.h>         // for fork()
#include <sys/types.h>      // for pid_t
#include <sys/wait.h>       // for waitpid()



int main(int argc, char *argv[])
{
  int     comm[2];
  int     status;
  pid_t   cpid;

  printf("CS201 - Assignment 3 - Ladinu Chandrasinghe\n");

    // Set up a pipe
  if ( pipe(comm) )
  {
    printf("[!] pipe error\n");
    return -1;
  }

    // Fork into parent and child
  cpid = fork();

  if (cpid < 0)
  {
    printf("[!] fork error\n");
    return -1;
  }

    // Code for the child to run
  if (cpid == 0)
  {
    close(comm[1]);  // Child does not talk to the parent

      // Read from pipe
    int  charCount = 0;
    char tmp;

    while (read(comm[0], &tmp, 1) != 0)
      charCount++;

    printf("child: counted %d characters\n", charCount);

    close(comm[0]);
    return 0;
  }

    // Code for the parent to run
  else
  {
    close(comm[0]);  // Parent does not listen to child
    
    if (argc <= 1)
      close(comm[1]);   // Child will see EOF

    else
    {
      int i;
      int n;

        // Write arguments from command line into the pipe
      for (i = 1; i < argc; i++)
      {
        int argvLength = strlen(argv[i]);

        for (n = 0; n < argvLength; n++)
        {
          write(comm[1], &argv[i][n], 1);
        }
      }
      close(comm[1]); // Child will see EOF
    }

    waitpid(cpid, &status, 0); // Reap the child

    return 0;
  }
}
