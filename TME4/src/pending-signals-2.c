#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

int main (int argc, char* argv []) {

  int i;
  sigset_t sig_set;
  struct sigaction action;  

  action.sa_handler = SIG_IGN;

  sigemptyset(&sig_set);
  sigaddset(&sig_set,SIGINT);
  sigaddset(&sig_set,SIGQUIT);
  sigprocmask(SIG_SETMASK, &sig_set, NULL);

  sigaction(SIGINT, &action, NULL);
  sigaction(SIGQUIT, &action, NULL);
  
  sleep(5);
  
  sigpending(&sig_set);

  for (i=1;i<NSIG;i++)
    if (sigismember(&sig_set,i))
      printf("\n Signal %d pendant \n",i);

  return EXIT_SUCCESS;
}
