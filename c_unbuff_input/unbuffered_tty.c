#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <termios.h>

using namespace std;

/*This code does the same but without shelling/forking the system calls*/


char getch() {
        char buf = 0;
        struct termios old = {0};
        if (tcgetattr(0, &old) < 0)
                perror("tcsetattr()");
        old.c_lflag &= ~ICANON;
        old.c_lflag &= ~ECHO;
        old.c_cc[VMIN] = 1;
        old.c_cc[VTIME] = 0;
        if (tcsetattr(0, TCSANOW, &old) < 0)
                perror("tcsetattr ICANON");
        if (read(0, &buf, 1) < 0)
                perror ("read()");
        old.c_lflag |= ICANON;
        old.c_lflag |= ECHO;
        if (tcsetattr(0, TCSADRAIN, &old) < 0)
                perror ("tcsetattr ~ICANON");
        return (buf);
}


int main() 
{
    // Set terminal to raw mode
    // WHILE this works it is not the best to shell the code (call the system fnc)
    // but the best option is to use the <termios.h> or <sgtty.h> and call the 
    // same code that stty uses.
    //
    system("stty raw");
    char input = getchar();
    cout << "\n__" << input << "--\n";
    system("stty cooked");

    cout << "\n::" << getch() << "\n::";
    return 0;

}
