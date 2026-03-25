cmake_minimum_required(VERSION 3.5)
project(baseSwitcherAPI_test CXX)

# Crée l'exécutable de test
add_executable(${PROJECT_NAME} test_main.cc test_convert.cpp)

# Inclure le dossier src pour voir les headers
target_include_directories(${PROJECT_NAME} PRIVATE ../src)

# Lier le fichier source contenant from_X_to_10
target_sources(${PROJECT_NAME} PRIVATE ../src/convert.cpp)

# Lier Drogon
target_link_libraries(${PROJECT_NAME} PRIVATE Drogon::Drogon)

ParseAndAddDrogonTests(${PROJECT_NAME})