#pragma once

#include "../controllers/boardController.h"
#include "../controllers/taskController.h"
#include <memory>
#include <pistache/endpoint.h>
#include <pistache/http.h>
#include <pistache/router.h>
class LazarusApi {
public:
  explicit LazarusApi(Pistache::Address, std::shared_ptr<TaskController>,
                      std::shared_ptr<BoardController> boardController);
  void init(size_t threadCount);
  void start();

private:
  std::shared_ptr<Pistache::Http::Endpoint> httpEndpoint_;
  Pistache::Rest::Router router_;
  std::shared_ptr<TaskController> taskController_;
  std::shared_ptr<BoardController> boardController_;
  void setupRoutes();
  void setupMiddleware();
};
