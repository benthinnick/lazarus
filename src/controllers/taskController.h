#pragma once
#include <pistache/endpoint.h>
#include <pistache/http.h>
#include <pistache/router.h>
class TaskController {

public:
  TaskController();
  ~TaskController();

  void getTasks(const Pistache::Rest::Request &req,
                Pistache::Http::ResponseWriter);

  void createTask(const Pistache::Rest::Request &req,
                  Pistache::Http::ResponseWriter);
};
