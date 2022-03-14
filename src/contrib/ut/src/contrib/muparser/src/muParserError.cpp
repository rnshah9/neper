/*
                 __________                                      
    _____   __ __\______   \_____  _______  ______  ____ _______ 
   /     \ |  |  \|     ___/\__  \ \_  __ \/  ___/_/ __ \\_  __ \
  |  Y Y  \|  |  /|    |     / __ \_|  | \/\___ \ \  ___/ |  | \/
  |__|_|  /|____/ |____|    (____  /|__|  /____  > \___  >|__|   
        \/                       \/            \/      \/        
  Copyright (C) 2011 Ingo Berg

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
  
#include "muParserError.h"
  
{
  
  
    //------------------------------------------------------------------------------
  const ParserErrorMsg & ParserErrorMsg::Instance () 
  {
    
  
  
    //------------------------------------------------------------------------------
  string_type ParserErrorMsg::operator[](unsigned a_iIdx) const 
  {
    
  
   
    //---------------------------------------------------------------------------
    ParserErrorMsg::~ParserErrorMsg () 
  {
  }
  
    //---------------------------------------------------------------------------
  /** \brief Assignement operator is deactivated.
  */ 
    ParserErrorMsg & ParserErrorMsg::operator= (const ParserErrorMsg &) 
  {
    
    
  
  
    //---------------------------------------------------------------------------
    ParserErrorMsg::ParserErrorMsg (const ParserErrorMsg &) 
  {
  } 
    //---------------------------------------------------------------------------
ParserErrorMsg::ParserErrorMsg () 
  {
    
    
      _T ("Unexpected token \"$TOK$\" found at position $POS$.");
    
    
      _T ("Invalid function-, variable- or constant name: \"$TOK$\".");
    
      _T ("Invalid binary operator identifier: \"$TOK$\".");
    
      _T ("Invalid infix operator identifier: \"$TOK$\".");
    
      _T ("Invalid postfix operator identifier: \"$TOK$\".");
    
      _T ("Invalid pointer to callback function.");
    
    
    
      _T ("Unexpected operator \"$TOK$\" found at position $POS$");
    
      _T ("Unexpected end of expression at position $POS$");
    
      _T ("Unexpected argument separator at position $POS$");
    
      _T ("Unexpected parenthesis \"$TOK$\" at position $POS$");
    
      _T ("Unexpected function \"$TOK$\" at position $POS$");
    
      _T ("Unexpected value \"$TOK$\" found at position $POS$");
    
      _T ("Unexpected variable \"$TOK$\" found at position $POS$");
    
      _T ("Function arguments used without a function (position: $POS$)");
    
    
      _T
      ("Too many parameters for function \"$TOK$\" at expression position $POS$");
    
      _T
      ("Too few parameters for function \"$TOK$\" at expression position $POS$");
    
    
    
    
      _T
      ("Invalid value for operator priority (must be greater or equal to zero).");
    
      _T
      ("user defined binary operator \"$TOK$\" conflicts with a built in operator.");
    
      _T ("Unexpected string token found at position $POS$.");
    
      _T ("Unterminated string starting at position $POS$.");
    
      _T ("String function called with a non string type of argument.");
    
      _T ("String value used where a numerical argument is expected.");
    
      _T ("No suitable overload for operator \"$TOK$\" at position $POS$.");
    
    
    
      _T ("Decimal separator is identic to function argument separator.");
    
      _T ("The \"$TOK$\" operator must be preceeded by a closing bracket.");
    
      _T ("If-then-else operator is missing an else clause");
    
    
      _T
      ("Number of computations to small for bulk mode. (Vectorisation overhead too costly)");
    
#if defined(_DEBUG)
      for (int i = 0; i < ecCOUNT; ++i)
      
        
    
#endif  /* 
  }
  
    //---------------------------------------------------------------------------
    //
    //  ParserError class
    //
    //---------------------------------------------------------------------------
    
  /** \brief Default constructor. */ 
ParserError::ParserError () 
  m_strMsg () 
  m_iErrc (ecUNDEFINED) 
  {
  
  
    //------------------------------------------------------------------------------
  /** \brief This Constructor is used for internal exceptions only. 
      
    It does not contain any information but the error code.
  */ 
ParserError::ParserError (EErrorCodes a_iErrc) 
  m_strMsg () 
  m_iErrc (a_iErrc) 
  {
    
    
    
    
    
  
    //------------------------------------------------------------------------------
  /** \brief Construct an error from a message text. */ 
  ParserError::
    ParserError (const string_type & sMsg) 
                                                       Instance ()) 
  {
    
    
  
    //------------------------------------------------------------------------------
  /** \brief Construct an error object. 
      \param [in] a_iErrc the error code.
      \param [in] sTok The token string related to this error.
      \param [in] sExpr The expression related to the error.
      \param [in] a_iPos the position in the expression where the error occurred. 
  */ 
  ParserError::ParserError (EErrorCodes iErrc, 
                              
                              
    m_strFormula (sExpr) 
    m_iErrc (iErrc) 
  {
    
    
    
    
    
  
    //------------------------------------------------------------------------------
  /** \brief Construct an error object. 
      \param [in] iErrc the error code.
      \param [in] iPos the position in the expression where the error occurred. 
      \param [in] sTok The token string related to this error.
  */ 
  ParserError::ParserError (EErrorCodes iErrc, int iPos,
                              const string_type & sTok) 
    m_strFormula () 
    m_ErrMsg (ParserErrorMsg::Instance ()) 
  {
    
    
    
    
    
  
    //------------------------------------------------------------------------------
  /** \brief Construct an error object. 
      \param [in] szMsg The error message text.
      \param [in] iPos the position related to the error.
      \param [in] sTok The token string related to this error.
  */ 
  ParserError::ParserError (const char_type * szMsg, int iPos,
                              const string_type & sTok) 
    m_strFormula () 
    m_iErrc (ecGENERIC) 
  {
    
    
    
    
  
    //------------------------------------------------------------------------------
  /** \brief Copy constructor. */ 
  ParserError::ParserError (const ParserError & a_Obj) 
                                                                   m_strMsg)
    
    m_iPos (a_Obj.m_iPos) 
    m_ErrMsg (ParserErrorMsg::Instance ()) 
  {
  
    //------------------------------------------------------------------------------
  /** \brief Assignment operator. */ 
    ParserError & ParserError::operator= (const ParserError & a_Obj) 
  {
    
      
    
    
    
    
    
    
  
  
    //------------------------------------------------------------------------------
    ParserError::~ParserError () 
  {
  }
  
    //------------------------------------------------------------------------------
  /** \brief Replace all occurrences of a substring with another string. 
      \param strFind The string that shall be replaced.
      \param strReplaceWith The string that should be inserted instead of strFind
  */ 
  void ParserError::ReplaceSubString (string_type & strSource,
                                      
                                      
  {
    
    
    
      
    {
      
      
      
        
      
      
    
    
  
  
    //------------------------------------------------------------------------------
  /** \brief Reset the erro object. */ 
  void ParserError::Reset () 
  {
    
    
    
    
    
  
    //------------------------------------------------------------------------------
  /** \brief Set the expression related to this error. */ 
  void ParserError::SetFormula (const string_type & a_strFormula) 
  {
    
  
    //------------------------------------------------------------------------------
  /** \brief gets the expression related tp this error.*/ 
  const string_type & ParserError::GetExpr () const 
  {
    
  
   
    //------------------------------------------------------------------------------
  /** \brief Returns the message string for this error. */ 
  const string_type & ParserError::GetMsg () const 
  {
    
  
   
    //------------------------------------------------------------------------------
  /** \brief Return the formula position related to the error. 

    If the error is not related to a distinct position this will return -1
  */ 
  int ParserError::GetPos () const 
  {
    
  
   
    //------------------------------------------------------------------------------
  /** \brief Return string related with this token (if available). */ 
  const string_type & ParserError::GetToken () const 
  {
    
  
   
    //------------------------------------------------------------------------------
  /** \brief Return the error code. */ 
    EErrorCodes ParserError::GetCode () const 
  {
    
  
 