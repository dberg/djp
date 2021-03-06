//-*- C++ -*-
#ifndef __C4_JAVA_TOKEN_H__
#define __C4_JAVA_TOKEN_H__

#include <map>
#include <string>

using std::u32string;

namespace c4j {

enum Token {
  TOK_EOF = -1,
  TOK_ERROR = -2,

  // Separators
  TOK_LPAREN = -3,
  TOK_RPAREN = -4,
  TOK_LCURLY_BRACKET = -5,
  TOK_RCURLY_BRACKET = -6,
  TOK_LBRACKET = -7,
  TOK_RBRACKET = -8,
  TOK_SEMICOLON = -9,
  TOK_COMMA = -10,
  TOK_PERIOD = -11,

  // Operators
  TOK_OP_EQUALS = -12,
  TOK_OP_GT = -13,
  TOK_OP_LT = -14,
  TOK_OP_EXCLAMATION = -15,
  TOK_OP_TILDE = -16,
  TOK_OP_QUESTION_MARK = -17,
  TOK_OP_COLON = -18,
  TOK_OP_EQUALS_EQUALS = -19,
  TOK_OP_LT_EQUALS = -20,
  TOK_OP_GT_EQUALS = -21,
  TOK_OP_EXCLAMATION_EQUALS = -22,
  TOK_OP_AMPERSAND_AMPERSAND = -23,
  TOK_OP_PIPE_PIPE = -24,
  TOK_OP_PLUS_PLUS = -25,
  TOK_OP_MINUS_MINUS = -26,
  TOK_OP_PLUS = -27,
  TOK_OP_MINUS = -28,
  TOK_OP_MUL = -29,
  TOK_OP_DIV = -30,
  TOK_OP_AMPERSAND = -31,
  TOK_OP_PIPE = -32,
  TOK_OP_CARRET = -33,
  TOK_OP_REM = -34,
  TOK_OP_LSHIFT = -35,
  TOK_OP_RSHIFT = -36,
  TOK_OP_TRIPLE_RSHIFT = -37,
  TOK_OP_PLUS_EQUALS = -38,
  TOK_OP_MINUS_EQUALS = -39,
  TOK_OP_MUL_EQUALS = -40,
  TOK_OP_DIV_EQUALS = -41,
  TOK_OP_AMPERSAND_EQUALS = -42,
  TOK_OP_PIPE_EQUALS = -43,
  TOK_OP_CARRET_EQUALS = -44,
  TOK_OP_REM_EQUALS = -45,
  TOK_OP_LSHIFT_EQUALS = -46,
  TOK_OP_RSHIFT_EQUALS = -47,
  TOK_OP_TRIPLE_RSHIFT_EQUALS = -48,

  // Special symbols
  TOK_ANNOTATION = -49,
  TOK_ANNOTATION_TYPE_DECLARATION = -50,
  TOK_IDENTIFIER = -51,
  TOK_ELLIPSIS = -52,

  TOK_INTEGER_TYPE_SUFFIX = -53, // 'l' or 'L'
  TOK_BOOLEAN_LITERAL = -54,
  TOK_NULL_LITERAL = -55,
  TOK_CHARACTER_LITERAL = -56,
  TOK_ESCAPE_SEQUENCE = -57,
  TOK_STRING_LITERAL = -58,

  // Numbers
  TOK_DECIMAL_NUMERAL = -59,
  TOK_DECIMAL_NUMERAL_WITH_INT_TYPE_SUFFIX = -60,
  TOK_HEX_NUMERAL = -61,
  TOK_HEX_NUMERAL_WITH_INT_TYPE_SUFFIX = -62,
  TOK_OCTAL_NUMERAL = -63,
  TOK_OCTAL_NUMERAL_WITH_INT_TYPE_SUFFIX = -64,
  TOK_BINARY_NUMERAL = -65,
  TOK_BINARY_NUMERAL_WITH_INT_TYPE_SUFFIX = -66,

  TOK_DECIMAL_FLOATING_POINT_LITERAL = -67,
  TOK_HEXADECIMAL_FLOATING_POINT_LITERAL = -68,

