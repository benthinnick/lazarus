#include "boardRepository.h"
#include "db.h"
#include <memory>

BoardRepository::BoardRepository(std::shared_ptr<ConnectionPool> db)
    : connectionPool_(db) {}

std::vector<std::shared_ptr<Board>>
BoardRepository::getBoardsByUser(User user) {
  ScopedConnection conn(connectionPool_->getConnection(), connectionPool_);

  pqxx::work tx(*conn.conn.conn.get());

  tx.commit();

  pqxx::result rez = tx.exec_params(
      "SELECT id, name, owner_id FROM public.boards WHERE owner_id=$1", user.id);

  std::vector<std::shared_ptr<Board>> boards;
  for (auto const &row : rez) {
    Board b;
    b.id = row[0].num();
    b.name = row[1].c_str();
    b.ownerId = row[2].num();
    boards.push_back(std::make_shared<Board>(std::move(b)));
  }

  return boards;
}
