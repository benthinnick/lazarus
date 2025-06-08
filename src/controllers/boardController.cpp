#include "boardController.h"
#include "../utils/utils.cpp"
#include <memory>
#include <nlohmann/json.hpp>

BoardController::BoardController(std::shared_ptr<BoardService> boardService)
    : boardService_(boardService) {};

void BoardController::getBoardsByUser(const Pistache::Rest::Request &req,
                                      Pistache::Http::ResponseWriter resp) {
  User user;
  user.id = req.param(":id").as<int>();
  std::vector<std::shared_ptr<Board>> boards =
      boardService_->getBoardsByUser(user);

  nlohmann::json j = boards;

  resp.send(Pistache::Http::Code::Ok, j.dump());
}
