#pragma once
#include <string>

struct Task {
  int id;
  int listId;
  std::string title;
  std::string description;
  int position;
};
