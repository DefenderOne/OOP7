#ifndef TEXT_H
#define TEXT_H

#include <iostream>
#include <string>

class DistortionProcedure {
protected:
    std::string text;
public:
    DistortionProcedure(std::string text);
    virtual std::string proceed(int cycles = 1) = 0;
    std::string getBaseText();
};

class NumberDistortion : public DistortionProcedure {
public:
    NumberDistortion(std::string text);
    std::string proceed(int cycles = 1);
};

class LetterDistortion : public DistortionProcedure {
public:
    LetterDistortion(std::string text);
    std::string proceed(int cycles = 1);
};

class SignDistortion : public DistortionProcedure {
private:
    int signs[6] = { '.', ',', '\'', '\"', '!', '?' };
    bool isSign(char sym);
public:
    SignDistortion(std::string text);
    std::string proceed(int cycles = 1);
};

class TextDistortion : DistortionProcedure {
public:
    std::string operator()(int cycles = 1);
    TextDistortion(std::string text);
    ~TextDistortion();
    std::string proceed(int cycles = 1);
};

#endif