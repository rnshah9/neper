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
  
  
#include "muParserBytecode.h"
  
#include <algorithm>
#include <cassert>
#include <string>
#include <stack>
#include <vector>
#include <iostream>
  
#include "muParserDef.h"
#include "muParserError.h"
#include "muParserToken.h"
#include "muParserStack.h"
#include "muParserTemplateMagic.h"
  
{
  
    //---------------------------------------------------------------------------
  /** \brief Bytecode default constructor. */ 
ParserByteCode::ParserByteCode () 
  m_iStackPos (0) 
  m_bEnableOptimizer (true) 
  {
    
  
  
    //---------------------------------------------------------------------------
  /** \brief Copy constructor. 
    
      Implemented in Terms of Assign(const ParserByteCode &a_ByteCode)
  */ 
    ParserByteCode::ParserByteCode (const ParserByteCode & a_ByteCode) 
  {
    
  
    //---------------------------------------------------------------------------
  /** \brief Assignment operator.
    
      Implemented in Terms of Assign(const ParserByteCode &a_ByteCode)
  */ 
    ParserByteCode & ParserByteCode::
    operator= (const ParserByteCode & a_ByteCode) 
  {
    
    
  
  
    //---------------------------------------------------------------------------
  void ParserByteCode::EnableOptimizer (bool bStat) 
  {
    
  
    //---------------------------------------------------------------------------
  /** \brief Copy state of another object to this. 
    
      \throw nowthrow
  */ 
  void ParserByteCode::Assign (const ParserByteCode & a_ByteCode) 
  {
    
      
    
    
    
    
  
  
    //---------------------------------------------------------------------------
  /** \brief Add a Variable pointer to bytecode. 
      \param a_pVar Pointer to be added.
      \throw nothrow
  */ 
  void ParserByteCode::AddVar (value_type * a_pVar) 
  {
    
+m_iStackPos;
    
    
      // optimization does not apply
      SToken tok;
    
    
    
    
    
  
    //---------------------------------------------------------------------------
  /** \brief Add a Variable pointer to bytecode. 

      Value entries in byte code consist of:
      <ul>
        <li>value array position of the value</li>
        <li>the operator code according to ParserToken::cmVAL</li>
        <li>the value stored in #mc_iSizeVal number of bytecode entries.</li>
      </ul>

      \param a_pVal Value to be added.
      \throw nothrow
  */ 
  void ParserByteCode::AddVal (value_type a_fVal) 
  {
    
+m_iStackPos;
    
    
      // If optimization does not apply
      SToken tok;
    
    
    
    
    
  
    //---------------------------------------------------------------------------
  void ParserByteCode::ConstantFolding (ECmdCode a_Oprt) 
  {
    
    
      m_vRPN[sz - 1].Val.data2;
    
      
    {
    
      x = (int) x && (int) y;
      m_vRPN.pop_back ();
      break;
    
      x = (int) x || (int) y;
      m_vRPN.pop_back ();
      break;
    
      x = x < y;
      m_vRPN.pop_back ();
      break;
    
      x = x > y;
      m_vRPN.pop_back ();
      break;
    
      x = x <= y;
      m_vRPN.pop_back ();
      break;
    
      x = x >= y;
      m_vRPN.pop_back ();
      break;
    
      x = x != y;
      m_vRPN.pop_back ();
      break;
    
      x = x == y;
      m_vRPN.pop_back ();
      break;
    
      x = x + y;
      m_vRPN.pop_back ();
      break;
    
      x = x - y;
      m_vRPN.pop_back ();
      break;
    
      x = x * y;
      m_vRPN.pop_back ();
      break;
    
      
#if defined(MUP_MATH_EXCEPTIONS)
        if (y == 0)
        
      
#endif  /* 
        
      
      
    
      x = MathImpl < value_type >::Pow (x, y);
      
      
    
      
    
  }
  
    //---------------------------------------------------------------------------
  /** \brief Add an operator identifier to bytecode. 
    
      Operator entries in byte code consist of:
      <ul>
        <li>value array position of the result</li>
        <li>the operator code according to ParserToken::ECmdCode</li>
      </ul>

      \sa  ParserToken::ECmdCode
  */ 
  void ParserByteCode::AddOp (ECmdCode a_Oprt) 
  {
    
    
      
    {
      
      
        // Check for foldable constants like:
        //   cmVAL cmVAL cmADD 
        // where cmADD can stand fopr any binary operator applied to
        // two constant values.
        if (sz >= 2 && m_vRPN[sz - 2].Cmd == cmVAL
            && m_vRPN[sz - 1].Cmd == cmVAL)
        
      {
        
        
      
      
      else
        
      {
        
          
        {
        
          
            // Optimization for polynomials of low order
            if (m_vRPN[sz - 2].Cmd == cmVAR && m_vRPN[sz - 1].Cmd == cmVAL)
            
          {
            
              
            
            else if (m_vRPN[sz - 1].Val.data2 == 3)
              
            
            else if (m_vRPN[sz - 1].Val.data2 == 4)
              
            
            else
              
            
            
          
          
        
        
          
            // Simple optimization based on pattern recognition for a shitload of different
            // bytecode combinations of addition/subtraction
            if ((m_vRPN[sz - 1].Cmd == cmVAR && m_vRPN[sz - 2].Cmd == cmVAL)
                || 
                     && m_vRPN[sz - 2].Cmd == cmVAR)
                || 
                     && m_vRPN[sz - 2].Cmd == cmVARMUL)
                || 
                     && m_vRPN[sz - 2].Cmd == cmVAL)
                || 
                     && m_vRPN[sz - 2].Cmd == cmVAR
                     && m_vRPN[sz - 2].Val.ptr == m_vRPN[sz - 1].Val.ptr)
                || 
                     && m_vRPN[sz - 2].Cmd == cmVARMUL
                     && m_vRPN[sz - 2].Val.ptr == m_vRPN[sz - 1].Val.ptr)
                || 
                     && m_vRPN[sz - 2].Cmd == cmVAR
                     && m_vRPN[sz - 2].Val.ptr == m_vRPN[sz - 1].Val.ptr)
                || 
                     && m_vRPN[sz - 2].Cmd == cmVARMUL
                     && m_vRPN[sz - 2].Val.ptr == m_vRPN[sz - 1].Val.ptr))
            
          {
            
                      && m_vRPN[sz - 1].Val.ptr != NULL)
                     || 
                          && m_vRPN[sz - 1].Val.ptr == NULL)
                     || 
            
            
            m_vRPN[sz - 2].Val.data2 += ((a_Oprt == cmSUB) ? -1 : 1) * m_vRPN[sz - 1].Val.data2;        // offset
            m_vRPN[sz - 2].Val.data += ((a_Oprt == cmSUB) ? -1 : 1) * m_vRPN[sz - 1].Val.data;  // multiplicand
            m_vRPN.pop_back ();
            
          
          
        
          
               || 
                    && m_vRPN[sz - 2].Cmd == cmVAR))
            
          {
            
            
              (value_type *) ((long long) (m_vRPN[sz - 2].Val.ptr) |
                              (long long) (m_vRPN[sz - 1].Val.ptr));
            
              m_vRPN[sz - 2].Val.data2 + m_vRPN[sz - 1].Val.data2;
            
            
            
          
          
          else
            if ((m_vRPN[sz - 1].Cmd == cmVAL
                 && m_vRPN[sz - 2].Cmd == cmVARMUL)
                || 
                     && m_vRPN[sz - 2].Cmd == cmVAL))
            
          {
            
              // Optimization: 2*(3*b+1) or (3*b+1)*2 -> 6*b+2
              m_vRPN[sz - 2].Cmd = cmVARMUL;
            
              (value_type *) ((long long) (m_vRPN[sz - 2].Val.ptr) |
                              (long long) (m_vRPN[sz - 1].Val.ptr));
            
              
            {
              
              
            
            
            else
              
            {
              
                m_vRPN[sz - 1].Val.data * m_vRPN[sz - 2].Val.data2;
              
                m_vRPN[sz - 1].Val.data2 * m_vRPN[sz - 2].Val.data2;
            
            
            
          
          
          else if (m_vRPN[sz - 1].Cmd == cmVAR && m_vRPN[sz - 2].Cmd == cmVAR
                   && 
            
          {
            
              // Optimization: a*a -> a^2
              m_vRPN[sz - 2].Cmd = cmVARPOW2;
            
            
          
          
        
          
               && m_vRPN[sz - 1].Val.data2 != 0)
            
          {
            
              // Optimization: 4*a/2 -> 2*a
              m_vRPN[sz - 2].Val.data /= m_vRPN[sz - 1].Val.data2;
            
            
            
          
          
        
      }
    
    
      // If optimization can't be applied just write the value
      if (!bOptimized)
      
    {
      
      
      
      
    
  
  
    //---------------------------------------------------------------------------
  void ParserByteCode::AddIfElse (ECmdCode a_Oprt) 
  {
    
    
    
  
    //---------------------------------------------------------------------------
  /** \brief Add an assignment operator
    
      Operator entries in byte code consist of:
      <ul>
        <li>cmASSIGN code</li>
        <li>the pointer of the destination variable</li>
      </ul>

      \sa  ParserToken::ECmdCode
  */ 
  void ParserByteCode::AddAssignOp (value_type * a_pVar) 
  {
    
    
    
    
    
  
    //---------------------------------------------------------------------------
  /** \brief Add function to bytecode. 

      \param a_iArgc Number of arguments, negative numbers indicate multiarg functions.
      \param a_pFun Pointer to function callback.
  */ 
  void ParserByteCode::AddFun (generic_fun_type a_pFun, int a_iArgc) 
  {
    
      
    {
      
    
    
    else
      
    {
      
        // function with unlimited number of arguments
        m_iStackPos = m_iStackPos + a_iArgc + 1;
    
    
    
    
    
    
    
  
  
    //---------------------------------------------------------------------------
  /** \brief Add a bulk function to bytecode. 

      \param a_iArgc Number of arguments, negative numbers indicate multiarg functions.
      \param a_pFun Pointer to function callback.
  */ 
  void ParserByteCode::AddBulkFun (generic_fun_type a_pFun, int a_iArgc) 
  {
    
    
    
    
    
    
    
  
    //---------------------------------------------------------------------------
  /** \brief Add Strung function entry to the parser bytecode. 
      \throw nothrow

      A string function entry consists of the stack position of the return value,
      followed by a cmSTRFUNC code, the function pointer and an index into the 
      string buffer maintained by the parser.
  */ 
  void ParserByteCode::AddStrFun (generic_fun_type a_pFun, int a_iArgc,
                                  int a_iIdx) 
  {
    
    
    
    
    
    
    
    
  
    //---------------------------------------------------------------------------
  /** \brief Add end marker to bytecode.
      
      \throw nothrow 
  */ 
  void ParserByteCode::Finalize () 
  {
    
    
    
    
    
      // Determine the if-then-else jump offsets
    ParserStack < int >stIf, stElse;
    
    
      
    {
      
        
      {
      
        
        
      
        
        
        
        
      
        
        
        
      
        
      
    
  
  
    //---------------------------------------------------------------------------
  const SToken *ParserByteCode::GetBase () const 
  {
    
      
    
    else
      
  
   
    //---------------------------------------------------------------------------
    std::size_t ParserByteCode::GetMaxStackSize () const 
  {
    
  
   
    //---------------------------------------------------------------------------
  /** \brief Returns the number of entries in the bytecode. */ 
    std::size_t ParserByteCode::GetSize () const 
  {
    
  
   
    //---------------------------------------------------------------------------
  /** \brief Delete the bytecode. 
  
      \throw nothrow

      The name of this function is a violation of my own coding guidelines
      but this way it's more in line with the STL functions thus more 
      intuitive.
  */ 
  void ParserByteCode::clear () 
  {
    
    
    
  
    //---------------------------------------------------------------------------
  /** \brief Dump bytecode (for debugging only!). */ 
  void ParserByteCode::AsciiDump () 
  {
    
      
    {
      
      
    
    
      size () << _T ("\n");
    
          ++i)
      
    {
      
      
        
      {
      
        mu::console () << _T ("VAL \t");
        
        
      
        mu::console () << _T ("VAR \t");
        
          ptr << _T ("]\n");
        
      
        mu::console () << _T ("VARPOW2 \t");
        
          ptr << _T ("]\n");
        
      
        mu::console () << _T ("VARPOW3 \t");
        
          ptr << _T ("]\n");
        
      
        mu::console () << _T ("VARPOW4 \t");
        
          ptr << _T ("]\n");
        
      
        mu::console () << _T ("VARMUL \t");
        
          ptr << _T ("]");
        
        
        
      
        mu::console () << _T ("CALL\t");
        
          argc << _T ("]");
        
          ptr << _T ("]");
        
        
      
        
        
          argc << _T ("]");
        
          idx << _T ("]");
        
          ptr << _T ("]\n");
        
      
        mu::console () << _T ("LT\n");
        break;
      
        mu::console () << _T ("GT\n");
        break;
      
        mu::console () << _T ("LE\n");
        break;
      
        mu::console () << _T ("GE\n");
        break;
      
        mu::console () << _T ("EQ\n");
        break;
      
        mu::console () << _T ("NEQ\n");
        break;
      
        mu::console () << _T ("ADD\n");
        break;
      
        mu::console () << _T ("&&\n");
        break;
      
        mu::console () << _T ("||\n");
        break;
      
        mu::console () << _T ("SUB\n");
        break;
      
        mu::console () << _T ("MUL\n");
        break;
      
        mu::console () << _T ("DIV\n");
        break;
      
        mu::console () << _T ("POW\n");
        break;
      
        mu::console () << _T ("IF\t");
        
          offset << _T ("]\n");
        
      
        mu::console () << _T ("ELSE\t");
        
          offset << _T ("]\n");
        
      
        mu::console () << _T ("ENDIF\n");
        break;
      
        
        
          ptr << _T ("]\n");
        
      
        mu::console () << _T ("(unknown code: ") << m_vRPN[i].
          Cmd << _T (")\n");
        
      
    }                           // while bytecode
    
  
