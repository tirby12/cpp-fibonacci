#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <iostream>

using namespace std;

int fibpro(int t)//function for Fibonacci process
{
  if (t <= 0)//returns 0 for the first number
    return 0;
  else if (t == 1)//returns 1 for the second number
    return 1;
  else//starts recursive call of the function
    return fibpro(t - 1) + fibpro(t - 2);
}


int main()
{      
  int amt;//interger that counts the amount of numbers to be printed
  pid_t pcid;//process id

  printf("Enter the amount of number to be displayed: ");//outputs some user friendly text
  scanf ("%d", &amt);//accepts input from user
  pcid= fork();//creates child process
  if (pcid > 0)//if its not the parent process it starts the process
	{
	  for (int t = 0; t<amt; t++)//loop for how many umbers to be displayed
	    {
	      printf("%d ",  fibpro(t));//displays the output 
	    }
	  printf("\n");
	}

  else if (pcid == 0)//when its the parent process it waits
	wait();

  
  return 0;
}

