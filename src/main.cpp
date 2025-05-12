#include "controllers/taskController.h"
#include "routes/router.h"

int main() {
  std::shared_ptr<TaskController> tc = std::make_shared<TaskController>();
  Pistache::Port port(8000);

  Pistache::Address addr("localhost", port);

  LazarusApi api(addr, tc);

  api.init(2);
  api.start();
}
