#include "native_api.h"

#include <memory>
#include <cmath>
#include <string>

#include "messages.pb.h"

std::string result;

inline char* StringAsArray(std::string* str) {
  return str->empty() ? NULL : &*str->begin();
}

int CalculateSquareRoot(int length, const char* data) {
  Request request;
  if (!request.ParseFromArray(data, length))
    return -1;

  Response response;
  for (int i = 0; i < request.value_size(); ++i) {
    int value = request.value(i);
    response.add_value(sqrt(static_cast<float>(value)));
  }

  response.SerializeToString(&result);
  return result.size();
}

int RetrieveResult(char* data) {
  memcpy(data, StringAsArray(&result), result.size());
  return 0;
}