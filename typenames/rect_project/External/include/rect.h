/*!
 <PRE>
 SOURCE FILE : rect.h
 DESCRIPTION.: This class implements a simple Rectangle whose sides are
               always parallel to the Cartesian axes.
               The rectangle is defined by a 2D point at the lower left
               corner and two lengths, one horizontal and other vertical.
               The data are all integers.
               This class has been designed as a teching example for some
               programming concepts in C++, such as templates and function
               pointer.
 AUTHOR......: Selan R. dos Santos.
 LOCATION....: DIMAp/UFRN.
 SATARTED ON.: February 24th, 2015
 CHANGES.....: No *bug* found so far.

 TO COMPILE..: g++ -c rect.cpp
 OBS.........: Part of the IMD0029/IMD0030 modules.

 LAST UPDATE.: None.
 </pre>
*/

/* ========================================================================= */
/* DEFINITION OF CONSTANTS AND MACROS		                             */
/* ------------------------------------------------------------------------- */

#ifndef RECT_H
#define RECT_H

#include <stdexcept>

/* ========================================================================= */
/* CLASS DECLARATION                                                         */
/* ------------------------------------------------------------------------- */
//! Namespace que engloba as opera&ccedil;&otilde;es e exce&ccedil;&otilde;es relacionadas com ret&acirc;ngulo.
namespace MyRectangle {

    //! Classe que implementa um ret&acirc;ngulo definido pela coordenada do v&eacute;rtice localizado
    //! no canto inferior esquerdo, dimens&atilde;o horizontal e vertical.
    class Rect
    {
        // CONSTRUCTORS AND DESTRUCTORS
        public:
            explicit Rect ( const int _iX=0, const int _iY=0, const int _iW=0, const int _iH=0 );
            Rect ( const Rect& tCObj );
            virtual ~Rect ( void );

        public:
            // ACESSOR methods

            //! Recupera a coordenada X do v&eacute;rtice do ret&acirc;ngulo.
            /*! @return Coordenana X do canto inferior do ret&acirc;ngulo. */
            int getX( void ) const { return miX; };

            //! Recupera a coordenada Y do v&eacute;rtice do ret&acirc;ngulo.
            /*! @return Coordenana Y do canto inferior do ret&acirc;ngulo. */
            int getY( void ) const { return miY; };

            //! Recupera a largura do ret&acirc;ngulo.
            /*! @return Largura do ret&acirc;ngulo. */
            int getWidth( void ) const { return miW; };

            //! Recupera a altura do ret&acirc;ngulo.
            /*! @return Altura do ret&acirc;ngulo. */
            int getHeight( void ) const { return miH; };

            //! Recupera as coordeadas do v&eacute;rtice e dimens&otilde;es (W, H) do ret&acirc;ngulo.
            /*! @param _iX Referência para coordenada X do canto inferior esquerdo. */
            /*! @param _iY Referência para coordenada Y do canto inferior esquerdo. */
            /*! @param _iW Referência para a largura do ret&acirc;ngulo. */
            /*! @param _iH Referência para a altura do ret&acirc;ngulo. */
            void getData( int &_iX, int &_iY, int &_iW, int &_iH ) const
            { _iX = miX; _iY = miY; _iW = miW; _iH = miH; };

            //! Recupera a &aacute;rea do ret&acirc;ngulo.
            /*! @return &Aacute;rea do ret&acirc;ngulo. */
            int area ( void ) const;

            // MUTATORS methods
            void setData( const int _iX, const int _iY, const int _iW, const int _iH );

            // OPERATORS OVERLOADING - These are the only operatos that have to be part of the class.
            Rect& operator= ( const Rect& rhs );
            int& operator[] ( const int tiIdx );
            const int& operator[] ( const int tiIdx ) const;


            // FRIEND METHODS
        public:

            friend bool operator== ( const Rect& lhs, const Rect& rhs );
            friend bool operator!= ( const Rect& lhs, const Rect& rhs );
            //! Sobrecarga do operador <<, que faz com que seja impresso o ret&acirc;ngulo na forma: [ x, y, Width, Height ]
            /*! @param _os Output stream, normalmente o <CODE>cout</code>.
             *  @param _CRec O ret&acirc;ngulo a ser impresso na tela.
             *  @return A pr&oacute;pria <CODE>os</code> recebida como par&acirc;metros (para permitir encadeamento).
             */
            inline friend std::ostream &operator<< (std::ostream& _os, const Rect& _CRec)
            {
                _os << "[x=" << _CRec.miX << ", y=" << _CRec.miY << ", w=" << _CRec.miW << ", h=" << _CRec.miH << " ]";
                return _os;
            }


        private:
            //! Coordenada X do canto inferior esquerdo.
            int miX;
            //! Coordenada Y do canto inferior esquerdo.
            int miY;
            //! Largura do ret&acirc;ngulo.
            int miW;
            //! Altura do ret&acirc;ngulo
            int miH;

        public:
            //! Posi&ccedil;&otilde;es dos campos
            enum field { X=0, Y=1, W=2, H=3 };
    };

} // namespace rectangle

#endif // RECT_H

/* ---------------------- [ End of the rect.h header ] -------------------- */
/* ======================================================================== */
