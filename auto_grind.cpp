#include <iostream>
#include <cstdlib>
#include <string>
#include <chrono>
#include <thread>

int main(int argc, char** argv){
  bool setup_track = true;
  int count = 0;
  std::string command1 = "xdotool type !work";
  std::string command2 = "xdotool type \"!dep all\"";
  std::string command3 = "xdotool key Return";
  
  if (argc >= 2){
     std::string check(argv[1]);
     if (check == "--low" || check == "-l"){
         setup_track = false;
     }
     else if (check == "--help" || check == "-h"){
              std::cout << "-h/--help to show this help message." << std::endl;
              std::cout << "-l/--low to low the wait time to 10 seconds instead of 30 seconds to start the auto type process." << std::endl;
              return 0;
     }
     else{
          std::cout << "[!] Invalid arguments, do -h/--help for more information" << std::endl;
          return 0;
     }    
  }            

  if (setup_track){
     std::cout << "[+] You have 30 seconds to locate where you gonna autotype" << std::endl;
     std::this_thread::sleep_for(std::chrono::seconds(30));
     setup_track = false;
  }

  else{
       std::cout << "[-] You have 10 seconds to locate where you gonna autotype" << std::endl;
       std::this_thread::sleep_for(std::chrono::seconds(10));
  }
       
  std::cout << "[+] The auto typing process starts now!" << std::endl;
  std::cout << "[+] You can do ctrl+c to stop the program." << std::endl;

  while (true){
      if (count != 10){
         int temp1 =  system(command1.c_str());
         if (temp1 != 0){std::cout << "[!] Error executing command! Command: " << command1 << std::endl;}
         int temp2 = system(command3.c_str());
         if (temp2 != 0){std::cout << "[!] Error executing command! Command: " << command3 << std::endl;}
         count++;
      }
      else{
           int temp1 = system(command2.c_str());
           if (temp1 != 0){std::cout << "[!] Error executing command! Command: " << command2 << std::endl;}
           int temp2 = system(command3.c_str());
           if (temp2 != 0){std::cout << "[!] Error executing command! Command: " << command3 << std::endl;}
           count = 0;
      }
      std::this_thread::sleep_for(std::chrono::minutes(1));
  }

  return 0;
}
