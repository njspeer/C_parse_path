#include "stdio.h"
#include <string.h>
/*
  Toy example to try and figure out what I am doing wrong

  gcc -Wall main.c -o main
  gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
*/

/* get parent directory */
void dirname(char *dir, char *pth)
{
  int x0 = -1;
  for(int i = 0; (dir[i]=pth[i]); ++i)
  {
    if(dir[i] == '/')
    {
      x0 = i;
    }
  }
  dir[x0 + 1] = '\0';
}

/* get file name */
char *filename(char *pth)
{
  char *fpnt;
  while(*(++pth)!='\0')
  {
    if(*pth=='/')
    {
      fpnt = pth;
    }
  }
  return ++fpnt;
}

/* takes a file name, fname, and returns the base name: bname (and its legnth) */
int base(char *bname, char *fname)
{
  int xdot = 0;
  for(int i = 0; (bname[i] = fname[i]); ++i)
  {
    if(fname[i] == '.'){xdot = i;}
  }
  bname[xdot] = '\0';
  return xdot;
}

int main()
{
  
  /* path to file */
  // char* pth = "/home/BlaBlaBla/file2.0_123s.bin";
  char* pth = "/home/BlaBlaBla/file2.0_123s.bin";
  printf("path = %s\n", pth);


  /* get the parent directory of the file */
  char fdir[strlen(pth) + 1];       
  dirname(fdir, pth);               
  printf("dir name:: = %s\n", fdir);
  printf("strlen(fdir) = %d\n", (int)strlen(fdir));

  
  /* extract the file-name from pth (just use a pointer) */
  char *fname = filename(pth);
  printf("file name = %s\n", fname);

  /* extract the base-name from fname*/
  char fbase[strlen(fname)];
  base(fbase, fname);
  printf("base name = %s\n", fbase);


  /* finally, we check fdir again and discover that it's now blank!? */
  printf("dir name:: = %s\n", fdir );
  printf("strlen(fdir) = %d\n", (int)strlen(fdir));

  return 0;
}