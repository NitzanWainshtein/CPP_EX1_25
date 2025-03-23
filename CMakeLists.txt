cmake_minimum_required(VERSION 3.10)
project(GraphProject)

set(CMAKE_CXX_STANDARD 11)

# לוודא שהקבצים נמצאים בפרויקט
include_directories(.)

# יצירת קובץ הפעלה בשם "main"
add_executable(main main.cpp Graph.cpp)
