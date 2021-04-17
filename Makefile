# Project Name
TARGET = jackoscillator

# Sources
CPP_SOURCES = main.cpp
CPP_SOURCES += WTFOscillator.cpp

# Library Locations
LIBDAISY_DIR = /Users/jack.nolan/Developer/DaisyExamples/libdaisy
DAISYSP_DIR = /Users/jack.nolan/Developer/DaisyExamples/DaisySP

# Core location, and generic Makefile.
SYSTEM_FILES_DIR = $(LIBDAISY_DIR)/core
include $(SYSTEM_FILES_DIR)/Makefile