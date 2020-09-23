/*
                 __________                                      
    _____   __ __\______   \_____  _______  ______  ____ _______ 
   /     \ |  |  \|     ___/\__  \ \_  __ \/  ___/_/ __ \\_  __ \
  |  Y Y  \|  |  /|    |     / __ \_|  | \/\___ \ \  ___/ |  | \/
  |__|_|  /|____/ |____|    (____  /|__|  /____  > \___  >|__|   
        \/                       \/            \/      \/        
  Copyright (C) 2013 Ingo Berg

  Permission is hereby granted, free of charge, to any person obtaining a copy of this 
  software and associated documentation files (the "Software"), to deal in the Software
  without restriction, including without limitation the rights to use, copy, modify, 
  merge, publish, distribute, sublicense, and/or sell copies of the Software, and to 
  permit persons to whom the Software is furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all copies or 
  substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
  NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND 
  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, 
  DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. 
*/ 
  
#ifndef MU_PARSER_BASE_H
#define MU_PARSER_BASE_H
  
//--- Standard includes ------------------------------------------------------------------------
#include <cmath>
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include <locale>
#include <limits.h>
  
//--- Parser includes --------------------------------------------------------------------------
#include "muParserDef.h"
#include "muParserStack.h"
#include "muParserTokenReader.h"
#include "muParserBytecode.h"
#include "muParserError.h"
  
{
  
/** \file
    \brief This file contains the class definition of the muparser engine.
*/ 
    
//--------------------------------------------------------------------------------------------------
/** \brief Mathematical expressions parser (base parser engine).
    \author (C) 2013 Ingo Berg

  This is the implementation of a bytecode based mathematical expressions parser. 
  The formula will be parsed from string and converted into a bytecode. 
  Future calculations will be done with the bytecode instead the formula string
  resulting in a significant performance increase. 
  Complementary to a set of internally implemented functions the parser is able to handle 
  user defined functions and variables. 
*/ 
    class ParserBase 
  {
    
  
    /** \brief Typedef for the parse functions. 
    
      The parse function do the actual work. The parser exchanges
      the function pointer to the parser function depending on 
      which state it is in. (i.e. bytecode parser vs. string parser)
    */ 
    typedef value_type (ParserBase::*ParseFunction) () const;
    
    /** \brief Type used for storing an array of values. */ 
    typedef std::vector < value_type > valbuf_type;
    
    /** \brief Type for a vector of strings. */ 
    typedef std::vector < string_type > stringbuf_type;
    
    /** \brief Typedef for the token reader. */ 
    typedef ParserTokenReader token_reader_type;
    
    /** \brief Type used for parser tokens. */ 
    typedef ParserToken < value_type, string_type > token_type;
    
    /** \brief Maximum number of threads spawned by OpenMP when using the bulk mode. */ 
    static const int s_MaxNumOpenMPThreads = 16;
  
    /** \brief Type of the error class. 
    
      Included for backwards compatibility.
    */ 
    typedef ParserError exception_type;
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    /** \fn void mu::ParserBase::DefineFun(const string_type &a_strName, fun_type0 a_pFun, bool a_bAllowOpt = true) 
        \brief Define a parser function without arguments.
        \param a_strName Name of the function
        \param a_pFun Pointer to the callback function
        \param a_bAllowOpt A flag indicating this function may be optimized
    */ 
    template < typename T > 
                                             T a_pFun, bool a_bAllowOpt =
                                             true) 
    {
      
                    ValidNameChars ());
    
                           
                           0, 
                           oaLEFT, 
    
    
                          const string_type & a_strVal);
    
    
                             bool a_bAllowOpt = true);
    
                           int a_iPrec = prINFIX, bool a_bAllowOpt = true);
    
      // Clear user defined variables, constants or functions
    void ClearVar ();
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
                   (int) mu::string_type::npos,
                   
  
    
    
    
    
    
    
    
    static bool g_DbgDumpCmdCode;
    
    
    /** \brief A facet class used to change decimal and thousands separator. */ 
  template < class TChar > 
      
    {
    
        m_cDecPoint (cDecSep) 
        m_cThousandsSep (cThousandsSep) 
      {
    } 
      {
        
      
       
      {
        
      
       
      {
        
          // fix for issue 4: https://code.google.com/p/muparser/issues/detail?id=4
          // courtesy of Jens Bartsch
          // original code:
          //        return std::string(1, (char)m_nGroup); 
          // new code:
        return std::string (1,
                            (char) (m_cThousandsSep >
                                    0 ? m_nGroup : CHAR_MAX));
    
      
      
    
  
    
    
    
                         
                         
                         
    
                                
    
                        
    
                         
    
                       
                       
    
                                
                                &a_vArg) const;
    
    
    
    
    
    
    
                       const string_type & a_CharSet) const;
    
                     
                     
    
                       
    
    /** \brief Pointer to the parser function. 
    
      Eval() calls the function whose address is stored there.
    */ 
      mutable ParseFunction m_pParseFormula;
    
    mutable stringbuf_type m_vStringBuf;        ///< String buffer, used for storing string function arguments
    stringbuf_type m_vStringVarBuf;
    
    
    funmap_type m_PostOprtDef;  ///< Postfix operator callbacks
    funmap_type m_InfixOprtDef; ///< unary infix operator.
    funmap_type m_OprtDef;      ///< Binary operator callbacks
    valmap_type m_ConstDef;     ///< user constants.
    strmap_type m_StrVarDef;    ///< user defined string constants
    varmap_type m_VarDef;       ///< user defind variables.
    
    
    string_type m_sOprtChars;   ///< Charset for postfix/ binary operator tokens
    string_type m_sInfixOprtChars;      ///< Charset for infix operator tokens
    
    
      // items merely used for caching state information
      mutable valbuf_type m_vStackBuffer;       ///< This is merely a buffer used for the stack in the cmd parsing routine
    mutable int m_nFinalResultIdx;
  



#endif  /* 
  