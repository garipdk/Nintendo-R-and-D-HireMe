cmake_minimum_required(VERSION 3.9.6)

project(HireMe LANGUAGES C)
#set(CMAKE_VERBOSE_MAKEFILE TRUE)
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_C_COMPILER gcc)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
file(GLOB HIREME_SOURCES *.c)

find_package(OpenMP)



if(OpenMP_C_FOUND)

endif()

if(MSVC)
  add_executable(HireMe.exe HireMe_main.c "${HIREME_SOURCES}")
  target_link_libraries(HireMe.exe m)
  target_compile_options(HireMe.exe PRIVATE /W4 /WX /Wno-unknown-pragmas)

  add_executable(HireMe_dbg.exe HireMe_main.c "${HIREME_SOURCES}")
  target_link_libraries(HireMe_dbg.exe m)
  target_compile_options(HireMe_dbg.exe PRIVATE /W4 /WX /Wno-unknown-pragmas /g)

  if(OpenMP_C_FOUND)
    add_executable(HireMe_omp.exe HireMe_main.c "${HIREME_SOURCES}")
    target_link_libraries(HireMe_omp.exe PRIVATE m OpenMP::OpenMP_C)
    target_compile_options(HireMe_omp.exe PRIVATE /W4 /WX)

    add_executable(HireMe_omp_dbg.exe HireMe_main.c "${HIREME_SOURCES}")
    target_link_libraries(HireMe_omp_dbg.exe PRIVATE m OpenMP::OpenMP_C)
    target_compile_options(HireMe_omp_dbg.exe PRIVATE /W4 /WX/g)
  endif()
else()
  add_executable(HireMe HireMe_main.c "${HIREME_SOURCES}")
  target_link_libraries(HireMe m)
  target_compile_options(HireMe PRIVATE -Wall -Wextra -Werror -Wno-unknown-pragmas)

  add_executable(HireMe_dbg HireMe_main.c "${HIREME_SOURCES}")
  target_link_libraries(HireMe_dbg m)
  target_compile_options(HireMe_dbg PRIVATE -Wall -Wextra -Werror -Wno-unknown-pragmas -g)

  add_executable(HireMe_mn HireMe_main.c "${HIREME_SOURCES}")
  target_link_libraries(HireMe_mn m)
  target_compile_options(HireMe_mn PRIVATE -Wall -Wextra -Werror -Wno-unknown-pragmas -march=native)

  add_executable(HireMe_Ofast HireMe_main.c "${HIREME_SOURCES}")
  target_link_libraries(HireMe_Ofast m)
  target_compile_options(HireMe_Ofast PRIVATE -Wall -Wextra -Werror -Wno-unknown-pragmas -Ofast)

  add_executable(HireMe_O3 HireMe_main.c "${HIREME_SOURCES}")
  target_link_libraries(HireMe_O3 m)
  target_compile_options(HireMe_O3 PRIVATE -Wall -Wextra -Werror -Wno-unknown-pragmas -O3)


  add_executable(HireMe_Ofast_mn HireMe_main.c "${HIREME_SOURCES}")
  target_link_libraries(HireMe_Ofast_mn m)
  target_compile_options(HireMe_Ofast_mn PRIVATE -Wall -Wextra -Werror -Wno-unknown-pragmas -Ofast -march=native)

  add_executable(HireMe_O3_mn HireMe_main.c "${HIREME_SOURCES}")
  target_link_libraries(HireMe_O3_mn m)
  target_compile_options(HireMe_O3_mn PRIVATE -Wall -Wextra -Werror -Wno-unknown-pragmas -O3 -march=native)


  if(OpenMP_C_FOUND)
    add_executable(HireMe_omp HireMe_main.c "${HIREME_SOURCES}")
    target_link_libraries(HireMe_omp PRIVATE m OpenMP::OpenMP_C)
    target_compile_options(HireMe_omp PRIVATE -Wall -Wextra -Werror)
    
    add_executable(HireMe_omp_dbg HireMe_main.c "${HIREME_SOURCES}")
    target_link_libraries(HireMe_omp_dbg PRIVATE m OpenMP::OpenMP_C)
    target_compile_options(HireMe_omp_dbg PRIVATE -Wall -Wextra -Werror -g)

    add_executable(HireMe_mn_omp HireMe_main.c "${HIREME_SOURCES}")
    target_link_libraries(HireMe_mn_omp PRIVATE m OpenMP::OpenMP_C)
    target_compile_options(HireMe_mn_omp PRIVATE -Wall -Wextra -Werror -march=native)

    add_executable(HireMe_Ofast_omp HireMe_main.c "${HIREME_SOURCES}")
    target_link_libraries(HireMe_Ofast_omp PRIVATE m OpenMP::OpenMP_C)
    target_compile_options(HireMe_Ofast_omp PRIVATE -Wall -Wextra -Werror -Ofast)

    add_executable(HireMe_O3_omp HireMe_main.c "${HIREME_SOURCES}")
    target_link_libraries(HireMe_O3_omp PRIVATE m OpenMP::OpenMP_C)
    target_compile_options(HireMe_O3_omp PRIVATE -Wall -Wextra -Werror -O3)

    add_executable(HireMe_Ofast_mn_omp HireMe_main.c "${HIREME_SOURCES}")
    target_link_libraries(HireMe_Ofast_mn_omp PRIVATE m OpenMP::OpenMP_C)
    target_compile_options(HireMe_Ofast_mn_omp PRIVATE -Wall -Wextra -Werror -Ofast -march=native)

    add_executable(HireMe_O3_mn_omp HireMe_main.c "${HIREME_SOURCES}")
    target_link_libraries(HireMe_O3_mn_omp PRIVATE m OpenMP::OpenMP_C)
    target_compile_options(HireMe_O3_mn_omp PRIVATE -Wall -Wextra -Werror -O3 -march=native)
  endif()
endif()



