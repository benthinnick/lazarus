#pragma once
#include <nlohmann/json.hpp>
#include <string>

struct Board {
  int id;
  std::string name;
  int ownerId;
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(Board, id, name, ownerId)
};
