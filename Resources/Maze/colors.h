#include <map>
#include <string>
#include <iostream>

using namespace std;

struct colorType
{

  map<string, int> fcm;
  map<string, int> bcm;
  colorType()
  {
    fcm["default"] = 39;
    fcm["black"] = 30;
    fcm["red"] = 31;
    fcm["green"] = 32;
    fcm["yellow"] = 33;
    fcm["blue"] = 34;
    fcm["magenta"] = 35;
    fcm["cyan"] = 36;
    fcm["light_gray"] = 37;
    bcm["default"] = 49;
    bcm["black"] = 40;
    bcm["red"] = 41;
    bcm["green"] = 42;
    bcm["yellow"] = 43;
    bcm["blue"] = 44;
    bcm["magenta"] = 45;
    bcm["cyan"] = 46;
    bcm["light_gray"] = 47;
  }

  void set_fg(string color)
  {
    cout << "\033[" << fcm[color] << "m";
  }

  void set_bg(string color)
  {
    cout << "\033[" << bcm[color] << "m";
  }

  string fg(string c)
  {
    string color = "\033[";
    color += fcm[c];
    color += "m";
    return color;
  }

  string bg(string c)
  {
    string color = "\033[";
    color += bcm[c];
    color += "m";
    return color;
  }

  void reset()
  {
    cout << "\033[" << fcm["default"] << "m";
    cout << "\033[" << bcm["default"] << "m";
  }
};

colorType colors;
