/**
 SOURCE FILE : rect.cpp
 DESCRIPTION.: Description of this module can be found in vec3.hh
 AUTHOR......: Selan R. dos Santos.
 LOCATION....: DIMAp/UFRN.
 SATARTED ON.: August/2006
 CHANGES.....: No changes.

 TO COMPILE..: g++ -c rec.cpp
 OBS.........: Part of the XXX Project.

 LAST UPDATE.: February 25th, 2015.
*/

/* ========================================================================= */
/* INCLUDES					                             */
/* ------------------------------------------------------------------------- */

// General includes
#include <cmath>

#include <new>
using std::bad_alloc;

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

#include <cassert>

#include "rect.h"

namespace MyRectangle {
    /* ========================================================================= */
    /* DEFINITION OF CONSTANTS AND MACROS		                             */
    /* ------------------------------------------------------------------------- */


    /* ========================================================================= */
    /* METHODS IMPLEMENTATION                                                    */
    /* ------------------------------------------------------------------------- */


    //! Construtor padr&atilde;o.
    /*! Esse construtor cria um ret&acirc;ngulo baseado nos 4 valores passado como argumento.
     * O ret&acirc;ngulo &eacute; definito pelas coordenadas do v&eacute;rtice no canto inferior esquerdo,
     * a dimens&atilde;o horizontal e a dimens&atilde;o vertical.
     * @param _iX Refer&ecirc;ncia para a coordenada X do canto inferior do ret&acirc;ngulo.
     * @param _iY Refer&ecirc;ncia para a coordenada Y do canto inferior do ret&acirc;ngulo.
     * @param _iW Refer&ecirc;ncia para a largura do ret&acirc;ngulo.
     * @param _iH Refer&ecirc;ncia para a altura do ret&acirc;ngulo.
     * @throws NegativeDimensionsException Se o cliente informar valor negativo para as dimensões.
     */ 
    Rect::Rect ( const int _iX,
                 const int _iY,
                 const int _iW,
                 const int _iH ) :
                 miX ( _iX ), miY( _iY ), miW ( _iW ), miH ( _iH )
    { 
        // Testar se recebemos dimensoes negativas.
        if ( miW < 0 )
        {
            miW = 0;
            throw std::invalid_argument ( "[MyRectangle::Rect::Rect()] -> Negative width provided!" );
        }
        if ( miH < 0 )
        {
            miH = 0;
            throw std::invalid_argument ( "[MyRectangle::Rect::Rect()] -> Negative height provided!" );
        }
    }

    //----------------------------------------------------------------------------------------
    //! Construtor c&oacute;pia
    /*! @param _CObj Objeto vetor a ser *clonado*.
    */
    Rect::Rect ( const Rect& _CObj ) :
        miX ( _CObj.miX ), miY( _CObj.miY ), miW ( _CObj.miW ), miH ( _CObj.miH )
    { /* Empty */ }


    //----------------------------------------------------------------------------------------
    //! Destrutor padr&atilde;o: faz nada.
    Rect::~Rect()
    { /* Empty */ }

    //----------------------------------------------------------------------------------------
    //! Atribui novos valores aos campos do ret&acirc;ngulo.
    /*! Atribui novos valores a cada uma das quatro campos que definem o ret&acirc;ngulo.
      @param _iX Novo valor para a coordenada X do canto inferior esquerdo.
      @param _iY Novo valor para a coordenada Y do canto inferior esquerdo.
      @param _iW Novo valor  para a largura.
      @param _iH Novo valor para a altura.
      @throws NegativeDimensionsException Se o cliente informar valor negativo para as dimensões.
      */
    void
    Rect::setData ( const int _iX, const int _iY, const int _iW, const int _iH )
    { 
        // Atribuicoes para os campos correspondentes.
        miX = _iX;
        miY = _iY;
        miW = _iW;
        miH = _iH;

        // Testar se recebemos dimensoes negativas.
        if ( miW < 0 )
        {
            miW = 0;
            throw std::invalid_argument ( "[MyRectangle::Rect::setData()] -> Negative width provided!" );
        }
        if ( miH < 0 )
        {
            miH = 0;
            throw std::invalid_argument ( "[MyRectangle::Rect::setData()] -> Negative height provided!" );
        }
    }



    //----------------------------------------------------------------------------------------
    //! Calcula a &aacute;rea do ret&acirc;ngulo
    /*! @return O valor da &aacute;rea do ret&acirc;ngulo.
    */
    int
    Rect::area( void ) const
    {   return miW * miH;  }



