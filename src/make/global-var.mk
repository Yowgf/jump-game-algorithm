# ALG1-TP1 project Makefile
# Global variables custom definitions.
# ==============================================================

GLOBAL_VAR_LIST := CXX FLAGS HEADER APPLIANCE BUILD \
  MODULES HEADER_EXTENSION APP_EXTENSION OBJECT_EXTENSION \
  EXECUTABLE_EXTENSION

# Compiler flags
CXX   := g++
FLAGS := -std=c++11 -Wall

# Directories
SOURCE_VAL_NAMES := HEADER APPLIANCE BUILD
# Directory of header files
HEADER      := header
# Directory of appliance files (e.g. ~.cpp~)
APPLIANCE   := appliance
# Directory of compiled files
BUILD       := build

# Source directory
SOURCE := src

# Project's modules
MODULES := 

# Files extensions
HEADER_EXTENSION     := hpp
APP_EXTENSION        := cpp
OBJECT_EXTENSION     := o
EXECUTABLE_EXTENSION := exe
