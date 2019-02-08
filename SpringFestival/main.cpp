#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

namespace SpringFestival {

enum Sex {
    Unknown,
    Male,
    Female
};

struct Country {
    enum Type {
        UnitedStates,
        UnitedKingdom,
        Germany,
        France,
        Spain,
        Italy,
        Russia,
        China,
        Japan,
        Korea
    };
};

struct Language {
    enum Type {
        American,
        Briton,
        German,
        French,
        Spanish,
        Italian,
        Russian,
        Chinese,
        Japanese,
        Korean
    };
};

class Location {
};

namespace China {
    static Location BeiJing;
    static Location ShangHai;
    static Location GuangZhou;
    static Location ShenZhen;
    namespace GuangXi {
        static Location HeZhou;
    }
}

class Person {
protected:
    std::string name_;
    Sex sex_;
    int year_;
    Country::Type country_;
    Location location_;

public:
    Person() : sex_(Sex::Unknown), year_(0), country_(Country::China), location_(China::BeiJing) {} 
    Person(const Person & src) {
        name_ = src.name_;
        sex_ = src.sex_;
        year_ = src.year_;
        country_ = src.country_;
        location_ = src.location_;
    }
    Person(const std::string & name, Sex sex, int year, Country::Type country, Location location)
        : name_(name), sex_(sex), year_(year), country_(country), location_(location) {}

    virtual void sayWords(const std::string & words) = 0;

    virtual void say(const std::string &  words) = 0;
    virtual void copyright(const std::string & text) = 0;

    virtual void github(const std::string & url) = 0;
    virtual void commit(const std::string & datetime) = 0;
    virtual void byebye() = 0;
};

class Chinese : public Person {
public:
    Chinese(const std::string & name, Sex sex, int year, Location location)
        : Person(name, sex, year, Country::China, location)
    {}

    void sayWords(const std::string & words) {
        std::cout << name_.c_str() << ": " << words.c_str() << std::endl;
    }

    void say(const std::string & words) { sayWords(words); }
    void copyright(const std::string & text) { sayWords(text); }

    void github(const std::string & url) {
        std::string words = "GitHub: " + url;
        sayWords(words);
    }
    void commit(const std::string & datetime) {
        std::string words = "Commit by: " + datetime;
        sayWords(words);
    }
    void byebye() {
        sayWords("byebye.");
        std::cout << std::endl;
    }
};

} // namespace SpringFestival

using namespace SpringFestival;

int main(int argn, char argv[])
{
    // ���������ۻԣ��У�1977�꣬����������
    Chinese guozi("GuoXiongHui", Male, 1977, China::GuangXi::HeZhou);

    // ����������
    guozi.say("Best wishes for the year to come!");

    // ��ϲ���ƣ�
    guozi.say("May you come into a good fortune!");

    // ���Ǹ��գ�
    guozi.say("Good luck in the year ahead!");

    // �������٣�
    guozi.say("Wish you health and longevity!");

    // �󼪴�����
    guozi.say("Have a prosperous year!");

    // 2019���꣬������֣�
    guozi.say("Happy spring festival in the year of pigs 2019!");

    // (c) ���� 2019, ��Ȩ����
    guozi.copyright("(c) 2019, Powered by GuoXiongHui.");

    // ������� Github ��ַ���¡�
    guozi.github("https://github.com/shines77/SpringFestival");
    // д�� 2019��2��4�� 23:52:00
    guozi.commit("2019-02-04 23:52:00");
    // See you next year 2020!
    guozi.byebye();

    return 0;
}
