/**
 * This is a test file that will ensure most of the TermGame functions are
 * working. It is not part of the library and should not be included in your
 * project.
 */

#include <iostream>
#include <string>
#include "TermGame.h"
using namespace std;
namespace TG = TermGame;
namespace TP = TermPrint;

int main()
{
    TP::print("\n[TEST UNBUFFERED INPUT]\n");
    // test getting a single character from stdin
    cout << "Press any key:\n";
    cout << TG::getch() << endl;
    // test getting arrow keys
    cout << "Press 4 Arrow Keys:\n";
    for (int i = 0; i < 4; i++)
    {
        cout << TG::getarrow() << endl;
    }

    // test splitting strings
    TP::print("\n[TEST SPLITTING STRINGS]\n");
    std::string mystring = "Hello+World+Please+Say+Hi";
    std::vector<std::string> myvec;
    myvec = TP::splitstring(mystring, '+');
    TP::print("original: " + mystring + '\n');
    TP::print("split: " + myvec[0]);
    for (int i = 1; i < myvec.size(); i++)
    {
        TP::print(", " + myvec[i]);
    }
    TP::print("\n");

    // test splitting strings
    TP::print("\n[TEST SLEEPING]\n");
    for (int i = 0; i < 3; i++)
    {
        TG::sleep(1000);
        TP::print(".");
    }
    TP::print("\npress any key.");
    TG::getch();

    // test fusing strings
    TP::print("\n\n[TEST FUSING STRINGS]\n");
    std::string car = "\n";
    car += "     .--.\n";
    car += ".----'   '--.\n";
    car += "'-()-----()-'\n";
    std::string atm = "";
    atm += " ___\n";
    atm += "[ATM]\n";
    atm += "  |\n";
    atm += "  |\n";
    TP::print("fusing strings without padding...\n");
    TP::print(TP::fuse(car, atm));
    TP::print("\nfusing strings with padding...\n");
    TP::print(TP::fuse(car, atm, true));

    // Test the color code interpreters
    TP::print("\n[TEST COLOR INTERPRETATION]\n");
    TP::print("This is colored! (and ignores codes like &72)\n", TP::RED, TP::WHITE);
    TP::print("This is also colored! (and will also ignore codes like &31)\n", TP::BLUE);
    TP::print("This is not!\n");
    TP::print("But this is&50 colored using &42TermPrint escapes!\n");
    TP::print("I can print with escapes &18&& the '&&' character.\n");
    TP::print("Notice how color resets after printing?\n");

    // Can we fuse strings with color codes?
    TP::print("\n[TEST FUSE && COLOR]\n");
    std::string card1 = "";
    card1 += "&20┏━━┓\n";
    card1 += "&20┃Q♥┃\n";
    card1 += "&20┗━━┛\n";
    std::string card2 = "";
    card2 += "&18┏━━┓\n";
    card2 += "&18┃K♠┃\n";
    card2 += "&18┗━━┛\n";
    TP::print("Can we fuse strings with color codes?\n");
    //TP::print(TP::fuse(card1, card2));
    TP::print(TP::fuse(card1, card2));
    TP::print("Yes! (but padding may behave strangely...)\n");
    //TP::print(TP::fuse(card1, card2, true));
    TP::print(TP::fuse(card1, card2, true));

    // TG::sleep(15000);
    // TP::clear();
}