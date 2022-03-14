#include <iostream>
#include "sha512.h"

// Windows
#include <windows.h>
#include <conio.h>
// *nix
//#include <curses.h>


int main(int argc, char *argv[]) {
    std::cout << "Ingrese un texto a encriptar: \n";
    /*LINUX
    #include <iostream>
#include <string>
#include <termios.h>
#include <unistd.h>

using namespace std;

int main()
{
    termios oldt;
    tcgetattr(STDIN_FILENO, &oldt);
    termios newt = oldt;
    newt.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    string s;
    getline(cin, s);

    cout << s << endl;
    return 0;
}
    */

    char exit; // Windows
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE); 
    DWORD mode = 0;
    GetConsoleMode(hStdin, &mode);
    SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));

    std::string input;
    getline(std::cin, input);

    std::string output1 = sha512(input);
    
    input.clear();
    fflush(stdin);
    
    std::cout << output1 << std::endl;
    std::cout << "Listo! Ahora, presione una tecla cualquiera para salir.\n";
    getch();
    
    return 0;
}