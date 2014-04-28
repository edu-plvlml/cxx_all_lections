# uniMakefile v0.2.4 by Pavel 'M4E5TR0' Matcula
# 0.2.1: fixed module dependencies for fortran objects
# 0.2.2: fixed 'check-syntax' target for emacs flymake
# 0.2.3: fixed bug with makedepf90 used w/o arguments
# 0.2.4: fixed unnecessary builds on 'clean' target

# To be customized
NAME := lections

# Can be customized: binary, static or shared
TARGET_TYPE := binary

# Can be configured: release or debug
BUILD_TYPE ?= release

# Can be configured: gcc, clang or intel
TOOLCHAIN ?= gcc

# To be customized for external libraries
INCLUDE_DIRS := 
LIB_DIRS := 
LIBS := 

# GNU Makefile Conventions (7.2.5)
# To be customized for internal structure
srcdir := ./

# To be customized for internal structure
INCLUDE_DIR := ./
BUILD_DIR ?= ./obj
BIN_DIR := ./bin
LIB_DIR := ./lib

CXXFLAGS += -std=c++11

ifeq ($(TOOLCHAIN),intel)
FFLAGS += -real-size 64
else
FFLAGS += -fdefault-real-8
endif

# GNU Makefile Conventions (7.2.1)
SHELL ?= /bin/sh
.SUFFIXES:

# GNU Makefile Conventions (7.2.3)
INSTALL ?= /bin/install
INSTALL_PROGRAM ?= $(INSTALL)
INSTALL_DATA ?= $(INSTALL) -m 644

# GNU Makefile Conventions (7.2.4)
DESTDIR ?= 

# GNU Makefile Conventions (7.2.5)
prefix ?= /usr/local
exec_prefix ?= $(prefix)
includedir ?= $(prefix)/include
bindir ?= $(exec_prefix)/bin
libdir ?= $(exec_prefix)/lib

