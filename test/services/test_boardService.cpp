#include "../../src/db/boardRepository.h"
#include "../../src/services/boardService.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <memory>

class MockRepository : public BoardRepository {
public:
  MockRepository() : BoardRepository(nullptr) {};
  MOCK_METHOD(std::vector<std::shared_ptr<Board>>, getBoardsByUser, (User user),
              (override));
};
class BoardServiceTest : public testing::Test {
protected:
  BoardService bs_ = BoardService(std::make_shared<MockRepository>());

  void TearDown() override {}
};

TEST_F(BoardServiceTest, getBoardsByUserWork) {
  EXPECT_NE(&bs_, nullptr);
  User user = {
      12,
      "testUser",
      "pwdHash",
  };

  std::vector<std::shared_ptr<Board>> boards = bs_.getBoardsByUser(user);
}
