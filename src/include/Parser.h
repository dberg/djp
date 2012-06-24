//-*- C++ -*-
#ifndef __PARSER_H__
#define __PARSER_H__
#include <string>
#include <sstream>
#include <vector>
#include "AST.h"
#include "ErrorCodes.h"
#include "SymbolTable.h"
#include "Token.h"

namespace djp {
class Parser {
  const std::string filename;
  const std::string buffer;

  unsigned int cursor;
  unsigned int line;

  int curToken;
  std::string curTokenStr;

  std::vector<std::string> scopes;

  struct State {
    int cursor, line, token;
    std::string tokenStr;
  };

  TokenUtil tokenUtil;

  // Helper methods
  bool isBasicType(int token);
  bool isJavaLetter(char c);
  bool isJavaLetterOrDigit(char c);
  bool isModifierToken(int token);
  bool isValidInitTokenOfClassBodyDeclaration(int token);
  bool isValidInitTokenOfTypeDeclaration(int token);
  void saveState(State &state);
  void restoreState(State &state);
  void addError(int err);
  void addError(int ini, int end, int err);

  // Lexer
  const char getChar();
  const char ungetChar(int count);
  bool lookaheadInterface(int point);

  void getNextToken();
  int getToken();
  int getAnnotationToken();
  int getPeriodOrEllipsisToken();
  int getTokenIdentifier(char c);

  // Parsing
  spAnnotation parseAnnotation();
  spAnnotationElement parseAnnotationElement();
  void parseAnnotations(std::vector<spAnnotation> &annotations);
  int parseArrayDepth();
  void parseClassBody(spClassBody &classBody);
  void parseClassBodyDeclaration(spClassBodyDeclaration &decl);
  void parseClassDeclaration(spClassDeclaration &classDecl);
  void parseClassOrInterfaceDeclaration(spClassOrInterfaceDeclaration& decl);
  void parseCompilationUnit();
  void parseConstructorDeclaratorRest(
    spConstructorDeclaratorRest &constDeclRest);
  void parseVariableDeclaratorId(spVariableDeclaratorId &varDeclId);
  void parseFormalParameters(spFormalParameters &formParams);
  void parseFormalParameterDecls(spFormalParameterDecls &formParamDecls);
  void parseFormalParameterDeclsRest(
    spFormalParameterDeclsRest &formParamDeclsRest);
  spImportDeclaration parseImportDeclaration();
  spImportDeclarations parseImportDeclarations();
  void parseModifier(spModifier &modifier);
  void parseMemberDecl(spMemberDecl &memberDecl);
  void parseNormalClassDeclaration(spNormalClassDeclaration &nClassDecl);
  spPackageDeclaration parsePackageDeclaration(
    std::vector<spAnnotation> &annotations);
  spQualifiedIdentifier parseQualifiedIdentifier();
  void parseType(spType &type);
  std::vector<spTypeDeclaration> parseTypeDeclarations(
    std::vector<spAnnotation> &annotations);
  void parseVariableModifier(spVariableModifier &varModifier);

public:
  Parser(const std::string _filename, const std::string &_buffer)
    : filename(_filename), buffer(_buffer), cursor(0), line(1), curToken(0),
      compilationUnit(spCompilationUnit(new CompilationUnit())),
      error(0), error_msg("") {}

  spCompilationUnit compilationUnit;
  ST st;
  int error;
  std::string error_msg;

  void parse();
};
} // namespace

#endif
