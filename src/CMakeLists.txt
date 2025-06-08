set(SOURCES
    main.cpp
    controllers/taskController.cpp
    controllers/boardController.cpp
    services/boardService.cpp
    db/boardRepository.cpp
    db/db.cpp
    routes/router.cpp
)
#Find each required library using pkg-config
pkg_check_modules(LIBPQXX REQUIRED IMPORTED_TARGET libpqxx)
pkg_check_modules(PISTACHE REQUIRED IMPORTED_TARGET libpistache)
pkg_check_modules(JSON REQUIRED IMPORTED_TARGET nlohmann_json)
pkg_check_modules(YAML REQUIRED IMPORTED_TARGET yaml-cpp)


add_executable(app ${SOURCES})
# Link libraries to the target
target_link_libraries(app
    PRIVATE PkgConfig::LIBPQXX
    PRIVATE PkgConfig::PISTACHE
    PRIVATE PkgConfig::JSON
    PRIVATE PkgConfig::YAML
)

add_library(lazaruslib ${SOURCES})
target_link_libraries(lazaruslib
    PUBLIC PkgConfig::LIBPQXX
    PUBLIC PkgConfig::PISTACHE
    PUBLIC PkgConfig::JSON
    PUBLIC PkgConfig::YAML
)


