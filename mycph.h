/* Frank Hulmes
  Project 1b
  CISC361
                                    mycp Header

  checkOverwrite(char *fd) - asks the user if they wish to overwrite the files
    parameters:
      char *fd - string containing the filename
    returns:
      1 if it can overwrite, 0 if Not
*/

int checkOverwrite(char *fd);

/*
  readAndWrite(char *readfd, char *writefd) - reads from filename readfd and writes to
  filename writefd, either overwriting the current file or creating a new one
    parameters:
      char *readfd - string containing the filename to be read
      char *writefd - string containing the filename to be written to
    returns:
      1 if successful, 0 if Not
*/

int readAndWrite(char *readfd, char *writefd);
