#pragma once
// Define whether we are using Windows
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#define WINDOWS true
#endif
// Included libraries
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#if defined(WINDOWS)
// Libraries only used in Windows
#include <conio.h>
#include <fcntl.h>
#include <windows.h>
#include <locale>
#include <codecvt>
#else
// Libraries only used by non-Windows
#include <unistd.h>
#endif

/*
 *  _____        __ _       _   _                            _____           _        _                         
 * |  __ \      / _(_)     | | (_)                   ___    |  __ \         | |      | |                        
 * | |  | | ___| |_ _ _ __ | |_ _  ___  _ __  ___   ( _ )   | |__) | __ ___ | |_ ___ | |_ _   _ _ __   ___  ___ 
 * | |  | |/ _ \  _| | '_ \| __| |/ _ \| '_ \/ __|  / _ \/\ |  ___/ '__/ _ \| __/ _ \| __| | | | '_ \ / _ \/ __|
 * | |__| |  __/ | | | | | | |_| | (_) | | | \__ \ | (_>  < | |   | | | (_) | || (_) | |_| |_| | |_) |  __/\__ \
 * |_____/ \___|_| |_|_| |_|\__|_|\___/|_| |_|___/  \___/\/ |_|   |_|  \___/ \__\___/ \__|\__, | .__/ \___||___/
 *                                                                                         __/ | |              
 *                                                                                        |___/|_|              
 * Read the comment blocks on these functions to learn more about how to use the library.
 */

namespace TermGame
{
/**
 * Gets a single character from stdin without need for a newline buffer. (No
 * need to press enter/return to finish input)
 * @return char  the character entered
 */
char getch();

/**
 * Gets an arrow key, unbuffered, from stdin. Expects 2-3 characters depending
 * on the user's platform.
 * @return a std::string containing one of four values that represent which
 * arrow key was pressed. "ARROW_UP", "ARROW_DOWN", "ARROW_LEFT", "ARROW_RIGHT"
 * @exception KeyPressError is thrown any time a non-arrow key is pressed in
 * response to this function
 */
std::string getarrow();

/**
 * Pauses the program for some time before continuing.
 * @param ms the time to pause in miliseconds (1000th of a second)
 */
void sleep(unsigned int ms);

} // namespace TermGame

