#pragma once

#include <pqxx/pqxx>

struct Connection {
  int id;
  std::shared_ptr<pqxx::connection> conn;
  Connection(int id, std::shared_ptr<pqxx::connection> conn)
      : id(id), conn(conn) {}
};

class ConnectionPoolImpl;

class ConnectionPool {
public:
  ConnectionPool(std::string connectionString, int maxConnections);
  ~ConnectionPool();
  Connection getConnection();
  void returnConnection(int id);

private:
  std::unique_ptr<ConnectionPoolImpl> impl;
};

class ScopedConnection {
public:
  ScopedConnection(Connection conn,
                   std::shared_ptr<ConnectionPool> connectionPool)
      : conn(conn), connectionPool_(connectionPool) {}
  ~ScopedConnection() { connectionPool_->returnConnection(conn.id); }

  Connection conn;

private:
  std::shared_ptr<ConnectionPool> connectionPool_;
};
