project (BattleCity)

# set include dirs
set (PRIVATE_INCLUDE_DIRS
	"${PROJECT_SOURCE_DIR}/include")

# set source files
set (SRC_DIRS
		"${PROJECT_SOURCE_DIR}/src"
		"${PROJECT_SOURCE_DIR}/src/model"
		"${PROJECT_SOURCE_DIR}")

foreach (src_dir ${SRC_DIRS})
	file(GLOB srcs ${src_dir}/*.cpp)
	set(SRC_LIST ${SRC_LIST} ${srcs})
endforeach()
message("SRC_LIST: ${SRC_LIST}")
include_directories(${PRIVATE_INCLUDE_DIRS})
add_executable(BattleCity ${SRC_LIST})