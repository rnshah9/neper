//---------------------------------------------------------------------------
//
//                 __________                                      
//    _____   __ __\______   \_____  _______  ______  ____ _______ 
//   /     \ |  |  \|     ___/\__  \ \_  __ \/  ___/_/ __ \\_  __ \ 
//  |  Y Y  \|  |  /|    |     / __ \_|  | \/\___ \ \  ___/ |  | \/
//  |__|_|  /|____/ |____|    (____  /|__|  /____  > \___  >|__|   
//        \/                       \/            \/      \/        
//  (C) 2015 Ingo Berg
//
//  example1.cpp - using the parser as a static library
//
//---------------------------------------------------------------------------

#include "muParserTest.h"
  
#if defined(_WIN32) && defined(_DEBUG)
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define CREATE_LEAKAGE_REPORT
#endif  /* 
  
#if defined( USINGDLL ) && defined( _WIN32 )
#error This sample can be used only with STATIC builds of muParser (on win32)
#endif  /* 
  
/** \brief This macro will enable mathematical constants like M_PI. */ 
#define _USE_MATH_DEFINES		
  
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <locale>
#include <limits>
#include <ios> 
#include <iomanip>
#include <numeric>
  
#include "muParser.h"
  


#if defined(CREATE_LEAKAGE_REPORT)
  
// Dumping memory leaks in the destructor of the static guard
// guarantees i won't get false positives from the ParserErrorMsg 
// class wich is a singleton with a static instance.
struct DumpLeaks 
{
  
