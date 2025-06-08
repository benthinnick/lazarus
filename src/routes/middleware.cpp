#include <pistache/http.h>
#include <pistache/router.h>

using namespace Pistache;

bool authMiddleware(Http::Request &req, Http::ResponseWriter &response) {
  std::cout << "middleware works" << std::endl;
  return true;
}
