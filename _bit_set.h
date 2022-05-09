
#ifndef __BIT_SET_H__
#define __BIT_SET_H__

#include "_include_all.h"

#define _getPP(PP, ...)             PP
#define _getP1(P1, ...)             _getPP(P1)
#define _getP2(P2, ...)             _getPP(__VA_ARGS__)
#define _Port( xxx )                _getP1(xxx)
#define _Pin( yyy )                 _getP2(yyy)

#define _CONCAT3(A,B,C)   A##B##C
#define _CONCAT2(A,B)     A##B



#define _Pdir_(ddd)     _CONCAT3(P,ddd,DIR)
#define _PdirT(pdpd)    _Pdir_(pdpd##_PORT_)
#define _PdirX(pp)      _Pdir_(_Port(pp))

#define _Pren_(ddd)     _CONCAT3(P,ddd,REN)
#define _PrenT(pdpd)    _Pren_(pdpd##_PORT_)
#define _PrenX(pp)      _Pren_(_Port(pp))

#define _Pout_(ddd)     _CONCAT3(P,ddd,OUT)
#define _PoutT(popo)    _Pout_(popo##_PORT_)
#define _PoutX(pp)      _Pout_(_Port(pp))

#define _Pin_(ddd)      _CONCAT3(P,ddd,IN)
#define _PinT(pipi)     _Pin_(pipi##_PORT_)
#define _PinX(pp)       _Pin_(_Pin(pp))

#define _Bbit_(bb)      _CONCAT2(BIT,bb)
#define _BbitT(bt)      _Bbit_(bt##_PIN_)
#define _BbitX(pp)      _Bbit_(_Pin(pp))

#define _Pres_(ddd)     _CONCAT3(P,ddd,REN)
#define _PresT(pdpd)    _Pres_(pdpd##_PORT_)
#define _PresX(pp)      _Pres_(_Port(pp))


// P1DIR |= BIT3 // P1.3 -> as Output
// P1OUT |= BIT3 // P1.3 -> bit output register set to 1
// P1IN & BIT3   // read P1.3's value( if input)


#define _Set1X(port,pin)             { P ## port ## OUT    |=     BIT ## pin   ; }
#define _Set0X(port,pin)             { P ## port ## OUT    &= ( ~ BIT ## pin ) ; }
//#define _Set1Y(...)                  _Set1X( __VA_ARGS__ )
//#define _Set0Y(...)                  _Set0X( __VA_ARGS__ )

#define _SetInX(p1,b1)              { P ## p1 ## DIR    &= ( ~ BIT ## b1 ) ; }
#define _SetOutX(p1,b1)             { P ## p1 ## DIR    |=     BIT ## b1   ; }
//#define _SetInY(...)                _SetInX( __VA_ARGS__ )
//#define _SetOutY(...)               _SetOutX( __VA_ARGS__ )

#define _SetRenOnX(p1,b1)           { P ## p1 ## REN    |=     BIT ## b1   ; }
#define _SetRenOffX(p1,b1)          { P ## p1 ## REN    &= ( ~ BIT ## b1 ) ; }
//#define _SetRenOnY(...)             _SetRenOnX( __VA_ARGS__ )
//#define _SetRenOffY(...)            _SetRenOffX( __VA_ARGS__ )

#define _PinitAsInOffOut0X(p1,b1)   { _SetRenOffX(p1,b1); _SetInX(p1,b1); _Set0X(p1,b1); }
#define _PinitAsInOffOut1X(p1,b1)   { _SetRenOffX(p1,b1); _SetInX(p1,b1); _Set1X(p1,b1); }
//#define _PinitAsInOffOut0Y(a1,b1)    _PinitAsInOffOut0X( a1,b1)
#define _PinitAsInOffOut0Y(...)    _PinitAsInOffOut0X( _XX(__VA_ARGS__))
//#define _PinitAsInOffOut1Y(...)     _PinitAsInOffOut1X( __VA_ARGS__ )

