#include "router.h"
#include "middleware.cpp"
#include <pistache/http.h>
#include <pistache/router.h>

using namespace Pistache;

LazarusApi::LazarusApi(Address addr, std::shared_ptr<TaskController> tc,
                       std::shared_ptr<BoardController> bc)
    : httpEndpoint_(std::make_shared<Http::Endpoint>(addr)),
      taskController_(std::move(tc)), boardController_(std::move(bc)) {};

void LazarusApi::init(size_t thr = 2) {
  auto opts = Http::Endpoint::options().threads(static_cast<int>(thr));
  httpEndpoint_->init(opts);
  setupRoutes();
  setupMiddleware();
}

void LazarusApi::start() {
  httpEndpoint_->setHandler(router_.handler());
  httpEndpoint_->serve();
};

void LazarusApi::setupMiddleware() {
  router_.addMiddleware(Rest::Routes::middleware(authMiddleware));
}

void LazarusApi::setupRoutes() {
  using namespace Rest;

  Routes::Get(router_, "/tasks",
              Routes::bind(&TaskController::getTasks, taskController_));
  Routes::Get(
      router_, "/boards/:id",
      Routes::bind(&BoardController::getBoardsByUser, boardController_));
}
