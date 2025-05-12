#include "router.h"

using namespace Pistache;
LazarusApi::LazarusApi(Address addr, std::shared_ptr<TaskController> tc)
    : httpEndpoint_(std::make_shared<Http::Endpoint>(addr)),
      taskController_(std::move(tc)) {};

void LazarusApi::init(size_t thr = 2) {
  auto opts = Http::Endpoint::options().threads(static_cast<int>(thr));
  httpEndpoint_->init(opts);
  setupRoutes();
}

void LazarusApi::start() {
  httpEndpoint_->setHandler(router_.handler());
  httpEndpoint_->serve();
};

void LazarusApi::setupRoutes() {
  using namespace Rest;

  Routes::Get(router_, "/tasks",
              Routes::bind(&TaskController::getTasks, taskController_));
}
