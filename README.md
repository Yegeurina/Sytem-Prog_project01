# Sytem-Prog_project01

## P.c
프로그램 P는 표준입력으로 부터 입력을 받아 단순히 표준 출력을 출력하는 프로그램 이다. 
EOF를 만날때 까지 입력을 받고 그 사항을 바로 출력하는 형식이며 입출력 중 에러가 발생했을 시 err_sys를 호출하여 stderr로 출력을 하도록 한다. 

```c
void err_sys(const char* x)
{
	perror(x);
	exit(1);
}
```
err_sys는 다음과 같다.


## prog.c

프로그램 prog는 표준입출력으로 파일 A와 B로 redirection하는 프로그램이다.

prog.c를 parent로 수행하고 dup2()를 사용하여 표준 입출력을 redirection하였다. 이를 child인 P에 fork()하여 전달하였다. child는 수행파일 P를 exec(P)gkrh 이후 open file descriptor을 유지한다.
