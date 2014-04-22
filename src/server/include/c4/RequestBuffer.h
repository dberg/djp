//-*- C++ -*-
#ifndef __REQUEST_BUFFER_H__
#define __REQUEST_BUFFER_H__

#include <iostream>
#include <memory>
#include <vector>
#include "c4/Request.pb.h"

namespace c4 {

class RequestBuffer;
typedef std::shared_ptr<RequestBuffer> spRequestBuffer;

class RequestBuffer {

  unsigned long size;
  std::vector<char> bytes;

  void calculateSize();

public:
  RequestBuffer(): size(0) {}
  int feed(char buffer[], int cbytes);
  Request buildAndRemoveRequest();
};

} // namespace

#endif
