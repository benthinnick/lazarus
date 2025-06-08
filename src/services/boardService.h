#pragma once

#include "../db/boardRepository.h"
class BoardService {
public:
  BoardService(std::shared_ptr<BoardRepository> boardRepository);
  std::vector<std::shared_ptr<Board>> getBoardsByUser(User user);
private:
    std::shared_ptr<BoardRepository> boardRepository_;
};
