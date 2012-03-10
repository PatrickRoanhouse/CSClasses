//
//  main.c
//  fork
//
//  Created by Ladinu Chandrasinghe on 3/8/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>         // for fork()
#include <sys/types.h>      // for pid_t
#include <sys/wait.h>       // for waitpid()

int main (int argc, const char * argv[])
{
    pid_t pid;
    pid_t ppid;
    pid_t cpid; // Child pid
    
    int   status;
    int   childRetVal = 7;
    
    pid  = getpid();
    ppid = getppid(); 
    
    printf("Ppid: %d\n", ppid);
    printf("Pid : %d\n", pid);
    
    
    cpid = fork();
    
    if (cpid < 0)
    {
        printf("[!] fork error...\n");
        return -1;
    }
        // The code the child is able to run
    else if (cpid == 0)
    {
        printf("Hello world from child\n");
        printf("Simulating a long computation...\n");
        
        sleep(1);
        
        return childRetVal;
    }
    
        // Parent will run this code (because pid != 0)
    else
    {
        printf("Parent is wating...\n");
        sleep(3);
        
        if (waitpid(cpid, &status, WNOHANG) > 0)      // If the process has changed state, waitpid will return the pid else 0
        {
            printf("parent reaps child status 0x%08X\n", status);
            
            if (WIFEXITED(status))
                printf("Child exited normally with %d\n", WEXITSTATUS(status));
        }
        
        return 0;
    }
}

