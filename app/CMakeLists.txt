cmake_minimum_required(VERSION 3.4.1)

add_library(simulationLibrary
            SHARED
            src/main/cpp/Main.cpp
            src/main/cpp/Controller.cpp
            src/main/cpp/engine/MainEngine.cpp
            src/main/cpp/engine/NDC.cpp
            src/main/cpp/engine/Selection.cpp
            src/main/cpp/graphic/MainGraphic.cpp
            src/main/cpp/graphic/Shader.cpp
            src/main/cpp/collision/Contact.cpp
            src/main/cpp/collision/ContactResolver.cpp
            src/main/cpp/collision/FineCollision.cpp
            src/main/cpp/collision/MainCollision.cpp
            src/main/cpp/collision/Octree.cpp
            src/main/cpp/common/CommonStructures.cpp
            src/main/cpp/common/Particle.cpp
            src/main/cpp/common/RigidBody.cpp
            src/main/cpp/common/SimulatedObject.cpp
            src/main/cpp/common/Utils.cpp
            src/main/cpp/common/World.cpp
            src/main/cpp/physics/ForceGenerators.cpp
            src/main/cpp/physics/MainPhysics.cpp)

include_directories(src/main/cpp/)

target_link_libraries(simulationLibrary
                      GLESv2
                      android
                      EGL
                      log)
