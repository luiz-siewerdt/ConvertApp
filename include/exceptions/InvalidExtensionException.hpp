#ifndef INVALID_EXTENSION_H
#define INVALID_EXTENSION_H

#include <exception>
#include <string>

using namespace std;

namespace Convert {
class InvalidExtensionException : public exception {
  string errorMessage;

public:
  explicit InvalidExtensionException(const string &extension) {
    this->errorMessage = extension + " isn't a valid extension";
  }

  const char *what() const noexcept { return errorMessage.c_str(); }
};

} // namespace Convert

#endif // !INVALID_EXTENSION_H
