
#ifndef INVALID_FILE_H
#define INVALID_FILE_H

#include <exception>
#include <string>

using namespace std;

namespace Convert {
class InvalidFileException : public exception {
  string errorMessage;

public:
  explicit InvalidFileException(const string &invalidPath)
      : errorMessage(invalidPath + " isn't a valid file") {}

  const char *what() const noexcept { return errorMessage.c_str(); }
};

} // namespace Convert
#endif // !INVALID_FILE_H
