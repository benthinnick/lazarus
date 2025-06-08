#pragma once

#include "../models/board.h"
#include "../models/user.h"
#include "db.h"
#include <memory>
#include <vector>

class BoardRepository {
public:
  BoardRepository(std::shared_ptr<ConnectionPool> db);
  virtual std::vector<std::shared_ptr<Board>> getBoardsByUser(User user);

private:
  std::shared_ptr<ConnectionPool> connectionPool_;
};
