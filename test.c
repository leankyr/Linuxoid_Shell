#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(int argc ,char  *argv[]) {

int i,j = 0 ;  
char input [ 512 ];

//printf("argc is: %d \n", argc    ) ;

for (i = 1; i < argc ; i++) {

//printf("argv [%d] = %s    \n "  , i , argv[i]  );

strcat(input , " ");
strcat( input  , argv[i]   );


} 

//printf(" the given command is:  %s   \n ", input );

        char *token;
        const char s[2]=";";



	char *commands[512];
        
        token=strtok(input ,s);
        while (token!=NULL){
        commands[j]=token;
  //     printf("\n commands[%d]=%s",j,commands[j]);
       // system(commands[j]);
        j++;    
        token=strtok(NULL,s);   
        }
        printf("\n");
// forking stuff
pid_t child_pid[j] ; 

for (i = 0 ; i < j ; i++) {
    pid_t pid = fork();
    child_pid[i] = pid; 
//printf( "fork returned: %d    \n ", (int) pid  );
       // j=0;
        char *args[10];
if (pid < 0) {
       perror("fork failed.");
       exit(1);
       }
     else if(pid == 0) {
  //  printf("I am the child with PID: %d  \n" , getpid()  );
       // Child now exec's
        j = 0 ;
        char *token;
        const char s[2]=" ";
      //  char *args[10];
        token=strtok(commands[i] ,s);
        while (token!=NULL){
        args[j]=token;
       // printf("\n args[%d]=%s",j,args[j]);
       // system(commands[j]);
        j++;
        token=strtok(NULL,s);
        printf("\n");
        }  
 //   sleep(rand() % 4  );    
    args[ j + 1] = NULL;
//  execvp (args[0], args   );
 //       srand( (int ) getpid()); 
 //   int sleep_time = rand() % 300;
  //  printf("Child with pid : %d will sleep for %d usecs \n " , getpid() , sleep_time   );
  //  sleep(5 ) ; 
if (  execvp (args[0], args   ) == -1 )  {
   if ( strcmp(args[0] , "quit" ) != 0    ) {
      printf( "command not found\n")   ;
        }
    } 
} 
else if ( pid > 0  ){
//printf("parent pid is %d :  \n ", getpid()   );
//printf("parent is waiting for child to finish\n" );
 
  }
}
//    wait(NULL);


for ( i = 0 ; i < j ; i++) {
 waitpid(child_pid[i] , NULL, 0   );
   }


return 0;
}
