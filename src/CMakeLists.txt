cmake_minimum_required(VERSION 3.9.6)

project(HireMe LANGUAGES C)

set(CMAKE_VERBOSE_MAKEFILE TRUE)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_C_COMPILER gcc)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_compile_definitions("RELEASE=$<CONFIG:Release>:OE_RELEASE")
if(MSVC)
elseif(CMAKE_C_COMPILER_ID  STREQUAL "GNU")
  message("Killer flags !")
  set(CMAKE_C_FLAGS_RELEASE -DNDEBUG -Ofast -fmerge-all-constants -fmodulo-sched -fmodulo-sched-allow-regmoves -fgcse-sm -fgcse-las -fdevirtualize-speculatively -fdevirtualize-at-ltrans -fsched-pressure -fsched-spec-load -fsched-spec-load-dangerous -fsched-stalled-insns=0 -freschedule-modulo-scheduled-loops -fselective-scheduling -fselective-scheduling2 -fsel-sched-pipelining -fsel-sched-pipelining-outer-loops -fipa-pta -floop-nest-optimize -ftree-loop-im -ftree-loop-ivcanon -fivopts -ftree-vectorize -fvect-cost-model=cheap -fprefetch-loop-arrays -freorder-blocks-and-partition -funroll-loops -ffunction-sections -fdata-sections -fstdarg-opt -fuse-linker-plugin -flto -march=native -mtune=native)
  message("Killer flags (release)!")
  set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} ${CMAKE_C_FLAGS_RELEASE} -fwhole-program)

  include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
  file(GLOB HIREME_SOURCES *.c)
  add_executable(HireMe HireMe_main.c "${HIREME_SOURCES}")
  target_compile_options(HireMe PRIVATE -Wall -Wextra -Werror -Wno-unknown-pragmas)

  add_executable(HireMe_dbg HireMe_main.c "${HIREME_SOURCES}")
  target_compile_options(HireMe_dbg PRIVATE -Wall -Wextra -Werror -Wno-unknown-pragmas -g)

  add_executable(HireMe_mn HireMe_main.c "${HIREME_SOURCES}")
  target_compile_options(HireMe_mn PRIVATE -Wall -Wextra -Werror -Wno-unknown-pragmas -march=native)

  add_executable(HireMe_Ofast HireMe_main.c "${HIREME_SOURCES}")
  target_compile_options(HireMe_Ofast PRIVATE -Wall -Wextra -Werror -Wno-unknown-pragmas -Ofast)

  add_executable(HireMe_O3 HireMe_main.c "${HIREME_SOURCES}")
  target_compile_options(HireMe_O3 PRIVATE -Wall -Wextra -Werror -Wno-unknown-pragmas -O3)


  add_executable(HireMe_Ofast_mn HireMe_main.c "${HIREME_SOURCES}")
  target_compile_options(HireMe_Ofast_mn PRIVATE -Wall -Wextra -Werror -Wno-unknown-pragmas -Ofast -march=native)

  add_executable(HireMe_O3_mn HireMe_main.c "${HIREME_SOURCES}")
  target_compile_options(HireMe_O3_mn PRIVATE -Wall -Wextra -Werror -Wno-unknown-pragmas -O3 -march=native)

  add_executable(HireMe_realease HireMe_main.c "${HIREME_SOURCES}")
  target_link_libraries(HireMe_realease ${CMAKE_EXE_LINKER_FLAGS})
  target_compile_options(HireMe_realease PRIVATE "${CMAKE_C_FLAGS_RELEASE}")

  find_package(OpenMP)
  if(OpenMP_C_FOUND)
    add_executable(HireMe_omp HireMe_main.c "${HIREME_SOURCES}")
    target_link_libraries(HireMe_omp PRIVATE OpenMP::OpenMP_C)
    target_compile_options(HireMe_omp PRIVATE -Wall -Wextra -Werror)
    
    add_executable(HireMe_omp_dbg HireMe_main.c "${HIREME_SOURCES}")
    target_link_libraries(HireMe_omp_dbg PRIVATE OpenMP::OpenMP_C)
    target_compile_options(HireMe_omp_dbg PRIVATE -Wall -Wextra -Werror -g)

    add_executable(HireMe_mn_omp HireMe_main.c "${HIREME_SOURCES}")
    target_link_libraries(HireMe_mn_omp PRIVATE OpenMP::OpenMP_C)
    target_compile_options(HireMe_mn_omp PRIVATE -Wall -Wextra -Werror -march=native)

    add_executable(HireMe_Ofast_omp HireMe_main.c "${HIREME_SOURCES}")
    target_link_libraries(HireMe_Ofast_omp PRIVATE OpenMP::OpenMP_C)
    target_compile_options(HireMe_Ofast_omp PRIVATE -Wall -Wextra -Werror -Ofast)

    add_executable(HireMe_O3_omp HireMe_main.c "${HIREME_SOURCES}")
    target_link_libraries(HireMe_O3_omp PRIVATE OpenMP::OpenMP_C)
    target_compile_options(HireMe_O3_omp PRIVATE -Wall -Wextra -Werror -O3)

    add_executable(HireMe_Ofast_mn_omp HireMe_main.c "${HIREME_SOURCES}")
    target_link_libraries(HireMe_Ofast_mn_omp PRIVATE OpenMP::OpenMP_C)
    target_compile_options(HireMe_Ofast_mn_omp PRIVATE -Wall -Wextra -Werror -Ofast -march=native)

    add_executable(HireMe_O3_mn_omp HireMe_main.c "${HIREME_SOURCES}")
    target_link_libraries(HireMe_O3_mn_omp PRIVATE OpenMP::OpenMP_C)
    target_compile_options(HireMe_O3_mn_omp PRIVATE -Wall -Wextra -Werror -O3 -march=native)

    add_executable(HireMe_realease_omp HireMe_main.c "${HIREME_SOURCES}")
    target_link_libraries(HireMe_realease_omp OpenMP::OpenMP_C ${CMAKE_EXE_LINKER_FLAGS})
    target_compile_options(HireMe_realease_omp PRIVATE "${CMAKE_C_FLAGS_RELEASE}")
  endif()
endif()



