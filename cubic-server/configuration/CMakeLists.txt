# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found. Any number of sources could be listed here.
target_sources (
    ${CMAKE_PROJECT_NAME} PRIVATE
    ConfigHandler.cpp
    ConfigHandler.hpp
    ArgumentHolder.cpp
    ArgumentHolder.hpp
    ArgumentsParser.cpp
    ArgumentsParser.hpp
    conversion.hpp
    errors.hpp
    Node.hpp
    Node.cpp
    Value.hpp
    Value.cpp
)

# add_executable(test_config)
# target_link_libraries(test_config argparse yaml-cpp)
# target_include_directories(test_config PRIVATE ..)
# target_sources(test_config PRIVATE
#     ConfigHandler.cpp
#     ConfigHandler.hpp
#     ArgumentHolder.cpp
#     ArgumentHolder.hpp
#     ArgumentsParser.cpp
#     ArgumentsParser.hpp
#     conversion.hpp
#     errors.hpp
#     Node.hpp
#     Value.hpp
#     Value.cpp
# )

target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC yaml-cpp::yaml-cpp)