namespace TermPrint
{
/**
 * TermPrint color codes stored as string objects for easy use. The codes will
 * also be documented on the repository.
 */
static const unsigned short DEFAULT = 0;
static const unsigned short BLACK = 1;
static const unsigned short RED = 2;
static const unsigned short YELLOW = 3;
static const unsigned short GREEN = 4;
static const unsigned short BLUE = 5;
static const unsigned short CYAN = 6;
static const unsigned short MAGENTA = 7;
static const unsigned short WHITE = 8;

/**
 * Prints a string to stdout. Interprets any TermPrint color codes of the form
 * &XY where X is the foreground code and Y is the background code.
 * @param msg the string that the user wants to print
 * @param colorize_newline should newlines have color applied to them? It can
 * create very strange effects if enabled.
*/
void print(std::string msg, bool colorize_newline = false);

/**
 * Prints a string to stdout. Overrides any TermPrint color codes found in the
 * text with color passed in by parameter.
 * @param msg the string that the user wants to print
 * @param forecolor the color of the text in the string
 * @param colorize_newline should newlines have color applied to them? It can
 * create very strange effects if enabled.
 */
void print(std::string msg, unsigned short forecolor, bool colorize_newline = false);

/**
 * Prints a string to stdout. Overrides any TermPrint color codes found in the
 * text with color passed in by parameter.
 * @param msg the string that the user wants to print
 * @param forecolor the color of the text in the string
 * @param backcolor the color behind the text in the string
 * @param colorize_newline should newlines have color applied to them? It can
 * create very strange effects if enabled.
 */
void print(std::string msg, unsigned short forecolor, unsigned short backcolor, bool colorize_newline = false);

/**
 * Clears the terminal of text.
 */
void clear();

/**
 * Fuses two multi-line string together for printing side-by-side
 * @param left the string that will be on the left half of the fused string
 * @param right the string that will be on the right half of the fused string
 * @return std::string containing both of the original strings side-by-side
 */
std::string fuse(std::string left, std::string right);

/**
 * Fuses two multi-line string together for printing side-by-side
 * @param left the string that will be on the left half of the fused string
 * @param right the string that will be on the right half of the fused string
 * @param pad bool, whether to pad each line of the string to be the same width
 */
std::string fuse(std::string left, std::string right, bool pad);

/**
 * Split a string and store each new substring in a vector.
 * @param text the original string
 * @param delim the delimiting character to split by
 * @return std::vector containing each substring
 */
std::vector<std::string> splitstring(std::string text, char delim);

/**
 *   _____ _______ ____  _____  _ 
 *  / ____|__   __/ __ \|  __ \| |
 * | (___    | | | |  | | |__) | |
 *  \___ \   | | | |  | |  ___/| |
 *  ____) |  | | | |__| | |    |_|
 * |_____/   |_|  \____/|_|    (_)
 *                                
 * Everything below this comment block you can ignore! From here on out, the file consists
 * only of internal variables that the library uses, or implementations of the functions
 * described above. If you truly want to know how everything is implemented, feel free to
 * continue reading. But, if you're only interested in utlizing the library, there is no
 * need to view the rest of this file.
 */

#if defined(WINDOWS)
// Windows fix bool.
static bool _winFix;
// We must have a reference to the active terminal for Windows' color API
static HANDLE _active_terminal;
#endif

#if defined(WINDOWS)
/**
 * Instead of making a #if every time a string shows up and making the
 * string a wide string if we're on Windows, we can overload the <<
 * operator to work with wostreams and strings so lines like:
 * wcout << "Hello World!";
 * will actually work. We're just going to convert the input string
 * into a wstring.
 * @param out the wide ostream to be output to
 * @param text the text to be converted to a wstring
 * @return the same ostream being used (for chaining output statements)
 */
std::wostream &operator<<(std::wostream &out, std::string text);
#endif

/**
 * Internal color code definitions which will work
 * with the Windows color API (or ANSI on *nix)
 * TermPrint color codes are translated back to these when printing.
 */
#if defined(WINDOWS)
static const unsigned short _BLACK = 0;
static const unsigned short _BLUE = 1;
static const unsigned short _GREEN = 2;
static const unsigned short _CYAN = 3;
static const unsigned short _RED = 4;
static const unsigned short _MAGENTA = 5;
static const unsigned short _YELLOW = 6;
static const unsigned short _WHITE = 7;
static const unsigned short _RESET_COLOR = 0;
#else
static const unsigned short _BLACK = 30;
static const unsigned short _RED = 31;
static const unsigned short _GREEN = 32;
static const unsigned short _YELLOW = 33;
static const unsigned short _BLUE = 34;
static const unsigned short _MAGENTA = 35;
static const unsigned short _CYAN = 36;
static const unsigned short _WHITE = 37;
static const unsigned short _RESET_COLOR = 39;
#endif
} // namespace TermPrint

/**
 * Namespace which holds exception classes and other error
 * handling for the TermGame and TermPrint namespaces.
 */
namespace TermError
{
/**
     * Exception for incorrect key pressed in input functions from TermGame.
     * This is useful for error handling and debugging.
     */
class KeyPressError : public std::exception
{
    std::string what_message;

public:
    KeyPressError();
    KeyPressError(std::string what_message);
    virtual const char *what() const throw();
};
} // namespace TermError

/*
 *  ______                _   _               _____                 _                           _        _   _                 
 * |  ____|              | | (_)             |_   _|               | |                         | |      | | (_)                
 * | |__ _   _ _ __   ___| |_ _  ___  _ __     | |  _ __ ___  _ __ | | ___ _ __ ___   ___ _ __ | |_ __ _| |_ _  ___  _ __  ___ 
 * |  __| | | | '_ \ / __| __| |/ _ \| '_ \    | | | '_ ` _ \| '_ \| |/ _ \ '_ ` _ \ / _ \ '_ \| __/ _` | __| |/ _ \| '_ \/ __|
 * | |  | |_| | | | | (__| |_| | (_) | | | |  _| |_| | | | | | |_) | |  __/ | | | | |  __/ | | | || (_| | |_| | (_) | | | \__ \
 * |_|   \__,_|_| |_|\___|\__|_|\___/|_| |_| |_____|_| |_| |_| .__/|_|\___|_| |_| |_|\___|_| |_|\__\__,_|\__|_|\___/|_| |_|___/
 *                                                           | |                                                               
 *                                                           |_|                                                               
 */

