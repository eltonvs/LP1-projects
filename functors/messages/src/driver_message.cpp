// Copyright 2016

/**
 * Exercício
 * ---------
 *
 * 1) Implementar message.cpp de acordo com a especificação de message.h.
 * 2) Imprimir as mensagens por ordem de
 *    a) Remetente
 *    b) Assunto
 *    c) Data de envio
 *    utilizando functors.
 *
 * 3) Fazer o programa trabalhar com objetos mensagem criado com alocação
 * dinâmica e ponteiros.
 *
 * 4) Converter o programa do passo 2 para trabalhar com std::unique_ptr<>.
 *
 */

#include <iostream>
#include <algorithm>
#include <vector>

#include "message.hpp"

int main() {
    Message m1("selan@dimap.ufrn.br", "LP1", "201509011355", "jack@gmail.com", "jack.boy@hotmail.com", "false", "Aqui começa o corpo da mensagem\n Queremos voce por aqui.\n \n Ate breve!");
    Message m2("andre@gmail.com", "Qualquer coisa", "201509101255");
    Message m3("silvia.mota@hotmail.com", "Pesquisa em conjunto", "201509101055");

    std::vector <Message> ms;

    ms.push_back(m1);
    ms.push_back(m2);
    ms.push_back(m3);

    std::cout << ">>> Original messages: \n";
    for (auto const & e : ms)
        std::cout << e << "\n";

    // TODO:
    // Aqui eh onde você deve ordenar as mensagens armazenadas em ms.

    std::cout << ">>> Sorted messages by Subject: \n";
    for ( auto const & e : ms )
        std::cout << e << "\n";

#ifdef _XXXx
    std::sort(ms.begin(), ms.end(), mySorterDate);

    std::cout << ">>> Sorted messages by Date: \n";
    for (auto const & e : ms)
        std::cout << e << "\n";

    std::sort(ms.begin(), ms.end(), mySorterSender);

    std::cout << ">>> Sorted messages by Sender: \n";
    for (auto const & e : ms)
        std::cout << e << "\n";
#endif

    std::cout << ">>> Normal exiting....\n";
    return EXIT_SUCCESS;
}
