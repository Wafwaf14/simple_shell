<h1>Simple Shell Project for ALX</h1>
<h2>Requirements</h2>
<h3>General</h3>
Allowed editors: vi, vim, emacs
<p>All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89<br>
All your files should end with a new line<br>
A README.md file, at the root of the folder of the project is mandatory<br>
Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl<br>
Your shell should not have any memory leaks<br>
No more than 5 functions per file<br>
All your header files should be include guarded<br>
Use system calls only when you need to (why?)<br>
Write a README with the description of your project<br>
You should have an AUTHORS file at the root of your repository, listing all individuals having contributed content to the repository. </p>

<h2>More Info</h2>
<h2>Output</h2>
<p>Unless specified otherwise, your program must have the exact same output as sh (/bin/sh) as well as the exact same error output.
The only difference is when you print an error, the name of the program must be equivalent to your argv[0] (See below)
Example of error with sh:</p>

```bash
$ echo "qwerty" | /bin/sh
/bin/sh: 1: qwerty: not found
$ echo "qwerty" | /bin/../bin/sh
/bin/../bin/sh: 1: qwerty: not found
$
```
<p>Same error with your program hsh:</p>

```bash
$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
$ echo "qwerty" | ./././hsh
./././hsh: 1: qwerty: not found
$
```

<h3>List of allowed functions and system calls</h3>

```
access (man 2 access)
chdir (man 2 chdir)
close (man 2 close)
closedir (man 3 closedir)
execve (man 2 execve)
exit (man 3 exit)
_exit (man 2 _exit)
fflush (man 3 fflush)
fork (man 2 fork)
free (man 3 free)
getcwd (man 3 getcwd)
getline (man 3 getline)
getpid (man 2 getpid)
isatty (man 3 isatty)
kill (man 2 kill)
malloc (man 3 malloc)
open (man 2 open)
opendir (man 3 opendir)
perror (man 3 perror)
read (man 2 read)
readdir (man 3 readdir)
signal (man 2 signal)
stat (__xstat) (man 2 stat)
lstat (__lxstat) (man 2 lstat)
fstat (__fxstat) (man 2 fstat)
strtok (man 3 strtok)
wait (man 2 wait)
waitpid (man 2 waitpid)
wait3 (man 2 wait3)
wait4 (man 2 wait4)
write (man 2 write)
```

<h3>Compilation</h3>
<p>Your shell will be compiled this way:</p>

`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

<h3>Testing</h3>
<p>Your shell should work like this in interactive mode:</p>

```bash
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
<p>But also in non-interactive mode:</p>

``` bash
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```