/*
 *  _____              ___                  ___             _   _             
 * |_   _|__ _ _ _ __ / __|__ _ _ __  ___  | __|  _ _ _  __| |_(_)___ _ _  ___
 *   | |/ -_) '_| '  \ (_ / _` | '  \/ -_) | _| || | ' \/ _|  _| / _ \ ' \(_-<
 *   |_|\___|_| |_|_|_\___\__,_|_|_|_\___| |_| \_,_|_||_\__|\__|_\___/_||_/__/
 */

char TermGame::getch()
{
#if defined(WINDOWS)
    // just use conio's getch
    return _getch();
#else
    char key;
    // turn off echo and get the input without a buffer
    system("stty -brkint -ignpar -istrip -icrnl -ixon -opost -isig -icanon -echo");
    // get the next stdin character
    //key = getchar();
    std::cin >> key;
    // set the terminal back to buffered input and echo
    system("stty cooked echo");
    return key;
#endif
}

std::string TermGame::getarrow()
{
    char key;
#if defined(WINDOWS)
    // On windows, arrow keys start with a char, value 0
    if (getch() == 0)
    {
        // The follow-up character determines which arrow key was pressed
        key = getch();
        if (key == 77)
            return "ARROW_RIGHT";
        else if (key == 72)
        {
            return "ARROW_UP";
        }
        else if (key == 75)
        {
            return "ARROW_LEFT";
        }
        else if (key == 80)
        {
            return "ARROW_DOWN";
        }
    }
#else
    // *nix systems work like the Windows version above, only arrow keys here
    // start with 2 characters, values 27 and 91, followed by a character to
    // distinguish between arrows.
    if (getch() == 27)
    {
        if (getch() == 91)
        {
            key = getch();
            if (key == 67)
                return "ARROW_RIGHT";
            else if (key == 65)
            {
                return "ARROW_UP";
            }
            else if (key == 68)
            {
                return "ARROW_LEFT";
            }
            else if (key == 66)
            {
                return "ARROW_DOWN";
            }
        }
    }
#endif
    // If a proper arrow key isn't pressed, throw an exception
    std::string error_msg = "KeyPressError: Non-arrow key pressed in response ";
    error_msg += "to TermGame::getarrow()";
    throw TermError::KeyPressError(error_msg);
}

void TermGame::sleep(unsigned int ms)
{
#if defined(WINDOWS)
    Sleep(ms);
#else
    // usleep is microseconds, not ms
    usleep(ms * 1000);
#endif
}

/*
 *  _____              ___     _     _     ___             _   _             
 * |_   _|__ _ _ _ __ | _ \_ _(_)_ _| |_  | __|  _ _ _  __| |_(_)___ _ _  ___
 *   | |/ -_) '_| '  \|  _/ '_| | ' \  _| | _| || | ' \/ _|  _| / _ \ ' \(_-<
 *   |_|\___|_| |_|_|_|_| |_| |_|_||_\__| |_| \_,_|_||_\__|\__|_\___/_||_/__/
 */

