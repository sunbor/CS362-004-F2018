#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    // TODO: rewrite this function
    // return random character
    char c;
    //random number from 32 to 126, which covers all ascii characters 
    //except control characters
    c = rand() % 95 + 32;
    return c;
}

char *inputString()
{
    // TODO: rewrite this function
    // make array of random size between 1 and 10
    // changed to just make array of size 6
    int size;
    //size = rand() % 10 + 1;
    size = 6;
    //allocate memory
    char *s;
    s = (char*) malloc(size * sizeof(char));
    //fill out array
    int i;
    for(i=0; i<size; i++){
	    //random number for all ascii graphic characters
	    s[i] = rand() % 95 + 32;
	    //make last character null character
	    if(i== size - 1)
		    s[i] = 0;
    }
    //have a small chance to just return the reset string
    i = rand() % 10000;
    if(i==0){
	    s[0] = 'r';
	    s[1] = 'e';
	    s[2] = 's';
	    s[3] = 'e';
	    s[4] = 't';
	    s[5] = '\0';
	    printf("fixed test returning s = reset\n");
    }

    return s;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      //delete array
      free(s);
      exit(200);
    }
    //delete array
    free(s);
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
