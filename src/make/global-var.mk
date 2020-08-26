# File Handler project Makefile
# Global variables custom definitions.
# ==============================================================

GLOBAL_VAR_LIST := CXX FLAGS HEADER APPLIANCE BUILD THIRD_PARTY \
  MODULOS HEADER_EXTENSION APP_EXTENSION OBJECT_EXTENSION \
  EXECUTABLE_EXTENSION

# Compiler flags
CXX   := g++
FLAGS := -std=c++11 -Wall

# Directories
# Diretorio de arquivos hpp
HEADER      := header
# Diretorio de arquivos arquivos cpp
APPLIANCE   := appliance
# Diretorio de arquivos compilados
BUILD       := build
# Diretorio de codigo third-party utilizado
THIRD_PARTY := third-party

# Source directory
SOURCE := src

# Modulos do programa
MODULOS := Safety

# Extensao de arquivos para windows
HEADER_EXTENSION     := hpp
APP_EXTENSION        := cpp
OBJECT_EXTENSION     := o
EXECUTABLE_EXTENSION := exe
