// Copyright 2016
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>

class Hero {
 public:
    enum attribute_t {ATTACK, DEFENSE, HEALING};

    Hero(std::string n = ""): m_name(n) {
        m_points.resize(3);
        std::fill(m_points.begin(), m_points.end(), 0);
    }

    // Setters
    void setAttribute(attribute_t a, int v) {
        m_points[a] = v;
    }

    // Getters
    int getAttribute(attribute_t a) const {
        return m_points[a];
    }
    std::string getName(void) const {
        return m_name;
    }

 private:
    std::string m_name;
    std::vector<int> m_points;
};

std::ostream & operator<< (std::ostream &_os, const Hero &_h) {
    _os << "{<" << _h.getName()
        << ">, A = " << _h.getAttribute(Hero::ATTACK)
        << ", D = " << _h.getAttribute(Hero::DEFENSE)
        << ", H = " << _h.getAttribute(Hero::HEALING)
        << "}";

    return _os;
}

struct CompareAttrib {
    CompareAttrib(Hero::attribute_t at) : m_at(at) {}
    bool operator()(const Hero &_h1, const Hero &_h2) {
        return _h1.getAttribute(m_at) < _h2.getAttribute(m_at);
    }

    Hero::attribute_t m_at;
};

int main(int argc, char const *argv[]) {
    std::vector<Hero> heros = {
        Hero("Hulk"),
        Hero("Batman"),
        Hero("Superman"),
        Hero("Spiderman"),
        Hero("Wolwerine")
    };

    enum heros_t {HULK, BATMAN, SUPERMAN, SPIDERMAN, WOLWERINE};

    heros[HULK].setAttribute(Hero::ATTACK, 10000);
    heros[HULK].setAttribute(Hero::DEFENSE, 10000);
    heros[HULK].setAttribute(Hero::HEALING, 10);

    heros[BATMAN].setAttribute(Hero::ATTACK, 100);
    heros[BATMAN].setAttribute(Hero::DEFENSE, 10);
    heros[BATMAN].setAttribute(Hero::HEALING, 10);

    heros[SUPERMAN].setAttribute(Hero::ATTACK, 200000);
    heros[SUPERMAN].setAttribute(Hero::DEFENSE, 200000);
    heros[SUPERMAN].setAttribute(Hero::HEALING, 2000);

    heros[WOLWERINE].setAttribute(Hero::ATTACK, 560);
    heros[WOLWERINE].setAttribute(Hero::DEFENSE, 800);
    heros[WOLWERINE].setAttribute(Hero::HEALING, 10000000);

    std::cout << ">>> Heroes list before sorting: [\n";
    std::copy(heros.begin(), heros.end(),
        std::ostream_iterator<Hero> (std::cout, "\n"));
    std::cout << "]\n";

    // Functors to compare (and sort)
    CompareAttrib cmp_at(Hero::ATTACK);
    CompareAttrib cmp_df(Hero::DEFENSE);
    CompareAttrib cmp_hl(Hero::HEALING);

    std::sort(heros.begin(), heros.end(), cmp_at);

    std::cout << ">>> Heroes list after sorting: [\n";
    std::copy(heros.begin(), heros.end(),
        std::ostream_iterator<Hero> (std::cout, "\n"));
    std::cout << "]\n";

    return EXIT_SUCCESS;
}
