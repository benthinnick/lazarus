#include "db.h"
#include <deque>
#include <pqxx/connection.hxx>

class ConnectionPoolImpl {
public:
  ConnectionPoolImpl(std::string connectionString, int maxConnection);
  Connection getConnection();
  void returnConnection(int connectionId);

private:
  std::vector<std::shared_ptr<pqxx::connection>> connection_pool_;
  std::deque<int> freeConnections;
};

ConnectionPoolImpl::ConnectionPoolImpl(std::string connectionString,
                                       int maxConnections) {
  connection_pool_ =
      std::vector<std::shared_ptr<pqxx::connection>>(maxConnections);

  freeConnections = std::deque<int>();

  for (int i = 0; i < maxConnections; i++) {
    connection_pool_[i] = std::make_shared<pqxx::connection>(connectionString);
    freeConnections.push_back(i);
  }
}

Connection ConnectionPoolImpl::getConnection() {
  int ci = freeConnections.front();
  freeConnections.pop_back();
  return Connection(ci, connection_pool_[ci]);
}

void ConnectionPoolImpl::returnConnection(int connectionId) {
  freeConnections.push_back(connectionId);
}

ConnectionPool::ConnectionPool(std::string connectionString, int maxConnections)
    : impl(std::make_unique<ConnectionPoolImpl>(connectionString,
                                                maxConnections)) {}
ConnectionPool::~ConnectionPool() {
}

Connection ConnectionPool::getConnection() { return impl->getConnection(); }

void ConnectionPool::returnConnection(int id) {
  return impl->returnConnection(id);
}