void TermPrint::print(std::string msg, bool colorize_newline)
{
    // Internal colors mapped in an array in order of the
    // public facing color codes.
    static const unsigned short _COLORS[] = {
        _RESET_COLOR,
        _BLACK,
        _RED,
        _YELLOW,
        _GREEN,
        _BLUE,
        _CYAN,
        _MAGENTA,
        _WHITE};
    /**
     * If we aren't coloring newlines, we need to ensure every newline includes
     * a &00 indicating that it should be reset.
     */
    if (!colorize_newline)
    {
        size_t start_pos = 0;
        std::string old = "\n";
        std::string repl = "&00\n";
        while ((start_pos = msg.find(old, start_pos)) != std::string::npos)
        {
            msg.replace(start_pos, old.length(), repl);
            start_pos += repl.length(); // Handles case where 'to' is a substring of 'from'
        }
    }
    // split the strings by the color code delimeter '&'
    std::vector<std::string> strings = splitstring(msg, '&');
#if defined(WINDOWS)
    std::wcout << strings[0];
    for (int i = 1; i < strings.size(); i++)
    {
        if (strings[i] == "")
        {
            std::wcout << '&';
        }
        else
        {
            if (i < 2 || strings[i - 1] != "")
            {
                // Get our color codes
                int fg_code = strings[i][0] - '0';
                int bg_code = strings[i][1] - '0';
                // std::wcout << "\n\nRECOLORING, COLOR CODES: (" << fg_code << ", " << bg_code << ")\n\n";
                // TermGame::getch();
                // Remove the color codes from the string
                strings[i].erase(0, 2);
                // Now lets actually use those color codes
                if (_COLORS[bg_code] != 0)
                {
                    SetConsoleTextAttribute(_active_terminal, (16 * _COLORS[bg_code]) + _COLORS[fg_code]);
                }
                else
                {
                    SetConsoleTextAttribute(_active_terminal, (16 * _BLACK) + _COLORS[fg_code]);
                }
            }
            std::wcout << strings[i];
        }
    }
    // Reset the terminal colors after the text is done printing
    SetConsoleTextAttribute(_active_terminal, (16 * _BLACK) + _WHITE);
#else
    std::cout << strings[0];
    for (int i = 1; i < strings.size(); i++)
    {
        if (strings[i] == "")
        {
            std::cout << '&';
        }
        else
        {
            if (i < 2 || strings[i - 1] != "")
            {
                // Get our color codes
                int fg_code = strings[i][0] - '0';
                int bg_code = strings[i][1] - '0';
                // Remove the color codes from the string
                strings[i].erase(0, 2);
                // Now lets actually use those color codes
                std::cout << "\033[" << _COLORS[fg_code] << ';' << _COLORS[bg_code] + 10 << 'm';
            }
            std::cout << strings[i];
        }
    }
    // Reset the terminal colors after the text is done printing
    std::cout << "\033[" + std::to_string(_RESET_COLOR) << ';' << std::to_string(_RESET_COLOR + 10) << 'm';
#endif
}

void TermPrint::print(std::string msg, unsigned short forecolor, bool colorize_newline)
{
#if defined(WINDOWS)
    print(msg, forecolor, _BLACK, colorize_newline);
#else
    print(msg, forecolor, _RESET_COLOR, colorize_newline);
#endif
}

void TermPrint::print(std::string msg, unsigned short forecolor, unsigned short backcolor, bool colorize_newline)
{
    // Internal colors mapped in an array in order of the
    // public facing color codes.
    static const unsigned short _COLORS[] = {
        _RESET_COLOR,
        _BLACK,
        _RED,
        _YELLOW,
        _GREEN,
        _BLUE,
        _CYAN,
        _MAGENTA,
        _WHITE};
    forecolor = _COLORS[forecolor];
    backcolor = _COLORS[backcolor];
    /**
     * If we aren't coloring newlines, we need to ensure every newline resets the color
     */
    std::vector<std::string> msgs;
    if (!colorize_newline)
    {
        msgs = splitstring(msg, '\n');
    }
    for (int i = 0; i < msgs.size(); i++)
    {
#if defined(WINDOWS)
        // If we're using windows and it has not yet been fixed
        if (!_winFix)
        {
            // set the console mode for unicode
            _setmode(_fileno(stdout), _O_U16TEXT);
            // We must have a reference to the active terminal for Windows' color API
            _active_terminal = GetStdHandle(STD_OUTPUT_HANDLE);
            // Mark the Windows fix as complete
            _winFix = true;
        }
        // Color the console based on the arguments
        // Win API color codes are of the form 0xXY
        // X is a hex digit in the 16's place (multiples of 16)
        // representing the background color. Y is a hex digit in the
        // 1's place (multiples of 1) representing the text color. Hence,
        // the addition below which generates a base 10 equivalent.
        SetConsoleTextAttribute(_active_terminal, (16 * backcolor) + forecolor);
        std::wcout << msgs[i];
        SetConsoleTextAttribute(_active_terminal, (16 * _BLACK) + _WHITE);
        if (msg.find('\n') > 1)
            std::wcout << "\n";
#else
        // This will all run if we are using *nix
        // print the color code for foreground and add 10 to convert foreground colors to background
        std::cout << "\033[" + std::to_string(forecolor) << ';' << std::to_string(backcolor + 10) << 'm';
        std::cout << msgs[i];
        std::cout << "\033[" + std::to_string(_RESET_COLOR) << ';' << std::to_string(_RESET_COLOR + 10) << 'm';
        // if (msg.find('\n') > 1)
        //     std::cout << '\n';
#endif
    }
}

