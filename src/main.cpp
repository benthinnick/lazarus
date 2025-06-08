#include "controllers/boardController.h"
#include "controllers/taskController.h"
#include "db/boardRepository.h"
#include "db/db.h"
#include "routes/router.h"
#include "services/boardService.h"
#include <memory>

int main() {
  std::shared_ptr<ConnectionPool> connectionPool = std::make_shared<
      ConnectionPool>(
      "dbname=lazarus user=postgres password=pathword host=localhost port=5432",
      5);
  std::shared_ptr<BoardRepository> br =
      std::make_shared<BoardRepository>(connectionPool);
  std::shared_ptr<BoardService> bs = std::make_shared<BoardService>(br);
  std::shared_ptr<TaskController> tc = std::make_shared<TaskController>();
  std::shared_ptr<BoardController> bc = std::make_shared<BoardController>(bs);

  Pistache::Port port(8000);
  Pistache::Address addr("localhost", port);

  LazarusApi api(addr, tc, bc);

  api.init(2);
  api.start();
}
