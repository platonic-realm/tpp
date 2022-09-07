cmake_minimum_required(VERSION 3.5)

add_library(tppcore STATIC
            async/event_handler.hpp
            async/event_handler.cpp
            collector/detail/detail_interface.hpp
            collector/process/process_interface.hpp
            collector/system/system_interface.hpp
            collector/task/task_interface.hpp
            event/init.hpp
            event/init.cpp
            storage/storag_interface.hpp)