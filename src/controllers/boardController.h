#pragma once

#include "../services/boardService.h"

#include <pistache/endpoint.h>
#include <pistache/http.h>
#include <pistache/router.h>

class BoardController {
public:
  BoardController(std::shared_ptr<BoardService> boardService);
  void getBoardsByUser(const Pistache::Rest::Request &req,
                       Pistache::Http::ResponseWriter);

private:
  std::shared_ptr<BoardService> boardService_;
};