SRCS.c := $(wildcard $(srcdir)/*.c)
SRCS.cc := $(wildcard $(srcdir)/*.cc)
SRCS.cpp := $(wildcard $(srcdir)/*.cpp)
SRCS.f := $(wildcard $(srcdir)/*.f)
SRCS.F := $(wildcard $(srcdir)/*.F)

FILTER_OUT = $(foreach FILE,$(2),$(if $(findstring $(1),$(FILE)),,$(FILE)))

OBJ_SRCS := $(SRCS.c) $(SRCS.cc) $(SRCS.cpp) $(SRCS.f) $(SRCS.F)
OBJ_SRCS := $(call FILTER_OUT,__SEMANTIC,$(OBJ_SRCS))
OBJ_SRCS := $(call FILTER_OUT,_flymake,$(OBJ_SRCS))

MOD_SRCS := $(SRCS.f) $(SRCS.F)
MOD_SRCS := $(call FILTER_OUT,__SEMANTIC,$(MOD_SRCS))
MOD_SRCS := $(call FILTER_OUT,_flymake,$(MOD_SRCS))

DEP_SRCS := $(SRCS.c) $(SRCS.cc) $(SRCS.cpp)
DEP_SRCS := $(call FILTER_OUT,__SEMANTIC,$(DEP_SRCS))
DEP_SRCS := $(call FILTER_OUT,_flymake,$(DEP_SRCS))

OBJS := $(addsuffix .o,$(basename $(subst $(srcdir)/,$(BUILD_DIR)/,$(OBJ_SRCS))))
MODS := $(addsuffix .mod,$(basename $(subst $(srcdir)/,$(BUILD_DIR)/,$(MOD_SRCS))))
DEPS := $(addsuffix .d,$(basename $(subst $(srcdir)/,$(BUILD_DIR)/,$(DEP_SRCS))))

ifneq ($(MOD_SRCS),)
DEPS += $(BUILD_DIR)/dependencies
endif

CPPFLAGS += -I$(INCLUDE_DIR)
CPPFLAGS += $(foreach DIR,$(INCLUDE_DIRS),-I$(DIR))
LDFLAGS += $(foreach DIR,$(LIB_DIRS),-L$(DIR))
LDLIBS += $(foreach LIB,$(LIBS),-l$(LIB))

ifeq ($(TOOLCHAIN),intel)
FFLAGS += -module $(BUILD_DIR)
else
FFLAGS += -J$(BUILD_DIR)
endif

ifeq ($(TOOLCHAIN),gcc)
CC := cc
CXX := g++
FC := gfortran
LDLIBS += -lgfortran
endif

ifeq ($(TOOLCHAIN),intel)
CC := icc
CXX := icpc
FC := ifort
LDLIBS += -lifcore
endif

ifeq ($(TOOLCHAIN),clang)
CC := clang
CXX := clang++
CXXFLAGS += -std=libc++
FC := gfortran
LDLIBS += -lc++abi -lgfortran
endif

ifeq ($(BUILD_TYPE),release)
CFLAGS += -O2
CXXFLAGS += -O2
FFLAGS += -O2
endif

ifeq ($(BUILD_TYPE),debug)
CFLAGS += -O0 -g
CXXFLAGS += -O0 -g
FFLAGS += -O0 -g
endif

ifeq ($(TARGET_TYPE),shared)
CFLAGS += -fPIC
CXXFLAGS += -fPIC
FFLAGS += -fPIC
endif

ifeq ($(TARGET_TYPE),binary)
TARGET_NAME := $(NAME)
TARGET_DIR := $(BIN_DIR)
endif

ifeq ($(TARGET_TYPE),static)
TARGET_NAME := lib$(NAME).a
TARGET_DIR := $(LIB_DIR)
endif

ifeq ($(TARGET_TYPE),shared)
TARGET_NAME := lib$(NAME).so
TARGET_DIR := $(LIB_DIR)
endif

TARGET := $(TARGET_DIR)/$(TARGET_NAME)

# GNU Makefile Conventions (7.2.6)
.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJS) | $(TARGET_DIR)
ifeq ($(TARGET_TYPE),binary)
	$(LINK.cc) -o $@ $^ $(LDLIBS)
endif
ifeq ($(TARGET_TYPE),static)
	$(AR) rc $@ $?
endif
ifeq ($(TARGET_TYPE),shared)
	$(LINK.cc) -shared -o $@ $^ $(LDLIBS)
endif

$(BUILD_DIR)/%.o: $(srcdir)/%.c | $(BUILD_DIR)
	$(COMPILE.c) -o $@ $<
$(BUILD_DIR)/%.d: $(srcdir)/%.c | $(BUILD_DIR)
	-@$(COMPILE.c) -E > /dev/null -MMD -MF $@ $< -MP

$(BUILD_DIR)/%.o: $(srcdir)/%.cc | $(BUILD_DIR)
	$(COMPILE.cc) -o $@ $<
$(BUILD_DIR)/%.d: $(srcdir)/%.cc | $(BUILD_DIR)
	-@$(COMPILE.cc) -E > /dev/null -MMD -MF $@ $< -MP

$(BUILD_DIR)/%.o: $(srcdir)/%.cpp | $(BUILD_DIR)
	$(COMPILE.cpp) -o $@ $<
$(BUILD_DIR)/%.d: $(srcdir)/%.cpp | $(BUILD_DIR)
	-@$(COMPILE.cpp) -E > /dev/null -MMD -MF $@ $< -MP

$(BUILD_DIR)/%.o $(BUILD_DIR)/%.mod: $(srcdir)/%.f | $(BUILD_DIR)
	$(COMPILE.F) -o $(BUILD_DIR)/$*.o $<

$(BUILD_DIR)/%.o $(BUILD_DIR)/%.mod: $(srcdir)/%.F | $(BUILD_DIR)
	$(COMPILE.f) -o $(BUILD_DIR)/$*.o $<

$(BUILD_DIR)/dependencies: $(MOD_SRCS) | $(BUILD_DIR)
	makedepf90 > $@ $^ -b $(BUILD_DIR) -m "%m.mod"

$(BUILD_DIR) $(BIN_DIR) $(LIB_DIR):
	mkdir -p $@

ifndef SYNTAX_CHECK_MODE
-include $(DEPS)
endif

.PHONY: all-tags
all-tags: etags ctags gtags ebrowse cscope

.PHONY: etags
etags: TAGS
# GNU Makefile Conventions (7.2.6)
TAGS:  $(OBJ_SRCS)
	etags $(srcdir)/*

.PHONY: ctags
ctags: tags
tags: $(OBJ_SRCS)
	ctags $(srcdir)/*

.PHONY: gtags
gtags: GTAGS
GTAGS: $(OBJ_SRCS)
	gtags

.PHONY: ebrowse
ebrowse: BROWSE
BROWSE: $(OBJ_SRCS)
	ebrowse $(srcdir)/*

.PHONY: cscope
cscope: cscope.out
cscope.out: $(OBJ_SRCS)
	cscope -b $(srcdir)/*

# GNU Makefile Conventions (7.2.6)
.PHONY: install
install:

# GNU Makefile Conventions (7.2.6)
.PHONY: uninstall
uninstall:

# GNU Makefile Conventions (7.2.6)
.PHONY: clean
clean:
	-rm -f $(DEPS)
	-rm -f $(MODS)
	-rm -f $(OBJS)
	-rm -f $(TARGET)

.PHONY: check-syntax
check-syntax: COMPILE.h := $(COMPILE.cc)
check-syntax:
#	$(COMPILE$(suffix $(CHK_SOURCES))) -fsyntax-only $(CHK_SOURCES) -Wall
	$(foreach CHK_SOURCE, $(CHK_SOURCES), \
	  $(COMPILE$(suffix $(CHK_SOURCE))) -fsyntax-only $(CHK_SOURCE) -Wall ; \
	)
