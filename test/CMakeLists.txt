# Add test executable
set(TESTSOURCES
  test_main.cpp
  services/test_boardService.cpp
)
add_executable(test_main ${TESTSOURCES})

include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

FetchContent_MakeAvailable(googletest)

target_link_libraries(test_main PRIVATE gtest gmock)
# Link your application libraries
target_link_libraries(test_main PRIVATE lazaruslib)

# Enable tests
include(GoogleTest)
gtest_discover_tests(test_main)