  // Keywords
  TOK_KEY_ABSTRACT = -69,
  TOK_KEY_ASSERT = -70,
  TOK_KEY_BOOLEAN = -71,
  TOK_KEY_BREAK = -72,
  TOK_KEY_BYTE = -73,
  TOK_KEY_CASE = -74,
  TOK_KEY_CATCH = -75,
  TOK_KEY_CHAR = -76,
  TOK_KEY_CLASS = -77,
  TOK_KEY_CONST = -78,
  TOK_KEY_CONTINUE = -79,
  TOK_KEY_DEFAULT = -80,
  TOK_KEY_DO = -81,
  TOK_KEY_DOUBLE = -82,
  TOK_KEY_ELSE = -83,
  TOK_KEY_ENUM = -84,
  TOK_KEY_EXTENDS = -85,
  TOK_KEY_FINAL = -86,
  TOK_KEY_FINALLY = -87,
  TOK_KEY_FLOAT = -88,
  TOK_KEY_FOR = -89,
  TOK_KEY_GOTO = -90,
  TOK_KEY_IF = -91,
  TOK_KEY_IMPLEMENTS = -92,
  TOK_KEY_IMPORT = -93,
  TOK_KEY_INSTANCEOF = -94,
  TOK_KEY_INT = -95,
  TOK_KEY_INTERFACE = -96,
  TOK_KEY_LONG = -97,
  TOK_KEY_NATIVE = -98,
  TOK_KEY_NEW = -99,
  TOK_KEY_PACKAGE = -100,
  TOK_KEY_PRIVATE = -101,
  TOK_KEY_PROTECTED = -102,
  TOK_KEY_PUBLIC = -103,
  TOK_KEY_RETURN = -104,
  TOK_KEY_SHORT = -105,
  TOK_KEY_STATIC = -106,
  TOK_KEY_STRICTFP = -107,
  TOK_KEY_SUPER = -108,
  TOK_KEY_SWITCH = -109,
  TOK_KEY_SYNCHRONIZED = -110,
  TOK_KEY_THIS = -111,
  TOK_KEY_THROW = -112,
  TOK_KEY_THROWS = -113,
  TOK_KEY_TRANSIENT = -114,
  TOK_KEY_TRY = -115,
  TOK_KEY_VOID = -116,
  TOK_KEY_VOLATILE = -117,
  TOK_KEY_WHILE = -118,
};

class TokenUtil {
  typedef std::map<std::u32string, int> KeywordMap;
  KeywordMap keywords;

