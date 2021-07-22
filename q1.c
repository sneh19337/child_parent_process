/*Name-Sneh Suman
Rollno-2019337*/
//Question 1 Quiz 2 OS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
#include <sys/types.h>
#include<ctype.h>

int main(void)
{
  char    string[500] ;
        char str[500]="";
        int     fd[2],fo[2];
        pid_t   childpid;
        
        

        pipe(fd);
        pipe(fo);
        
        if((childpid = fork()) == -1)
        {
                perror("fork");
                exit(1);
        }

        if(childpid == 0)
        {
               
                close(fd[1]);//fd[1] becuase it will recieve signal initially
                close(fo[0]);//fo[0] becuase it will send signal 
                  //reading
                 
                  while(read(fd[0],string, sizeof(string))>0)
                 
                 {
                  //changing to uppercase
                  for (int i = 0; string[i]!='\0'; i++) 
                  {
      if(string[i] >= 'a' && string[i] <= 'z') {
         string[i] = string[i] - 32;
        
      }
                    }
   for (int i = 0; string[i]!='\0'; i++) {
    str[i]=string[i];
    
}
}
   }//child process ends        
                //parent process
                fgets(string,500,stdin); //reads string
                
                printf("%s",str);//printing the modified string
                //printf("%s",string);

                write(fd[1], string, (strlen(string)+1));
                
                
                
                exit(0);
        
                close(fd[0]);//closing fd[0] as it sends the signal initially
                close(fo[1]);//closing fo[1] as it receives the signal
        return(0);
     
}