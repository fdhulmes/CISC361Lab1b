#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "mycph.h"
#define MAX_SIZE 128

extern int errno;

int main(int argc, char *argv[]){
  if(argc != 3){
    printf("Insufficient arguments. Exiting cp ...");
    return 0;
  }
  int accessRead = access(argv[1], F_OK);
  int accessWrite = access(argv[2], F_OK);
  if((accessRead == 0) && (accessWrite == 0)){
    // Both files exist, ask if overwrite, then read and write
    if(checkOverwrite(argv[2])){
      readAndWrite(argv[1], argv[2]);
      return 0;
    }
    else{
      printf("Not overwriting. Exiting cp ...");
      return 0;
    }
  }
  else if(accessRead == 0){
    // To Do: Read the file, create and write to new file
  }
  else{
    printf("Read file does not exist. Exiting cp ...");
    return 0;
  }

}

int checkOverwrite(char *fd){
  char *overwrite = (char*)malloc(sizeof(char));
  printf("Do you wish to overwrite the file %s ? (y/n)", fd);
  scanf("%s", overwrite);
  if(strcmp(overwrite,"y") == 0){
    free(overwrite);
    return 1;
  }
  else{
    free(overwrite);
    return 0;
  }
}

int readAndWrite(char *readfd, char *writefd){
  // Opens, reads, and writes to the file
  int openRead, openWrite, readIn, writeIn;
  char *buffer = (char *)malloc(sizeof(char) * MAX_SIZE);
  openRead = open(readfd, O_RDONLY);
  if(openRead < 0){
    perror("ERROR: ");
    return 0;
  }
  openWrite = open(writefd, O_WRONLY);
  if(openWrite < 0){
    perror("ERROR: ");
    return 0;
  }
  readIn = read(openRead, buffer, MAX_SIZE);
  if(read < 0){
    perror("ERROR: ");
    return 0;
  }
  else{
    writeIn = write(openWrite, buffer, MAX_SIZE);
    if(writeIn < 0){
      perror("ERROR: ");
      return 0;
    }
    else{
      while(read(openRead, buffer, MAX_SIZE) > 0){
        writeIn = write(openWrite, buffer, MAX_SIZE);
      }
    }
  }
  printf("Finished copying");
  free(buffer);
  close(readIn);
  close(writeIn);
  return 1;
}