  typedef std::map<int, int> TokenLengthMap;
  TokenLengthMap tokensLen;

public:
  TokenUtil() {
    keywords[U"abstract"] = TOK_KEY_ABSTRACT;
    keywords[U"assert"] = TOK_KEY_ASSERT;
    keywords[U"boolean"] = TOK_KEY_BOOLEAN;
    keywords[U"break"] = TOK_KEY_BREAK;
    keywords[U"byte"] = TOK_KEY_BYTE;
    keywords[U"case"] = TOK_KEY_CASE;
    keywords[U"catch"] = TOK_KEY_CATCH;
    keywords[U"char"] = TOK_KEY_CHAR;
    keywords[U"class"] = TOK_KEY_CLASS;
    keywords[U"const"] = TOK_KEY_CONST;
    keywords[U"continue"] = TOK_KEY_CONTINUE;
    keywords[U"default"] = TOK_KEY_DEFAULT;
    keywords[U"do"] = TOK_KEY_DO;
    keywords[U"double"] = TOK_KEY_DOUBLE;
    keywords[U"else"] = TOK_KEY_ELSE;
    keywords[U"enum"] = TOK_KEY_ENUM;
    keywords[U"extends"] = TOK_KEY_EXTENDS;
    keywords[U"final"] = TOK_KEY_FINAL;
    keywords[U"finally"] = TOK_KEY_FINALLY;
    keywords[U"float"] = TOK_KEY_FLOAT;
    keywords[U"for"] = TOK_KEY_FOR;
    keywords[U"goto"] = TOK_KEY_GOTO;
    keywords[U"if"] = TOK_KEY_IF;
    keywords[U"implements"] = TOK_KEY_IMPLEMENTS;
    keywords[U"import"] = TOK_KEY_IMPORT;
    keywords[U"instanceof"] = TOK_KEY_INSTANCEOF;
    keywords[U"int"] = TOK_KEY_INT;
    keywords[U"interface"] = TOK_KEY_INTERFACE;
    keywords[U"long"] = TOK_KEY_LONG;
    keywords[U"native"] = TOK_KEY_NATIVE;
    keywords[U"new"] = TOK_KEY_NEW;
    keywords[U"package"] = TOK_KEY_PACKAGE;
    keywords[U"private"] = TOK_KEY_PRIVATE;
    keywords[U"protected"] = TOK_KEY_PROTECTED;
    keywords[U"public"] = TOK_KEY_PUBLIC;
    keywords[U"return"] = TOK_KEY_RETURN;
    keywords[U"short"] = TOK_KEY_SHORT;
    keywords[U"static"] = TOK_KEY_STATIC;
    keywords[U"strictfp"] = TOK_KEY_STRICTFP;
    keywords[U"super"] = TOK_KEY_SUPER;
    keywords[U"switch"] = TOK_KEY_SWITCH;
    keywords[U"synchronized"] = TOK_KEY_SYNCHRONIZED;
    keywords[U"this"] = TOK_KEY_THIS;
    keywords[U"throw"] = TOK_KEY_THROW;
    keywords[U"throws"] = TOK_KEY_THROWS;
    keywords[U"transient"] = TOK_KEY_TRANSIENT;
    keywords[U"try"] = TOK_KEY_TRY;
    keywords[U"void"] = TOK_KEY_VOID;
    keywords[U"volatile"] = TOK_KEY_VOLATILE;
    keywords[U"while"] = TOK_KEY_WHILE;

    tokensLen[TOK_NULL_LITERAL] = 4;

    tokensLen[TOK_KEY_ABSTRACT] = 8;
    tokensLen[TOK_KEY_ASSERT] = 6;
    tokensLen[TOK_KEY_BOOLEAN] = 7;
    tokensLen[TOK_KEY_BREAK] = 5;
    tokensLen[TOK_KEY_BYTE] = 4;
    tokensLen[TOK_KEY_CASE] = 4;
    tokensLen[TOK_KEY_CATCH] = 5;
    tokensLen[TOK_KEY_CHAR] = 4;
    tokensLen[TOK_KEY_CLASS] = 5;
    tokensLen[TOK_KEY_CONST] = 5;
    tokensLen[TOK_KEY_CONTINUE] = 8;
    tokensLen[TOK_KEY_DEFAULT] = 7;
    tokensLen[TOK_KEY_DO] = 2;
    tokensLen[TOK_KEY_DOUBLE] = 6;
    tokensLen[TOK_KEY_ELSE] = 4;
    tokensLen[TOK_KEY_ENUM] = 4;
    tokensLen[TOK_KEY_EXTENDS] = 7;
    tokensLen[TOK_KEY_FINAL] = 5;
    tokensLen[TOK_KEY_FINALLY] = 7;
    tokensLen[TOK_KEY_FLOAT] = 5;
    tokensLen[TOK_KEY_FOR] = 3;
    tokensLen[TOK_KEY_GOTO] = 4;
    tokensLen[TOK_KEY_IF] = 2;
    tokensLen[TOK_KEY_IMPLEMENTS] = 10;
    tokensLen[TOK_KEY_IMPORT] = 6;
    tokensLen[TOK_KEY_INSTANCEOF] = 10;
    tokensLen[TOK_KEY_INT] = 3;
    tokensLen[TOK_KEY_INTERFACE] = 9;
    tokensLen[TOK_KEY_LONG] = 4;
    tokensLen[TOK_KEY_NATIVE] = 6;
    tokensLen[TOK_KEY_NEW] = 3;
    tokensLen[TOK_KEY_PACKAGE] = 7;
    tokensLen[TOK_KEY_PRIVATE] = 7;
    tokensLen[TOK_KEY_PROTECTED] = 9;
    tokensLen[TOK_KEY_PUBLIC] = 6;
    tokensLen[TOK_KEY_RETURN] = 6;
    tokensLen[TOK_KEY_SHORT] = 5;
    tokensLen[TOK_KEY_STATIC] = 6;
    tokensLen[TOK_KEY_STRICTFP] = 8;
    tokensLen[TOK_KEY_SUPER] = 5;
    tokensLen[TOK_KEY_SWITCH] = 6;
    tokensLen[TOK_KEY_SYNCHRONIZED] = 12;
    tokensLen[TOK_KEY_THIS] = 4;
    tokensLen[TOK_KEY_THROW] = 5;
    tokensLen[TOK_KEY_THROWS] = 6;
    tokensLen[TOK_KEY_TRANSIENT] = 9;
    tokensLen[TOK_KEY_TRY] = 3;
    tokensLen[TOK_KEY_VOID] = 4;
    tokensLen[TOK_KEY_VOLATILE] = 8;
    tokensLen[TOK_KEY_WHILE] = 5;

    // InfixOp, PrefixOp, AssignmentOperator
    tokensLen[TOK_OP_AMPERSAND_AMPERSAND] = 2;
    tokensLen[TOK_OP_PIPE] = 1;
    tokensLen[TOK_OP_CARRET] = 1;
    tokensLen[TOK_OP_AMPERSAND] = 1;
    tokensLen[TOK_OP_EQUALS_EQUALS] = 2;
    tokensLen[TOK_OP_EXCLAMATION_EQUALS] = 2;
    tokensLen[TOK_OP_LT] = 1;
    tokensLen[TOK_OP_GT] = 1;
    tokensLen[TOK_OP_LT_EQUALS] = 2;
    tokensLen[TOK_OP_GT_EQUALS] = 2;
    tokensLen[TOK_OP_LSHIFT] = 2;
    tokensLen[TOK_OP_RSHIFT] = 2;
    tokensLen[TOK_OP_TRIPLE_RSHIFT] = 3;
    tokensLen[TOK_OP_PLUS] = 1;
    tokensLen[TOK_OP_MINUS] = 1;
    tokensLen[TOK_OP_MUL] = 1;
    tokensLen[TOK_OP_DIV] = 1;
    tokensLen[TOK_OP_REM] = 1;
    tokensLen[TOK_OP_PLUS_PLUS] = 2;
    tokensLen[TOK_OP_MINUS_MINUS] = 2;
    tokensLen[TOK_OP_EXCLAMATION] = 1;
    tokensLen[TOK_OP_TILDE] = 1;
    tokensLen[TOK_OP_EQUALS] = 1;
    tokensLen[TOK_OP_PLUS_EQUALS] = 2;
    tokensLen[TOK_OP_MINUS_EQUALS] = 2;
    tokensLen[TOK_OP_MUL_EQUALS] = 2;
    tokensLen[TOK_OP_DIV_EQUALS] = 2;
    tokensLen[TOK_OP_AMPERSAND_EQUALS] = 2;
    tokensLen[TOK_OP_PIPE_EQUALS] = 2;
    tokensLen[TOK_OP_CARRET_EQUALS] = 2;
    tokensLen[TOK_OP_REM_EQUALS] = 2;
    tokensLen[TOK_OP_LSHIFT_EQUALS] = 2;
    tokensLen[TOK_OP_RSHIFT_EQUALS] = 2;
    tokensLen[TOK_OP_TRIPLE_RSHIFT_EQUALS] = 3;

  }

  int getKeywordToken(u32string identifier) {
    KeywordMap::iterator it = keywords.find(identifier);
    if (it == keywords.end()) {
      return 0;
    }
    return it->second;
  }

  int getTokenLength(int token) {
    TokenLengthMap::iterator it = tokensLen.find(token);
    if (it == tokensLen.end()) {
      return 0;
    }
    return it->second;
  }
};

enum ImportType {
  SINGLE_TYPE_IMPORT_DECLARATION,
  TYPE_IMPORT_ON_DEMAND_DECLARATION,
  SINGLE_STATIC_IMPORT_DECLARATION,
  STATIC_IMPORT_ON_DEMAND_DECLARATION,
};

} // namespace
#endif
