#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "fun.h"

// SYSCALL.
// fork.... - Fork a process (Сделать копию текущего/выполняющегося процесса)
// waitpid - Остановить выполняющийся процесс до уничтожения дочернеого процесса
// exit - Уничтожить выполняющийся процесс
// _exit - Уничтожить себя и не сбрасывать буфер stdio.
// 


// GLOBAL VARIABLE Глобальная переменная

size_t n = 11;

void run_fact() {
  size_t res = fact(n);
  printf("(SUBPROCESS) Fact of %ld is %ld.\n", n, res);  
}


int main(){
  // cout << "Hello, World" << endl;
  printf("Hello, World!\n");
  size_t cpid;
  
  if ((cpid = fork()) == 0) { // Child process
    run_fact();
  } else { // fork()!=0 == child_pid
    // Main process
    size_t res = fact(n);
    printf("Fact of %ld is %ld.\n", n, res);
  }
  if (cpid!=0) {
    int rc;
    waitpid(cpid, &rc, 0);
    printf("A Child process killed.\n");
  }
  return 0;
}

// #include <unistd.h>
// #include <sys/wait.h>
