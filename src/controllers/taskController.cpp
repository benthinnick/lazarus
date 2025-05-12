#include "taskController.h"
#include <pistache/http.h>

TaskController::TaskController() {}

TaskController::~TaskController() {}

void TaskController::getTasks(const Pistache::Rest::Request &req,
                              Pistache::Http::ResponseWriter response) {
  response.send(Pistache::Http::Code::Ok, "Hello, World, bitch");
}
