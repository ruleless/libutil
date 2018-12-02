set (BIN util.utest)
include_directories ("..")
# target_include_directories (util.utest PRIVATE ".")

aux_source_directory (. SOURCE)
add_executable (${BIN} ${SOURCE})
target_link_libraries (${BIN} gtest pthread)