void TermPrint::clear()
{
#if defined(WINDOWS)
    // if using Windows, fake it by going down lots of lines
    std::wcout << std::string(40, '\n');
#else
    // on *nix use ANSI escape
    //std::cout << "\033[2J";
    std::cout <<"\033[2J\033[1;1H";
#endif
}

std::string TermPrint::fuse(std::string left, std::string right)
{
    return fuse(left, right, false);
}

std::string TermPrint::fuse(std::string left, std::string right, bool pad)
{
    std::string result = "";
    // split the strings, create vectors
    std::vector<std::string> lv = TermPrint::splitstring(left, '\n');
    std::vector<std::string> rv = TermPrint::splitstring(right, '\n');
    // correct the number of lines in the strings so they match
    if (lv.size() > rv.size())
    {
        int diff = lv.size() - rv.size();
        for (int i = 0; i < diff; i++)
        {
            rv.push_back("");
        }
    }
    else if (lv.size() < rv.size())
    {

        int diff = rv.size() - lv.size();
        for (int i = 0; i < diff; i++)
        {
            lv.push_back("");
        }
    }
    if (pad)
    {
        // find the largest line out of any of the vectors
        int max = 0;
        for (int i = 0; i < lv.size(); i++)
        {
            if (lv[i].size() > max)
                max = lv[i].size();
            if (rv[i].size() > max)
                max = rv[i].size();
        }
        // for each line in both vectors, pad the line for max size
        for (int i = 0; i < lv.size(); i++)
        {
            if (lv[i].size() < max)
            {
                int diff = max - lv[i].size();
                lv[i] += std::string(diff, ' ');
            }
            if (rv[i].size() < max)
            {
                int diff = max - rv[i].size();
                rv[i] += std::string(diff, ' ');
            }
        }
    }
    // loop through the vectors and produce the new string
    for (int i = 0; i < lv.size(); i++)
    {
        result += lv[i] + rv[i] + '\n';
    }
    return result;
}

std::vector<std::string> TermPrint::splitstring(std::string text, char delim)
{
    std::vector<std::string> strings;
    while (text.size() > 0)
    {
        int i = 0;
        while (text[i] != delim && i < text.size())
            i++;
        strings.push_back(text.substr(0, i));
        text.erase(0, i + 1);
    }
    return strings;
}

#if defined(WINDOWS)
std::wostream &TermPrint::operator<<(std::wostream &out, std::string text)
{
    /**
     * create a string <-> wide string converter
     * example from stack overflow
     * std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
     * std::string narrow = converter.to_bytes(wide_utf16_source_string);
     * std::wstring wide = converter.from_bytes(narrow_utf8_source_string);
     */
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    std::wstring wide_text = converter.from_bytes(text);
    out << wide_text;
    return out;
}
#endif

/*
 *  _____              ___                   ___             _   _             
 * |_   _|__ _ _ _ __ | __|_ _ _ _ ___ _ _  | __|  _ _ _  __| |_(_)___ _ _  ___
 *   | |/ -_) '_| '  \| _|| '_| '_/ _ \ '_| | _| || | ' \/ _|  _| / _ \ ' \(_-<
 *   |_|\___|_| |_|_|_|___|_| |_| \___/_|   |_| \_,_|_||_\__|\__|_\___/_||_/__/
 */

TermError::KeyPressError::KeyPressError()
{
    what_message = "KeyPressError: Invalid key pressed!";
}

TermError::KeyPressError::KeyPressError(std::string what_message)
{
    this->what_message = what_message;
}

const char *TermError::KeyPressError::what() const throw()
{
    return what_message.c_str();
}