  {
    


#endif  /* 
  
// Forward declarations
void CalcBulk ();

// Operator callback functions
  value_type Mega (value_type a_fVal)
{
  return a_fVal * 1e6;
}


{
  return a_fVal / (value_type) 1e3;
}


{
  return v * std::rand () / (value_type) (RAND_MAX + 1.0);
}


{
  return v == 0;
}


{
  return v1 + v2;
}


{
  return v1 * v2;
}


//---------------------------------------------------------------------------
  value_type ThrowAnException (value_type) 
{
  



//---------------------------------------------------------------------------
  value_type BulkFun1 (int nBulkIdx, int nThreadIdx, value_type v1) 
{
  
    // Note: I'm just doing something with all three parameters to shut 
    // compiler warnings up!
    return nBulkIdx + nThreadIdx + v1;



//---------------------------------------------------------------------------
  value_type Ping () 
{
  
  



//---------------------------------------------------------------------------
  value_type StrFun0 (const char_type * szMsg) 
{
  
    
  



//---------------------------------------------------------------------------
  value_type StrFun2 (const char_type * v1, value_type v2, value_type v3) 
{
  
  



//---------------------------------------------------------------------------
  value_type Debug (mu::value_type v1, mu::value_type v2) 
{
  
  
    console () << _T ("Bytecode dumping ") << ((v1 != 0) ? _T ("active") :
                                               _T ("inactive")) << _T ("\n");
  



//---------------------------------------------------------------------------
// Factory function for creating new parser variables
// This could as well be a function performing database queries.
  value_type * AddVariable (const char_type * a_szName, void *a_pUserData) 
{
  
    // I don't want dynamic allocation here, so i used this static buffer
    // If you want dynamic allocation you must allocate all variables dynamically
    // in order to delete them later on. Or you find other ways to keep track of 
    // variables that have been created implicitely.
  static value_type afValBuf[100];
  
  
+iVal;
  
    <<a_szName << std::dec << _T ("\" (slots left: ") 
    <<99 - iVal << _T (")") 
    <<_T (" User data pointer is:") 
  
  
    
  
  else
    



IsHexValue (const char_type * a_szExpr, int *a_iPos, value_type * a_fVal) 
{
  
    
  
  
    // New code based on streams for UNICODE compliance:
    stringstream_type::pos_type nPos (0);
  
  
  
  
    
  
  
  



//---------------------------------------------------------------------------
  void
Splash () 
{
  
    console () <<
    _T
    ("                 __________                                       \n");
  
    console () <<
    _T
    ("    _____   __ __\\______   \\_____  _______  ______  ____ _______\n");
  
    console () <<
    _T
    ("   /     \\ |  |  \\|     ___/\\__  \\ \\_  __ \\/  ___/_/ __ \\\\_  __ \\ \n");
  
    console () <<
    _T
    ("  |  Y Y  \\|  |  /|    |     / __ \\_|  | \\/\\___ \\ \\  ___/ |  | \\/ \n");
  
    console () <<
    _T
    ("  |__|_|  /|____/ |____|    (____  /|__|  /____  > \\___  >|__|    \n");
  
    console () <<
    _T
    ("        \\/                       \\/            \\/      \\/         \n");
  
    GetVersion (pviFULL) << _T ("\n");
  


//---------------------------------------------------------------------------
  value_type SelfTest () 
{
  
    console () <<
    _T ("-----------------------------------------------------------\n");
  
  
    // Skip the self test if the value type is set to an integer type.
    if (mu::TypeInfo < mu::value_type >::IsInteger ())
    
  {
    
      console () <<
      _T
      ("  Test skipped: integer data type are not compatible with the unit test!\n\n");
  
  
  else
    
  {
    
    
  
  



//---------------------------------------------------------------------------
  value_type Help () 
{
  
    console () <<
    _T ("-----------------------------------------------------------\n");
  
  
  
  
    console () << _T ("  list const   - list all numeric parser constants\n");
  
  
  
  
  
  
  
  
  
  
  
    console () <<
    _T ("-----------------------------------------------------------\n");
  



//---------------------------------------------------------------------------
/*
void CheckLocale()
{
  // Local names:
  // "C" - the classic C locale
  // "de_DE" - not for Windows?
  // "en_US" - not for Windows?
  // "German_germany" - For MSVC8
  try
  {
    std::locale loc("German_germany");
    console() << _T("Locale settings:\n");
    console() << _T("  Decimal point:  '") << std::use_facet<numpunct<char_type> >(loc).decimal_point() << _T("'\n"); 
    console() << _T("  Thousands sep:  '") << std::use_facet<numpunct<char_type> >(loc).thousands_sep() << _T("'\n"); 
    console() << _T("  Grouping:       '") << std::use_facet<numpunct<char_type> >(loc).grouping()  << _T("'\n"); 
    console() << _T("  True is named:  '") << std::use_facet<numpunct<char_type> >(loc).truename()  << _T("'\n"); 
    console() << _T("  False is named: '") << std::use_facet<numpunct<char_type> >(loc).falsename() << _T("'\n"); 
    console() << _T("-----------------------------------------------------------\n");
  }
  catch(...)
  {
    console() << _T("Locale settings:\n");
    console() << _T("  invalid locale name\n");
    console() << _T("-----------------------------------------------------------\n");
  }
}

//---------------------------------------------------------------------------
void CheckDiff()
{
  mu::Parser  parser;
  value_type x = 1, 
             v1,
             v2,
             v3,
             eps(pow(std::numeric_limits<value_type>::epsilon(), 0.2));
  parser.DefineVar(_T("x"), &x);
  parser.SetExpr(_T("_e^-x*sin(x)"));
  
  v1 = parser.Diff(&x, 1),
  v2 = parser.Diff(&x, 1, eps);
  v3 = cos((value_type)1.0)/exp((value_type)1) - sin((value_type)1.0)/exp((value_type)1); //-0.110793765307;
  mu::console() << parser.GetExpr() << _T("\n");
  mu::console() << _T("v1 = ") << v1 << _T("; v1-v3 = ") << v1-v3 << _T("\n");
  mu::console() << _T("v2 = ") << v2 << _T("; v2-v3 = ") << v2-v3 << _T("\n");
}
*/ 
  
//---------------------------------------------------------------------------
  void
ListVar (const mu::ParserBase & parser) 
{
  
    // Query the used variables (must be done after calc)
    mu::varmap_type variables = parser.GetVar ();
  
    
  
  
  
  
  
    
      first << _T ("   Address: [0x") << item->second << _T ("]\n");



//---------------------------------------------------------------------------
  void
ListConst (const mu::ParserBase & parser) 
{
  
  
  
  
    
  {
    
  
  
  else
    
  {
    
    
      
        second << _T ("\n");
  



//---------------------------------------------------------------------------
  void
ListExprVar (const mu::ParserBase & parser) 
{
  
  
    
  {
    
    
  
  
    // Query the used variables (must be done after calc)
    mu::console () << _T ("\nExpression variables:\n");
  
  
  
  
    
  {
    
  
  
  else
    
  {
    
      size () << _T ("\n");
    
    
      
        first << _T ("   Address: [0x") << item->second << _T ("]\n");
  



//---------------------------------------------------------------------------
/** \brief Check for external keywords.
*/ 
  int
CheckKeywords (const mu::char_type * a_szLine, mu::Parser & a_Parser) 
{
  
  
    
  {
    
  
  
  else if (sLine == _T ("list var"))
    
  {
    
    
  
  
  else if (sLine == _T ("opt on"))
    
  {
    
    
    
  
  
  else if (sLine == _T ("opt off"))
    
  {
    
    
    
  
  
  else if (sLine == _T ("list const"))
    
  {
    
    
  
  
  else if (sLine == _T ("list exprvar"))
    
  {
    
    
  
  
  else if (sLine == _T ("locale de"))
    
  {
    
      console () <<
      _T ("Setting german locale: ArgSep=';' DecSep=',' ThousandsSep='.'\n");
    
    
    
    
  
  
  else if (sLine == _T ("locale en"))
    
  {
    
      console () <<
      _T ("Setting english locale: ArgSep=',' DecSep='.' ThousandsSep=''\n");
    
    
    
    
  
  
  else if (sLine == _T ("locale reset"))
    
  {
    
    
    
  
  
  else if (sLine == _T ("test bulk"))
    
  {
    
    
    
  
  



//---------------------------------------------------------------------------
  void
CalcBulk () 
{
  
  
  
  
  
  {
    
      
    {
      
      
    
    
    
    
    
    
    
      
    {
      
        console () << _T ("Eqn. ") << i << _T (": x=") << x[i] << _T ("; y=")
        << y[i] << _T ("; result=") << result[i] << _T ("\n");
  
  {
    
    
    
    
  
  
  


//---------------------------------------------------------------------------
  void
Calc () 
{
  
  
    // Change locale settings if necessary
    // function argument separator:   sum(2;3;4) vs. sum(2,3,4)
    // decimal separator:             3,14       vs. 3.14
    // thousands separator:           1000000    vs 1.000.000
//#define USE_GERMAN_LOCALE
#ifdef  USE_GERMAN_LOCALE
    parser.SetArgSep (';');
  
  
  
#else   /* 
    // this is the default, so i it's commented:
    //parser.SetArgSep(',');
    //parser.SetDecSep('.');
    //parser.SetThousandsSep('');
#endif  /* 
    
    // Add some variables
    value_type vVarVal[] =
  {
  1, 2};                        // Values of the parser variables
  parser.DefineVar (_T ("a"), &vVarVal[0]);     // Assign Variable names and bind them to the C++ variables
  parser.DefineVar (_T ("b"), &vVarVal[1]);
  
  
  
  
  
    // Add user defined unary operators
    parser.DefinePostfixOprt (_T ("M"), Mega);
  
  
  
  
  
  
  parser.DefineFun (_T ("throw"), ThrowAnException);
  
  
  
    // These are service and debug functions
    parser.DefineFun (_T ("debug"), Debug);
  
  
  
  
  
#ifdef _DEBUG
//  parser.EnableDebugDump(1, 0);
#endif  /* 
    
    // Define the variable factory
    parser.SetVarFactory (AddVariable, &parser);
  
    
  {
    
    {
      
      
      
        
      {
      
        break;
      
        continue;
      
        return;
      
      
        
      
      
      
        // There are multiple ways to retrieve the result...
        // 1.) If you know there is only a single return value or in case you only need the last 
        //     result of an expression consisting of comma separated subexpressions you can 
        //     simply use: 
        mu::console () << _T ("ans=") << parser.Eval () << _T ("\n");
      
        // 2.) As an alternative you can also retrieve multiple return values using this API:
      int nNum = parser.GetNumResults ();
      
        
      {
        
          console () <<
          _T ("Multiple return values detected! Complete list:\n");
        
          // this is the hard way if you need to retrieve multiple subexpression
          // results
          value_type * v = parser.Eval (nNum);
        
        
          
        {
          
      
    
    {
      
      
      
      
        GetExpr () << _T ("\"\n");
      
        GetToken () << _T ("\"\n");
      
        GetPos () << _T ("\n");
      
        GetCode () << _T ("\n");
  
} 

//---------------------------------------------------------------------------
  int
main (int, char **) 
{
  
  
  
  
//  CheckLocale();
//  CheckDiff();
    
  
  {
    
  
  {
    
      // Only erros raised during the initialization will end up here
      // formula related errors are treated in Calc()
      console () << _T ("Initialization error:  ") << e.GetMsg () << endl;
    
    
    
  
  {
    
      // there is no unicode compliant way to query exc.what()
      // so i'll leave it for this example.
      console () << _T ("aborting...\n");
  


