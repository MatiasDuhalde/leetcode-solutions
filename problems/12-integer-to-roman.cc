#include <string>

class Solution {
 public:
  std::string intToRoman(int num) {
    int thousands = num / 1000;
    int hundreds = (num % 1000) / 100;
    int tens = (num % 100) / 10;
    int ones = num % 10;

    std::string result = "";
    for (int i = 0; i < thousands; i++) {
      result += "M";
    }
    if (hundreds == 4) {
      result += "CD";
    } else if (hundreds == 9) {
      result += "CM";
    } else {
      if (hundreds >= 5) {
        result += "D";
        hundreds -= 5;
      }
      for (int i = 0; i < hundreds; i++) {
        result += "C";
      }
    }
    if (tens == 4) {
      result += "XL";
    } else if (tens == 9) {
      result += "XC";
    } else {
      if (tens >= 5) {
        result += "L";
        tens -= 5;
      }
      for (int i = 0; i < tens; i++) {
        result += "X";
      }
    }
    if (ones == 4) {
      result += "IV";
    } else if (ones == 9) {
      result += "IX";
    } else {
      if (ones >= 5) {
        result += "V";
        ones -= 5;
      }
      for (int i = 0; i < ones; i++) {
        result += "I";
      }
    }

    return result;
  }
};