#define _ZZZ
#define _XX20( ff , ...) 
//#define _XX21( ff , aa, bb, ...) { ff ( aa, bb ) ; _XX20( ff, __VA_ARGS__ ) ; }
#define _XX21( ff , aa, bb, ...) { ff ( aa, bb ) ; _XX20( ff, _XX(__VA_ARGS__) ) ; }
#define _XX21x( ...) _XX21( _XX( __VA_ARGS__ ) )
#define _XX22( ff , aa, bb, ...) { ff( aa, bb ) ; _XX21( ff, __VA_ARGS__ ) ; }
#define _XX23( ff , aa, bb, ...) { ff( aa, bb ) ; _XX22( ff, __VA_ARGS__ ) ; }
#define _XX24( ff , aa, bb, ...) { ff( aa, bb ) ; _XX23( ff, __VA_ARGS__ ) ; }
#define _XX25( ff , aa, bb, ...) { ff( aa, bb ) ; _XX24( ff, __VA_ARGS__ ) ; }
#define _XX2( ffff, ...) ffff( __VA_ARGS__ )
#define _XX( ...) __VA_ARGS__ 

#define _X2( ff, a11, a12, a21, a22 ) { ff( a11, a12 ) ; ff( a21, a22 ) }
#define _Y2( ff, ... ) _X2( ff , __VA_ARGS__ )

//#define _READbitX(ppp)          ( (P ## p1 ## IN)   &  (BIT ## b1)       )
//#define _SetOut0X(ppp)          { _SetOutX( ppp ); _Set0X( ppp ); }
////#define _SetOut0Y(ppp,...)      { _SetOutX(ppp);   _SetOut0Y( __VA_ARGS__ ); }
////#define _SetOut0Z(p1,p2,...)    { _SetOutX(p1,p2); }
////#define _SetOut0Y(p1,p2,...) { _SetOutX(p1,p2);   _SetOut0Y( __VA_ARGS__ ); }
//#define _SetOut0Y(p1,p2,...) { _SetOutX(p1,p2);   }
//#define _SetOut0Z(p1,...)    { _SetOut0Y(p1); _SetOut0Z(__VA_ARGS__);    }
////#define led_10_init()           { _PinInAsOffInitOut0(led_10); }
//
////#define _PinInitAsInOffOut0x(cnt,func,...)  { _SetRENoff_(ppp); _SetIN_(ppp); _Set0_(ppp); }
//#define _PinInitAsInOffOut0x(cnt,func,...)  { _SetRENoff_(ppp); _SetIN_(ppp); _Set0_(ppp); }




#define _SetIN(name)  { name##_dir &= ( ~ name##_bit ) ; }
#define _SetOUT(name) { name##_dir |=     name##_bit   ; }
#define _Set0(name)   { name##_out &= ( ~ name##_bit ) ; }
#define _Set1(name)   { name##_out |=     name##_bit   ; }

#define _SetIN_(name)  { _PdirT(name) &= ( ~ _BbitT(name) ) ; }
#define _SetOUT_(name) { _PdirT(name) |=     _BbitT(name)   ; }

#define _SetRENon_(name)  { _PrenT(name) |=     _BbitT(name)   ; }
#define _SetRENoff_(name) { _PrenT(name) &= ( ~ _BbitT(name) ) ; }

#define _PinInAsOffInitOut0(name)  { _SetRENoff_(name); _SetIN_(name); _Set0_(name); }
#define _PinInAsOffInitOut1(name)  { _SetRENoff_(name); _SetIN_(name); _Set1_(name); }

#define _Set0_(name)   { _PoutT(name) &= ( ~ _BbitT(name) ) ; }
#define _Set1_(name)   { _PoutT(name) |=     _BbitT(name)   ; }

#define _READbit_(name) (_PinT(name) & _BbitT(name))

#define _SetIN_pullUP(name)     _SetIN_( name ) ; _SetRENon_(name); _Set1_(name);
#define _SetIN_pullDOWN(name)   _SetIN_( name ) ; _SetRENon_(name); _Set0_(name);


uint8_t _bit_count(uint8_t ___byte);
uint8_t _bit_set(uint8_t ___byte);
void _byte_set(uint8_t ___cnt, uint8_t ___arr[] , uint8_t ___byte);
uint8_t _byte_cmp(uint8_t ___cnt, uint8_t ___arr1[], uint8_t ___arr2[]);

void _bit_and(uint8_t ___cnt, uint8_t ___A[], uint8_t ___B[], uint8_t ___O[] );
void _bit_or(uint8_t  ___cnt, uint8_t ___A[], uint8_t ___B[], uint8_t ___O[] );
void _bit_xor(uint8_t ___cnt, uint8_t ___A[], uint8_t ___B[], uint8_t ___O[] );
void _bit_inv(uint8_t ___cnt, uint8_t ___A[], uint8_t ___O[] );

#endif
