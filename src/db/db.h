#pragma once

#include <pqxx/pqxx>

class Db {
public:
  Db(int);
  ~Db();
  std::shared_ptr<pqxx::connection> getConnection(int t);

private:
  std::vector<std::shared_ptr<pqxx::connection>> connection_pool_;
};