    //----------------------------------------------------------------------------------------
    //! Sobrecarga do operador de atribui&ccedil;&atilde;o.
    /*! @return O vetor a ser atribuito ao lado esquerdo do operador.
    */
    Rect &
    Rect::operator= ( const Rect& rhs )
    {
        // Check for self assign.
        if ( this == &rhs ) return *this;

        // Assigning the new coordinates.
        miX = rhs.miX;
        miY = rhs.miY;
        miW = rhs.miW;
        miH = rhs.miH;

        return *this;
    }

    //----------------------------------------------------------------------------------------
    //! Sobrecarga do operador de indexa&ccedil;&atilde;o, com suporte a atribui&ccedil;&atilde;o (usado como lhs).
    /*! Retorna a coordenada do campo correspondente ao &iacute;ndice passado como par&acirc;metro.
     *  Lembrando que os &iacute;ndices 0, 1, 2 e 3 correspondem, respectivamente, a X, Y, Width e Height
     *  Esse operador em especial suporta atribui&ccedil;&atilde;o.
     *  @throws OutOfBoundsException Se o &iacute;ndice usado estiver fora do intervalo [0,3].
     *  @return A coordenada na posi&ccedil;&atilde;o requisitada.
     */
    int &
    Rect::operator[] ( const int _iIdx )
    {
        // Validate index range.
        // if ( _iIdx < field::X || _iIdx > field::H ) // Works only on C++11
        if ( _iIdx < X || _iIdx > H )
            throw std::out_of_range( "[int& MyRectangle::Rect::operator[]] -> Access index out of range; It must be in [0;3]!" );

        // Return the corresponding coordinate.
        // Note that we must return the member itiself, as they are 
        // references to the private members and can be in an
        // assignment operation as a l-value.
        if ( _iIdx == X )      return miX;
        else if ( _iIdx == Y ) return miY;
        else if ( _iIdx == W ) return miW;
        else                   return miH;
    }

    //----------------------------------------------------------------------------------------
    //! Sobrecarga do operador de indexa&ccedil;&atilde;o sem suporte a atribuit&ccedil;&atilde;o (consuta, ou rhs).
    /*! Retorna a coordenada do vetor correspondente ao &iacute;ndice passado como par&acirc;metro.
     *  Lembrando que os &iacute;ndices 0, 1, 2 e 3 correspondem, respectivamente, a X, Y, Width e Height
     *  @throws OutOfBoundsException Se o &iacute;ndice usado estiver fora do intervalo [0,3].
     *  @return A coordenada na posi&ccedil;&atilde;o requisitada.
     */
    const int &
    Rect::operator[] ( const int _iIdx ) const {
        // Validate index range.
        if ( _iIdx < X || _iIdx > H )
            throw std::out_of_range( "[const int& MyRectangle::Rect::operator[]] -> Access index out of range; It must be in [0;3]!" );

        if ( _iIdx == X )      return miX;
        else if ( _iIdx == Y ) return miY;
        else if ( _iIdx == W ) return miW;
        else                   return miH;

    }


    //-------------------------------------------
    //    Friend methods
    //-------------------------------------------

    //----------------------------------------------------------------------------------------
    //! Sobrecarga do operador relacional de igualdade.
    /*! @return Verdadeiro se os vetores s&atilde;o iguais.
     *  @param _lhs Left hand side term of '==' expression.
     *  @param _rhs Right hand side term of '==' expression.
    */
    bool
    operator== ( const Rect& _lhs, const Rect& _rhs )
    {
        // Compare all the coordinates.
        return ( _lhs.miX == _rhs.miX && _lhs.miY == _rhs.miY && _lhs.miW == _rhs.miW && _lhs.miH == _rhs.miH );
    }

    //----------------------------------------------------------------------------------------
    //! Sobrecarga do operador relacional de desigualdade.
    /*! @return Verdadeiro se os vetores s&atilde;o diferentes (em pelo menos uma coordenada).
     *  @param _lhs Left hand side term of '==' expression.
     *  @param _rhs Right hand side term of '==' expression.
    */
    bool
    operator!= ( const Rect& _lhs, const Rect& _rhs )
    {
        // Compare all the coordinates.
        return ( _lhs.miX != _rhs.miX || _lhs.miY != _rhs.miY || _lhs.miW != _rhs.miW || _lhs.miH != _rhs.miH );
    }



} // namspace rectangle

/* --------------------- [ END OF THE rect.cpp MODULE ] ----------------- */
/* ====================================================================== */
