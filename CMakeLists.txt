cmake_minimum_required(
    VERSION 3.9
)

project(
    CourseWork_1
    VERSION 1.0
    DESCRIPTION "Курсовая работа студента группы М3О-101Б-23 Блинкова Владимира на тему 'Информационно-поисковая система на очереди'"
    LANGUAGES CXX
)

add_executable(bin src/tests_typehxx.cxx src/types.hxx)