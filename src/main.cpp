/* MIT License
Copyright (c) 2020 Emir Ensar All Rights Reserved.
Distributed under the terms of the MIT License.
*/

// Huge thanks for ferhatgec(https://github.com/ferhatgec)

// include part from the ferhatgec/scrift
#include <ctype.h>
#include <dirent.h>
#include <unistd.h>
#include <time.h>
#include <iostream>
#include <cstdio>
#include <string.h>
#include <stdio.h>
#include <locale.h>
#include <ctype.h>
#include <thread>
#include <string>
#include <ctime>
#include "../include/ExecutePlusPlus.hpp"


using namespace std;
int main() {
  ExecutePlusPlus ex;
  char hostname[HOST_NAME_MAX];
  time_t ttime = time(0);
  char* dt = ctime(&ttime);
  gethostname(hostname, HOST_NAME_MAX);
  cout <<"Welcome to IntelliShell, " << getenv("USER") << "!\n";
  cout << "The current local date and time is: " << dt;
  std::string shell;
    do {
      cout << getenv("USER") << "@" << hostname << " | " << get_current_dir_name() <<  " -> ";
      getline(cin, shell);
      ex.RunFunction(shell.c_str());
    }
    while(shell != "exit");
  return 0;
}
