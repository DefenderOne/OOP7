#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "..\Headers\text.h"

// Distortion Base

DistortionProcedure::DistortionProcedure(std::string text) {
    this->text = text;
}

std::string DistortionProcedure::getBaseText() {
    return text;
}

// Number Distortion

NumberDistortion::NumberDistortion(std::string text) : DistortionProcedure(text) {}

std::string NumberDistortion::proceed(int cycles) {
    std::string result, temp = text;
    srand(time(NULL));
    for (int i = 0; i < cycles; i++) {
        result = "";
        for (int j = 0; j < temp.size(); j++) {
            if (std::isdigit(temp[j])) {
                int number = rand() % 7;
                int tempNum = rand() % 10;
                switch (number)
                {
                    case 0:
                    case 1: {
                        result += '0' + tempNum;
                        break;
                    }
                    default: {
                        result += temp[j];
                        break;
                    }
                }
            }
            else {
                result += temp[j];
            }
        }
        temp = result;
    }
    return result;
}

// Text Distortion

LetterDistortion::LetterDistortion(std::string text) : DistortionProcedure(text) { }

std::string LetterDistortion::proceed(int cycles) {
    std::string result, temp = text;
    srand(time(NULL));
    for (int i = 0; i < cycles; i++) {
        result = "";
        for (int j = 0; j < temp.size(); j++) {
            if (isalpha(temp[j])) {
                int number = rand() % 12;
                int tempNum = rand() % 26;
                // Смена регистра
                // Замена транслитерой
                // Замена любой другой буквой (очень редкий вариант)
                switch (number) {
                    case 0: {
                        result += 'a' + tempNum;
                        break;
                    }
                    case 1:
                    case 2: {
                        if (isupper(temp[j])) {
                            result += (char)tolower(temp[j]);
                        }
                        else {
                            result += (char)toupper(temp[j]);
                        }
                        break;
                    }
                    case 4:
                    case 5: {
                        switch (temp[j]) {
                            case 'e':
                            case 'E': { result += '3'; break; }
                            case 's': { result += '5'; break; }
                            case 'G': { result += '6'; break; }
                            case 'U':
                            case 'u': { result += 'v'; break; }
                            case 'A': { result += '4'; break; }
                            case 'I': 
                            case 'i': { result += '1'; break; }
                            default: { result += temp[j]; break; }
                        }
                        break;
                    }
                    default: {
                        result += temp[j];
                        break;
                    }
                }
            }
            else {
                result += temp[j];
            }
        }
        temp = result;
    }
    return result;
}

// Sign Distortion

SignDistortion::SignDistortion(std::string text) : DistortionProcedure(text) { }

bool SignDistortion::isSign(char sym) {
    return sym == '!' || sym == ',' || sym == '.' || sym == '\"' || sym == '\''|| sym == '?';
}

std::string SignDistortion::proceed(int cycles) {
    std::string result, temp = text;
    srand(time(NULL));
    for (int i = 0; i < cycles; i++) {
        result = "";
        for (int j = 0; j < temp.size(); j++) {
            if (isSign(temp[j])) {
                int number = rand() % 7;
                int tempNum = rand() % 6;
                switch (number) {
                    case 0: {
                        result += ' ';
                        break;
                    }
                    case 1:
                    case 2: {
                        result += signs[tempNum];
                        break;
                    }
                    default: {
                        result += temp[j];
                        break;
                    }
                }
            }
            else {
                result += temp[j];
            }
        }
        temp = result;
    }
    return result;
}

// Text Distortion

TextDistortion::TextDistortion(std::string text) : DistortionProcedure(text) { }

TextDistortion::~TextDistortion() { }

std::string TextDistortion::operator()(int cycles) {
    return proceed(cycles);
}

std::string TextDistortion::proceed(int cycles) {
    std::string temp = text;
    temp = NumberDistortion(temp).proceed(cycles);
    temp = LetterDistortion(temp).proceed(cycles);
    temp = SignDistortion(temp).proceed(cycles);
    return temp;
}