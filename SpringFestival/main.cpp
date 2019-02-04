#include <stdio.h>
#include <stdlib.h>

namespace SpringFestival {

enum Sex {
    Male,
    Female
};

struct Country {
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
    namespace GuangXi {
        static Location HeZhou;
    }
}

class Man {
public:
    Man() {}
    Man(const Man & src) {}
    Man(Sex sex, const char * name, int year, Country::Type country, Location loc) {}

    virtual void say(const char * words) = 0;
    virtual void copyright(const char * text) = 0;
    void github(const char * url) {}
    void commit(const char * datetime) {}
    void byebye() {}
};

class Chinese : public Man {
public:
    Chinese(Sex sex, const char * name, int year, Location loc)
        : Man(sex, name, year, Country::Chinese, loc)
    {}

    void say(const char * words) {}
    void copyright(const char * text) {}
};

} // namespace SpringFestival

using namespace SpringFestival;

int main(int argn, char argv[])
{
    // ������ ���ۻԣ��У�����1977�꣬����������
    Chinese guozi(Male, "GuoXiongHui", 1977, China::GuangXi::HeZhou);

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
    guozi.say("Happy Spring Festival in the Year of Pigs 2019!");

    // (c) ���� 2019, ��Ȩ����
    guozi.copyright("Powered by GuoXiongHui, (c) 2019");

    // ������� Github ��ַ���¡�
    guozi.github("https://github.com/shines77/SpringFestival");
    // д�� 2019��2��4�� 23:52:00
    guozi.commit("2019-02-04 23:52:00");
    // See you next year 2020!
    guozi.byebye();

    return 0;
}
