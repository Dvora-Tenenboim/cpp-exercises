#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<assert.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/types.h>
#include <errno.h>
int s;
struct sigaction new_action,chld_signal;

void chld_signal_handler( int signum )                       
{
	wait(&s);
}
void cmdpipe(int pipe_index,char **arglist)
{
	int pipe_fd[2] ;
	pid_t pid1,pid2;
	if (pipe(pipe_fd) == -1)
	{
		perror ("cannot open pipe") ;
		exit(EXIT_FAILURE) ;
	}
	pid1=fork();
	if (pid1 < 0)
	{
		perror ("error in fork") ;
		exit(EXIT_FAILURE) ;
	}
	
	if (pid1 == 0)
	{
		new_action.sa_handler = SIG_DFL;
  		if( 0 != sigaction(SIGINT, &new_action, NULL) )
  		{
    		printf("Signal handle registration failed. %s\n",strerror(errno));
    		exit(EXIT_FAILURE);
  		}
		close(pipe_fd[0]) ;
		dup2(pipe_fd[1],STDOUT_FILENO);
		arglist[pipe_index]=NULL;
		execvp(arglist[0],arglist);
	}
	else
 	{	
 		pid2 = fork();
		if (pid2 < 0)
		{
			perror ("error in fork") ;
			exit(EXIT_FAILURE) ;
		}
		close(pipe_fd[1]);
		if (pid2 == 0)
 		{
			if( 0 != sigaction(SIGINT, &new_action, NULL) )
  			{
    			printf("Signal handle registration failed. %s\n",strerror(errno));
    			exit(EXIT_FAILURE);
  			}
 			dup2(pipe_fd[0],STDIN_FILENO);
 			execvp(arglist[pipe_index+1],arglist+pipe_index+1);
 		}
 		waitpid(pid2,&s,0);
		waitpid(pid1,&s,0);	
 	} 
}


int prepare(void)
{
	new_action.sa_handler = SIG_IGN;
  	if( 0 != sigaction(SIGINT, &new_action, NULL) )
  	{
    		printf("Signal handle registration failed. %s\n",strerror(errno));
    		return -1;
  	}
  	return 0;
}
int process_arglist(int count, char **arglist)
{
	chld_signal.sa_handler=chld_signal_handler;
	chld_signal.sa_flags = SA_RESTART;
	if( 0 != sigaction(SIGCHLD, &chld_signal, NULL) )
  	{
    		printf("Child signal handle registration failed. %s\n",strerror(errno));
    		exit(EXIT_FAILURE);
  	}
	int i,flag2=0;
	if(*arglist[count-1]=='&')
	{
		flag2=1;
	}
	if(!flag2)
	{

		for(i=0;i<count;i++)
		{
			if(*arglist[i]=='|')
			{
				break;
				execvp(arglist[0],arglist);
			}
		}
		if(i!=count)
		{
			cmdpipe(i,arglist);	
		}
		else
		{
			pid_t status=fork();
			if(status==0)
			{
				new_action.sa_handler = SIG_DFL;
  				if( 0 != sigaction(SIGINT, &new_action, NULL) )
  				{
    				printf("Signal handle registration failed. %s\n",strerror(errno));
    				exit(EXIT_FAILURE);
  				}
				execvp(arglist[0],arglist);
			}
			waitpid(status,&s,0);
		}
	}
	else
	{
		pid_t state=fork();
		if (state < 0)
		{
			perror ("error in fork") ;
			exit(EXIT_FAILURE) ;
		}
		if(state==0)
		{
			arglist[count-1]=NULL;
			execvp(arglist[0],arglist);
		}
	}
	return 1;
}




int finalize(void)
{
	return 0;
}
