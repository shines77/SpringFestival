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
    // 姓名： 郭雄辉，男，生于1977年，广西贺州人
    Chinese guozi(Male, "GuoXiongHui", 1977, China::GuangXi::HeZhou);

    // 恭贺新禧！
    guozi.say("Best wishes for the year to come!");

    // 恭喜发财！
    guozi.say("May you come into a good fortune!");

    // 吉星高照！
    guozi.say("Good luck in the year ahead!");

    // 健康长寿！
    guozi.say("Wish you health and longevity!");

    // 大吉大利！
    guozi.say("Have a prosperous year!");

    // 2019猪年，新年快乐！
    guozi.say("Happy Spring Festival in the Year of Pigs 2019!");

    // (c) 郭子 2019, 版权所有
    guozi.copyright("Powered by GuoXiongHui, (c) 2019");

    // 本程序的 Github 地址如下。
    guozi.github("https://github.com/shines77/SpringFestival");
    // 写于 2019年2月4日 23:52:00
    guozi.commit("2019-02-04 23:52:00");
    // See you next year 2020!
    guozi.byebye();

    return 0;
}
