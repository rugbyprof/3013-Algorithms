# TermGame
A simple c++ library that helps in the creation of games in the terminal. It was designed for freshmen computer science students, so it is cross-platform and simple to use.

## TermPrint Escape Sequences
Escape sequences in TermPrint are of the form "&XY" where X and Y are replaced
with numeric codes from the chart below. (Note, when escaping to print a
literal '&', there will not be a Y value)

| Color    | Code |
| :---:    | :-:  |
| Default  | 0    |
| Black    | 1    |
| Red      | 2    |
| Yellow   | 3    |
| Green    | 4    |
| Blue     | 5    |
| Cyan     | 6    |
| Magenta  | 7    |
| White    | 8    |

## Function Documentation
```cpp
/**
 * Gets a single character from stdin without need for a newline buffer.
 * (No need to press enter/return to finish input)
 * @return char  the character entered
 */
char TermGame::getch();

/**
 * Gets an arrow key, unbuffered, from stdin. Expects 2-3 characters
 * depending on the user's platform.
 * @return a std::string containing one of four values that
 * represent which arrow key was pressed. "ARROW_UP", "ARROW_DOWN",
 * "ARROW_LEFT", "ARROW_RIGHT"
 * @exception KeyPressError thrown any time a non-arrow key is pressed
 * in response to this function
 */
std::string TermGame::getarrow();

/**
 * Pauses the program for some time before continuing.
 * @param ms the time to pause in miliseconds (1000th of a second)
 */
void TermGame::sleep(unsigned int ms);

/**
 * Prints a string to stdout. Interprets any TermPrint
 * color codes of the form &XY where X is the foreground
 * code and Y is the background code.
 * @param msg the string that the user wants to print
 * @param colorize_newline should newlines have color applied to them? It can
 * create very strange effects if enabled.
*/
void TermPrint::print(std::string msg, bool colorize_newline = false);

/**
 * Prints a string to stdout. Overrides any TermPrint
 * color codes found in the text with color passed in
 * by parameter.
 * @param msg the string that the user wants to print
 * @param forecolor the color of the text in the string
 * @param colorize_newline should newlines have color applied to them? It can
 * create very strange effects if enabled.
 */
void TermPrint::print(std::string msg, unsigned short forecolor, bool colorize_newline = false);

/**
 * Prints a string to stdout. Overrides any TermPrint
 * color codes found in the text with color passed in
 * by parameter.
 * @param msg the string that the user wants to print
 * @param forecolor the color of the text in the string
 * @param backcolor the color behind the text in the string
 * @param colorize_newline should newlines have color applied to them? It can
 * create very strange effects if enabled.
 */
void TermPrint::print(std::string msg, unsigned short forecolor, unsigned short backcolor, bool colorize_newline = false);

/**
 * Clears the terminal of text.
 */
void TermPrint::clear();

/**
 * Fuses two multi-line string together for printing side-by-side
 * @param left the string that will be on the left half of the fused string
 * @param right the string that will be on the right half of the fused string
 */
std::string TermPrint::fuse(std::string left, std::string right);

/**
 * Fuses two multi-line string together for printing side-by-side
 * @param left the string that will be on the left half of the fused string
 * @param right the string that will be on the right half of the fused string
 * @param pad bool, whether to pad each line of the string to be the same width
 */
std::string TermPrint::fuse(std::string left, std::string right, bool pad);

/**
 * Split a string and store each new substring in a vector.
 * @param text the original string
 * @param delim the delimiting character to split by
 * @return std::vector containing each substring
 */
std::vector<std::string> TermPrint::splitstring(std::string text, char delim);
```