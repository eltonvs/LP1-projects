// Teste da classe Rect
// Memory leak check done with valgrind.
// valgrind --leak-check=yes ./teste_vec3
// Para compilar: g++ -Wall rect_drive.cpp rect.cpp -o rect_drive

#include <numeric>
#include <cassert>
#include <iostream>
using std::cout;
using std::cin;
using std::cerr;
using std::endl;

#include <new>
using std::bad_alloc;

#include <cmath>
#include <vector>
#include <stdexcept>
#include <algorithm>

#include "rect.h"
using namespace MyRectangle;


int main( )
{
    //Rect myContainer [] = { Rect( 1, 1, 2, 4),
    std::vector< Rect > myContainer = {
        {Rect( 1, 1, 2, 4)},
        {Rect( 2, 2, 2, 1 )},
        {Rect( 2, 4, 1, 1 )},
        {Rect( 5, 3, 3, 1)},
        {Rect( 4, 10, 2, 7 )},
        {Rect( -2, 3, 5, 6 )},
        {Rect( -1, -4, 10, 2 )},
        {Rect( 3, -3, 8, 8 )}
    };
    
    std::cout << "\n>>> Starting UNIT test for the class MyRectangle::Rect\n\n";

    // Testando funcoes ACCESSORS
    assert( myContainer[ 0 ].getX() == 1 );
    assert( myContainer[ 0 ].getY() == 1 );
    assert( myContainer[ 0 ].getWidth() == 2 );
    assert( myContainer[ 0 ].getHeight() == 4 );
    cout << "(1)>>> getX(), getY(), getWidth(), and getHeight() methods successful!\n";
    

    // Testando construtor copia.
    Rect R1( 1, 2, 3, 4 );
    assert( R1.getX() == 1 );
    assert( R1.getY() == 2 );
    assert( R1.getWidth() == 3 );
    assert( R1.getHeight() == 4 );
    // Tentando criar retangulo invalido, o que deve gerar uma excecao.
    bool flag ( false );
    Rect *pt( nullptr );
    try {
        pt = new Rect( 1, 1, -3, -3 );
    } catch( const std::invalid_argument& e ) {
        flag = true;
        delete pt;
    }
    assert( flag );
    cout << "(2)>>> Constructor successful!\n";

    // Testando recuperacao de dados em 1 chamada
    int x(0), y(0), w(0), h(0);
    R1.getData( x, y, w, h );
    assert( x == 1 );
    assert( y == 2 );
    assert( w == 3 );
    assert( h == 4 );
    cout << "(3)>>> getData() successful!\n";

    // Testando modificacao de dados em uma chamada.
    R1.setData( 10*x, 10*y, 10*w, 10*h );
    int a, b, c, d;
    R1.getData( a, b, c, d );
    assert( a == 10*x  );
    assert( b == 10*y );
    assert( c == 10*w );
    assert( d == 10*h );
    cout << "(4)>>> setData() successful!\n";

    // Testando operador de atribuicao.
    R1.setData( 1, 2, 3, 4 );
    Rect R3;
    R3 = R1;
    assert( R3.getX() == 1 );
    assert( R3.getY() == 2 );
    assert( R3.getWidth() == 3 );
    assert( R3.getHeight() == 4 );
    cout << "(5)>>> assign operator successful!\n";

    // Testando construtor copia.
    R1.setData( 1, 2, 3, 4 );
    Rect R2( R1 );
    assert( R2.getX() == 1 );
    assert( R2.getY() == 2 );
    assert( R2.getWidth() == 3 );
    assert( R2.getHeight() == 4 );
    cout << "(6)>>> copy constructor successful!\n";

    // Testando operador de comparacao.
    R1.setData( 1, 2, 3, 4 );
    R3 = R1;
    assert( R1 == R3 );
    cout << "(7)>>> operator==() successful!\n";

    // Testando operador de desgigualdade.
    R1.setData( 1, 2, 3, 4 );
    R3.setData( 0, 2, 3, 4 );
    assert( R1 != R3 );
    R1.setData( 1, 2, 3, 4 );
    R3.setData( 1, 0, 3, 4 );
    assert( R1 != R3 );
    R1.setData( 1, 2, 3, 4 );
    R3.setData( 1, 2, 0, 4 );
    assert( R1 != R3 );
    R1.setData( 1, 2, 3, 4 );
    R3.setData( 1, 2, 3, 0 );
    assert( R1 != R3 );
    cout << "(8)>>> operator!=() operator successful!\n";
    
    // Testando operador de acesso
    R1.setData( 1, 2, 3, 4 );
    assert( R1[ Rect::field::X ] == 1 );
    assert( R1[ Rect::field::Y ] == 2 );
    assert( R1[ Rect::field::W ] == 3 );
    assert( R1[ Rect::field::H ] == 4 );
    cout << "(9)>>> operator[]() for access successful!\n";

    // Testando operador de acesso de atribuicao
    R2.setData( 4, 3, 2, 1 );
    R1[ Rect::field::X ] = 4;
    R1[ Rect::field::Y ] = 3;
    R1[ Rect::field::W ] = 2;
    R1[ Rect::field::H ] = 1;
    assert( R2 == R1 );

    // Tentando acessar posicao invalida do reta
    flag = false;
    try {
        pt = new Rect( 1, 1, 3, 3 );
        (*pt)[ 5 ] = 9;
    } catch( const std::out_of_range & e ) {
        flag = true;
        delete pt;
    }
    assert( flag );
    cout << "(10)>>> operator[]() for assignment successful!\n";

    // Testando metodo para imprimir um rectangle na saida padrao.
    // Testando funcao area().
    for_each( myContainer.begin(), myContainer.end(), [&]( const Rect& _r )
            {
                auto fDist2Origin ( sqrt( _r.getX() * _r.getX() + _r.getY() * _r.getY() ) ); 
                std::cout << "\t>> Rect[ " << (&_r - myContainer.data())<< " ] = " << _r
                << "; area = " << _r.area()
                << "; dist. p/ origem = " << fDist2Origin
                << endl;
                assert( _r.area() == ( _r.getWidth() * _r.getHeight() ) );
            });
#ifdef RUNNING_C0X
    for( int i(0); i < iSz; ++ i )
    {
        float fDist2Origin = sqrt( myContainer[i].getX()* myContainer[i].getX() + myContainer[i].getY()* myContainer[i].getY()  ); 
        cout << "  >> Rect[ " << i << " ] = " << myContainer[ i ]
              << "; area = " << myContainer[ i ].area()
              << "; dist. p/ origem = " << fDist2Origin
              << endl;
        assert( myContainer[ i ].area() == ( myContainer[ i ].getWidth() * myContainer[ i ].getHeight() ) );
    }
#endif
    cout << "(11)>>> area() successful!\n";

    

    cout << "\n>>> Normal exiting...\n\n";
    return EXIT_SUCCESS;  
}

