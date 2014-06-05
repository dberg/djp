//-*- C++ -*-
#ifndef __C4S_PHASE_H__
#define __C4S_PHASE_H__

#include <memory>
#include "c4/common/CompilationUnit.h"
#include "c4/scala/TypeDefs.h"

namespace c4s {

/**
 * Phase abstract class.
 */
class Phase {

public:
  virtual void run() = 0;
};

/**
 * Initial Phase marker.
 */
class NoPhase : public Phase {

public:
  virtual void run();
};

class GlobalPhase : public Phase {
private:
  virtual void applyPhase(c4::spCompilationUnit &unit);

public:
  virtual void run();
  virtual void apply(c4::spCompilationUnit &unit) = 0;
};

class StdPhase : public GlobalPhase {

};

class ParserPhase : public StdPhase {
public:
  virtual void apply(c4::spCompilationUnit &unit);
};

} // namespace

#endif
