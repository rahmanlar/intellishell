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
  ex.ExecuteName("IntelliShell");
  char hostname[HOST_NAME_MAX];
  time_t ttime = time(0);
  char* dt = ctime(&ttime);
  gethostname(hostname, HOST_NAME_MAX);
  cout << "\033[1;34m" << "Welcome to IntelliShell, " "\033[0m" <<  "\033[0;92m" << getenv("USER") << "\033[0m" << "!\n";
  cout << "\033[1;34m" << "The current local date and time is: " << "\033[0m" << "\033[0;92m" << dt;
  std::string shell;
    do {
      cout << "\033[1;34m" << getenv("USER") << "\033[0m"<< "\033[0;92m" << "@" << "\033[0m" << "\033[1;34m" << hostname << "\033[0m" << "\033[93m" << " | " << "\033[0m" << "\033[0;31m" << get_current_dir_name() << "\033[0m" << "\033[0;92m" " -> " << "\033[0m";
      getline(cin, shell);
      ex.RunFunction(shell.c_str());
    }
   while(shell.find("cd"));
    std::string choosedirectory;
     cout << "Choose a directory: ";
     getline(cin, choosedirectory);
     chdir(choosedirectory.c_str());
    while(shell != "exit");
  return 0;
}
