cmake_minimum_required(VERSION 3.27)
project(Particles-Simulation)
set(CMAKE_CXX_STANDARD 17)
# Créer un exécutable pour le projet
add_executable(Particles-Simulation
        main.cpp
        main.h
        main.h
        Particle.cpp
        Particle.h
)
# Définir le chemin vers les modules CMake de SFML
set(SFML_DIR "/opt/homebrew/Cellar/sfml/2.6.1/lib/cmake/ParticleSFML")
# Trouver les paquets SFML nécessaires
find_package(SFML 2.6.1 COMPONENTS graphics audio network system window REQUIRED)
# Inclure les répertoires d'en-tête SFML
include_directories(${SFML_INCLUDE_DIR})
# Lier les bibliothèques SFML à l'exécutable de votre projet
target_link_libraries(Particles-Simulation sfml-graphics sfml-audio sfml-network sfml-system sfml-window)