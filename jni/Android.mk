LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := physicalSimulationTool

LOCAL_SRC_FILES := Main.cpp Controller.cpp \
physics.engine/MainEngine.cpp \
physics.engine/NDC.cpp \
physics.engine/Selection.cpp \
library.graphic/MainGraphic.cpp \
library.graphic/Shader.cpp \
library.collision/Contact.cpp \
library.collision/ContactResolver.cpp \
library.collision/FineCollision.cpp \
library.collision/MainCollision.cpp \
library.collision/Octree.cpp \
common/CommonStructures.cpp \
common/Particle.cpp \
common/RigidBody.cpp \
common/SimulatedObject.cpp \
common/Utils.cpp \
common/World.cpp \
library.physics/ForceGenerators.cpp \
library.physics/MainPhysics.cpp \
#library.physics/ParticleForceGenerators.cpp
#library.physics/TorqueGenerators.cpp
#library.collision/ParticleContact.cpp
#library.collision/ParticleLinks.cpp
#library.collision/QuadTree.cpp

LOCAL_CPP_EXTENSION := .cpp
LOCAL_LDLIBS  := -landroid -llog -lEGL -lGLESv1_CM -lOpenSLES -lGLESv2

LOCAL_CPP_INCLUDES += $(LOCAL_PATH)/common
LOCAL_CPP_INCLUDES += $(LOCAL_PATH)/library.collision
LOCAL_CPP_INCLUDES += $(LOCAL_PATH)/library.graphic
LOCAL_CPP_INCLUDES += $(LOCAL_PATH)/library.physics
LOCAL_CPP_INCLUDES += $(LOCAL_PATH)/physics.engine


#LOCAL_SRC_FILES += $(LOCAL_PATH)/common/*.cpp
#LOCAL_SRC_FILES += $(LOCAL_PATH)/library.collision/*.cpp
#LOCAL_SRC_FILES += $(LOCAL_PATH)/library.graphic/*.cpp
#LOCAL_SRC_FILES += $(LOCAL_PATH)/library.physics/*.cpp
#LOCAL_SRC_FILES += $(LOCAL_PATH)/physics.engine/*.cpp


#LOCAL_CFLAGS += -DANDROID_NDK
#LOCAL_CFLAGS += -DDISABLE_IMPORTGL
#LOCAL_CPP_FEATURES := rtti features exceptions
#LOCAL_C_INCLUDES := sources/foo
#LOCAL_C_INCLUDES := $(LOCAL_PATH)/../foo
#LOCAL_CFLAGS / LOCAL_CPPFLAGS
#LOCAL_ARM_NEON  := true
 

include $(BUILD_SHARED_LIBRARY)
