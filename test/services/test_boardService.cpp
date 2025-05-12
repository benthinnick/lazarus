#pragma once

#include "../../src/services/boardService.h"
#include <gtest/gtest.h>

class BoardServiceTest : public testing::Test {
protected:
  BoardServiceTest() {}

  BoardService bs;
};
