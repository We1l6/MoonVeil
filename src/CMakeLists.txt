project(template_module LANGUAGES CXX)

set(MAIN_SOURCES
    "main.cpp")

set(MAIN_HEADERS
    "main.h")
        
add_executable(template
  ${MAIN_SOURCES}
  ${MAIN_HEADERS}
)

target_link_libraries(template PRIVATE spdlog::spdlog)

add_subdirectory("calculator")

if(ENABLE_SANITIZE_ADDR OR ENABLE_SANITIZE_UNDEF)
    include(Sanitizers)
    #add_sanitizer_flags()
endif()

if(${ENABLE_WARNINGS})
    target_set_warnings(
        template
        ${ENABLE_WARNINGS}
        ${ENABLE_WARNINGS_AS_ERRORS}
    )
endif()
