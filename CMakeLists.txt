cmake_minimum_required(VERSION 3.27)
project(Particles-Simulation)
set(CMAKE_CXX_STANDARD 17)

add_executable(Particles-Simulation
        main.cpp
        main.h
        main.h
        Particle.cpp
        Particle.h
)

set(SFML_DIR "/opt/homebrew/Cellar/sfml/2.6.1/lib/cmake/ParticleSFML")

find_package(SFML 2.6.1 COMPONENTS graphics audio network system window REQUIRED)

include_directories(${SFML_INCLUDE_DIR})

target_link_libraries(Particles-Simulation sfml-graphics sfml-audio sfml-network sfml-system sfml-window)