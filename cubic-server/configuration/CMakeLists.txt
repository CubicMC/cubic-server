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

target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC yaml-cpp::yaml-cpp)
