#include <iostream>
#include <string>

class MeuFunctor {
 public:
    MeuFunctor(const std::string &_msg_inicial) {
        this->o_que_voce_quer = _msg_inicial;
    }
    void print() {
        std::cout << o_que_voce_quer << "\n";
    }
    void operator()(const std::string &_complemento) {
        o_que_voce_quer += _complemento;
    }

 private:
    std::string o_que_voce_quer;
};

int main(int argc, char const *argv[]) {
    MeuFunctor fica_grande("O que a gente quer? ");

    std::string bla;

    fica_grande.print();

    std::cin >> bla;

    fica_grande(bla);

    fica_grande.print();

    return EXIT_SUCCESS;
}
