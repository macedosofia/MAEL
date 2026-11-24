add_executable(test_character_energy
    test_character_energy.cpp
    ../src/character.cpp
    ../src/map.cpp
)

target_include_directories(test_character_energy PRIVATE ../include)

target_link_libraries(test_character_energy PRIVATE raylib)

add_test(NAME character_energy COMMAND test_character_energy)
