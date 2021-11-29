#ifndef CALC_H
#define CALC_H

enum ERROR {
    NEOK = 0,
    OK   = 1
};

//-----------------------------------
//!
//! Finds a number in the string
//! 
//! @return a number
//!
//! @note: 0 priority
//!
//-----------------------------------

int getN();

//-----------------------------------
//!
//! Finds an expression in brackets
//!
//! @return result of expression
//!
//! @note: 1 priority
//!
//-----------------------------------

int getP();

//-----------------------------------
//!
//! Processes multiplying and 
//! division
//!
//! @return result of operation
//!
//! @note: 2 priority
//!
//-----------------------------------

int getT();

//-----------------------------------
//!
//! Processes addition and
//! subsctraction
//! 
//! @return result of operation
//!
//! @note: 3 priority
//!
//-----------------------------------

int getE();

//-----------------------------------
//!
//! Processes all expression
//!
//! @return result of expression
//! 
//! @note: 4 priority
//!
//----------------------------------

int getG();

//----------------------------------
//!
//! Prints error
//! 
//----------------------------------

void syntaxError();

//----------------------------------
//!
//! Checks if the func comes across
//! expecting symbol
//!
//! @param[in] symb - symb to check
//!
//! @return if symb was founded 
//!         or not
//!
//----------------------------------

enum ERROR required(char symb);


#endif // CALC_H
