#include "boardService.h"
#include <memory>

BoardService::BoardService(std::shared_ptr<BoardRepository> boardRepository)
    : boardRepository_(boardRepository) {}

std::vector<std::shared_ptr<Board>> BoardService::getBoardsByUser(User user) {
  return boardRepository_->getBoardsByUser(user);
}
