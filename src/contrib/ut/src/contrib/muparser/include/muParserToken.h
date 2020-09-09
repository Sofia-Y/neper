/*
                 __________                                      
    _____   __ __\______   \_____  _______  ______  ____ _______ 
   /     \ |  |  \|     ___/\__  \ \_  __ \/  ___/_/ __ \\_  __ \
  |  Y Y  \|  |  /|    |     / __ \_|  | \/\___ \ \  ___/ |  | \/
  |__|_|  /|____/ |____|    (____  /|__|  /____  > \___  >|__|   
        \/                       \/            \/      \/        
  Copyright (C) 2004-2013 Ingo Berg

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
  
  
#ifndef MU_PARSER_TOKEN_H
#define MU_PARSER_TOKEN_H
  
#include <cassert>
#include <string>
#include <stack>
#include <vector>
#include <memory>
  
#include "muParserError.h"
#include "muParserCallback.h"
  
/** \file
    \brief This file contains the parser token definition.
*/ 
  
{
  
  /** \brief Encapsulation of the data for a single formula token. 

    Formula token implementation. Part of the Math Parser Package.
    Formula tokens can be either one of the following:
    <ul>
      <li>value</li>
      <li>variable</li>
      <li>function with numerical arguments</li>
      <li>functions with a string as argument</li>
      <li>prefix operators</li>
      <li>infix operators</li>
	    <li>binary operator</li>
    </ul>

   \author (C) 2004-2013 Ingo Berg 
  */ 
    template < typename TBase, typename TString > 
  {
  
    ETypeCode m_iType;
    
    int m_iIdx;                 ///< An otional index to an external buffer storing the token data
    TString m_strTok;           ///< Token string
    TString m_strVal;           ///< Value for string variables
    value_type m_fVal;          ///< the value 
    std::auto_ptr < ParserCallback > m_pCallback;
  
      //---------------------------------------------------------------------------
      /** \brief Constructor (default).
        
          Sets token to an neutral state of type cmUNKNOWN.
          \throw nothrow
          \sa ECmdCode
      */ 
  ParserToken () 
    m_iCode (cmUNKNOWN) 
    m_strTok () 
    {
    } 
      //------------------------------------------------------------------------------
      /** \brief Create token from another one.
      
          Implemented by calling Assign(...)
          \throw nothrow
          \post m_iType==cmUNKNOWN
          \sa #Assign
      */ 
      ParserToken (const ParserToken & a_Tok) 
    {
      
    
      //------------------------------------------------------------------------------
      /** \brief Assignement operator. 
      
          Copy token state from another token and return this.
          Implemented by calling Assign(...).
          \throw nothrow
      */ 
      ParserToken & operator= (const ParserToken & a_Tok) 
    {
      
      
    
    
      //------------------------------------------------------------------------------
      /** \brief Copy token information from argument.
      
          \throw nothrow
      */ 
    void Assign (const ParserToken & a_Tok) 
    {
      
      
      
      
      
      
      
      
        // create new callback object if a_Tok has one 
        m_pCallback.reset (a_Tok.m_pCallback.get ()? a_Tok.m_pCallback->
                           Clone () : 0);
    
      //------------------------------------------------------------------------------
      /** \brief Assign a token type. 

        Token may not be of type value, variable or function. Those have seperate set functions. 

        \pre [assert] a_iType!=cmVAR
        \pre [assert] a_iType!=cmVAL
        \pre [assert] a_iType!=cmFUNC
        \post m_fVal = 0
        \post m_pTok = 0
      */ 
      ParserToken & Set (ECmdCode a_iType, const TString & a_strTok =
                         TString ()) 
    {
      
        // The following types cant be set this way, they have special Set functions
        assert (a_iType != cmVAR);
      
      
      
      
      
      
      
      
    
    
      //------------------------------------------------------------------------------
      /** \brief Set Callback type. */ 
      ParserToken & Set (const ParserCallback & a_pCallback,
                         const TString & a_sTok) 
    {
      
      
      
      
      
      
      
      
    
    
      //------------------------------------------------------------------------------
      /** \brief Make this token a value token. 
      
          Member variables not necessary for value tokens will be invalidated.
          \throw nothrow
      */ 
      ParserToken & SetVal (TBase a_fVal, const TString & a_strTok =
                            TString ()) 
    {
      
      
      
      
      
      
      
      
    
    
      //------------------------------------------------------------------------------
      /** \brief make this token a variable token. 
      
          Member variables not necessary for variable tokens will be invalidated.
          \throw nothrow
      */ 
      ParserToken & SetVar (TBase * a_pVar, const TString & a_strTok) 
    {
      
      
      
      
      
      
      
    
    
      //------------------------------------------------------------------------------
      /** \brief Make this token a variable token. 
      
          Member variables not necessary for variable tokens will be invalidated.
          \throw nothrow
      */ 
      ParserToken & SetString (const TString & a_strTok, std::size_t a_iSize) 
    {
      
      
      
      
      
      
      
    
    
      //------------------------------------------------------------------------------
      /** \brief Set an index associated with the token related data. 
      
          In cmSTRFUNC - This is the index to a string table in the main parser.
          \param a_iIdx The index the string function result will take in the bytecode parser.
          \throw exception_type if #a_iIdx<0 or #m_iType!=cmSTRING
      */ 
    void SetIdx (int a_iIdx) 
    {
      
        
      
    
    
      //------------------------------------------------------------------------------
      /** \brief Return Index associated with the token related data. 
      
          In cmSTRFUNC - This is the index to a string table in the main parser.

          \throw exception_type if #m_iIdx<0 or #m_iType!=cmSTRING
          \return The index the result will take in the Bytecode calculatin array (#m_iIdx).
      */ 
    int GetIdx () const 
    {
      
        
      
    
     
      //------------------------------------------------------------------------------
      /** \brief Return the token type.
      
          \return #m_iType
          \throw nothrow
      */ 
      ECmdCode GetCode () const 
    {
      
        
      {
        
      
       
      else
         
      {
        
      
    
    
      //------------------------------------------------------------------------------
    ETypeCode GetType ()const 
    {
      
        
      {
        
      
       
      else
         
      {
        
      
    
    
      //------------------------------------------------------------------------------
    int GetPri () const 
    {
      
        
      
            && m_pCallback->GetCode () != cmOPRT_INFIX)
        
      
    
     
      //------------------------------------------------------------------------------
      EOprtAssociativity GetAssociativity () const 
    {
      
           || m_pCallback->GetCode () != cmOPRT_BIN)
        
      
    
     
      //------------------------------------------------------------------------------
      /** \brief Return the address of the callback function assoziated with
                 function and operator tokens.

          \return The pointer stored in #m_pTok.
          \throw exception_type if token type is non of:
                 <ul>
                   <li>cmFUNC</li>
                   <li>cmSTRFUNC</li>
                   <li>cmPOSTOP</li>
                   <li>cmINFIXOP</li>
                   <li>cmOPRT_BIN</li>
                 </ul>
          \sa ECmdCode
      */ 
      generic_fun_type GetFuncAddr () const 
    {
      
        GetAddr () : 0;
    
     
      //------------------------------------------------------------------------------
      /** \biref Get value of the token.
        
          Only applicable to variable and value tokens.
          \throw exception_type if token is no value/variable token.
      */ 
      TBase GetVal () const 
    {
      
        
      {
      
        return m_fVal;
        
        
      
     
     
      //------------------------------------------------------------------------------
      /** \brief Get address of a variable token.

        Valid only if m_iType==CmdVar.
        \throw exception_type if token is no variable token.
      */ 
      TBase * GetVar () const 
    {
      
        
      
    
     
      //------------------------------------------------------------------------------
      /** \brief Return the number of function arguments. 

        Valid only if m_iType==CmdFUNC.
      */ 
    int GetArgCount () const 
    {
      
      
        
      
    
     
      //------------------------------------------------------------------------------
      /** \brief Return the token identifier. 
          
          If #m_iType is cmSTRING the token identifier is the value of the string argument
          for a string function.
          \return #m_strTok
          \throw nothrow
          \sa m_strTok
      */ 
    const TString & GetAsString () const 
    {
      
    
   



#endif  /* 