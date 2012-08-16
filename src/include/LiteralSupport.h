//-*- C++ -*-
#ifndef __LITERAL_SUPPORT_H__
#define __LITERAL_SUPPORT_H__
#include <sstream>
#include <boost/shared_ptr.hpp>
#include "SourceCodeStream.h"
#include "Token.h"

namespace djp {

class LiteralSupport;
typedef boost::shared_ptr<LiteralSupport> spLiteralSupport;

class LiteralSupport {

  spSourceCodeStream src;

  // Integer Literals
  int consumeIntegerLiteral(std::stringstream &ss, bool (*fnDigitP) (char),
    int tok, int tokWithSuffix);
  int getBinaryNumeral(std::stringstream &ss);
  int getDecimalNumeral(std::stringstream &ss);
  int getHexNumeral(std::stringstream &ss);
  int getOctalNumeral(std::stringstream &ss);
  int getTokWithLeadingZero(std::stringstream &ss);

public:
  LiteralSupport(spSourceCodeStream &src) : src(src) {}
  int getLiteralNumber(char c, std::stringstream &ss);
};

} // namespace

#endif
