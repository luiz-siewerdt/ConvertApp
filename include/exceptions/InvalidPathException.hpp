

#ifndef INVALID_PATH_H
#define INVALID_PATH_H

#include <exception>
#include <string>

using namespace std;

namespace Convert {
class InvalidPathException : public exception {
  string errorMessage;

public:
  explicit InvalidPathException(const string &invalidPath) {
    this->errorMessage = invalidPath + " isn't a valid path";
  }

  const char *what() const noexcept override { return errorMessage.c_str(); }
};

} // namespace Convert

#endif // !INVALID_PATH_H
