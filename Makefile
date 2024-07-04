TARGET_EXEC ?= CubicServer

TARGET_TESTS ?= glados

CXX	?=	gcc

BUILD_DIR := build
BUILD_DIR_TESTS := build_tests
SRC_DIRS := cubic-server

SRCS := $(shell find $(SRC_DIRS) -name '*.cpp')

OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

OBJS_TESTS := $(SRCS:%=$(BUILD_DIR_TESTS)/%.o)

DEPS := $(OBJS:.o=.d)

LIB_FOLDERS := $(shell ls -d libs/*/)

INC_DIRS := $(SRC_DIRS) $(addsuffix include,$(LIB_FOLDERS))
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CPPFLAGS := $(INC_FLAGS) -MMD -MP

CXXFLAGS := -Wall
CXXFLAGS += -Wextra
CXXFLAGS += -Wconversion
CXXFLAGS += -std=c++17
CXXFLAGS += -Wp,-U_FORTIFY_SOURCE
CXXFLAGS += -Wformat=2
CXXFLAGS += -MMD -MP
CXXFLAGS += -fno-builtin
CXXFLAGS += -pipe
CXXFLAGS += -march=native -mtune=native
CXXFLAGS += -Wcast-qual
CXXFLAGS += -Wconversion
CXXFLAGS += -Wdisabled-optimization
CXXFLAGS += -Werror=return-type
CXXFLAGS += -Winit-self
CXXFLAGS += -Winline
CXXFLAGS += -Wredundant-decls
CXXFLAGS += -Wshadow
CXXFLAGS += -Wundef
CXXFLAGS += -Wunreachable-code
CXXFLAGS += -Wwrite-strings
CXXFLAGS += -Wno-missing-field-initializers

ifeq ($(CXX), g++)
CXXFLAGS += -Wduplicated-branches
CXXFLAGS += -Wduplicated-cond
CXXFLAGS += -Werror=vla-larger-than=0
CXXFLAGS += -Wlogical-op
endif

LDFLAGS	:= -Llibs/cubic-protocol -lcubic-protocol

# TODO: Set this up in a more generic way
NEEDED_LIBS := libs/cubic-protocol/libcubic-protocol.a

ifeq ($(DEBUG), 1)
        CXXFLAGS += -Og -ggdb
else
        CXXFLAGS += -O3 -DNDEBUG
        LDFLAGS += -s
endif

ifeq ($(LTO), 1)
        CXXFLAGS += -flto
		# This will break with DEBUG=1, but who the hell builds with
		# LTOs and debug at the same time?
		# I could also make it throw an error if DEBUG and LTO are activated
		# at the same time but for now this will do
        LDFLAGS += -flto -O3
endif

ifeq ($(ASAN), 1)
        CXXFLAGS += -fsanitize=address,leak,undefined
        LDFLAGS += -fsanitize=address,leak,undefined
endif

# -fanalyzer is quite broken in g++, deactivate by default
ifeq ($(ANALYZER), 1)
ifeq ($(CXX), g++)
	CXXFLAGS += -fanalyzer
	CXXFLAGS += -Wno-analyzer-use-of-uninitialized-value
endif
endif

.PHONY: all
all:
	$(MAKE) all-libs
	$(MAKE) $(TARGET_EXEC)

.PHONY: tests_run
tests_run:
	$(MAKE) all-libs
	$(MAKE) tests_run-libs
	$(MAKE) $(TARGET_TESTS)
	./$(TARGET_TESTS)

$(TARGET_EXEC): $(BUILD_DIR)/$(TARGET_EXEC)
	cp $(BUILD_DIR)/$(TARGET_EXEC) $(TARGET_EXEC)

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS) $(NEEDED_LIBS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

$(TARGET_TESTS): $(BUILD_DIR_TESTS)/$(TARGET_TESTS)
	cp $(BUILD_DIR_TESTS)/$(TARGET_TESTS) $(TARGET_TESTS)

$(BUILD_DIR_TESTS)/$(TARGET_TESTS): CPPFLAGS += -DUNIT_TESTS=1
$(BUILD_DIR_TESTS)/$(TARGET_TESTS): CXXFLAGS += --coverage
$(BUILD_DIR_TESTS)/$(TARGET_TESTS): LDFLAGS += -lcriterion --coverage
$(BUILD_DIR_TESTS)/$(TARGET_TESTS): $(OBJS_TESTS) $(NEEDED_LIBS)
	$(CXX) $(OBJS_TESTS) -o $@ $(LDFLAGS)

$(BUILD_DIR_TESTS)/%.cpp.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/%.cpp.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

.PHONY: all-libs
all-libs: $(LIB_FOLDERS)
	$(MAKE) -C $^ all

.PHONY: tests_run-libs
tests_run-libs: $(LIB_FOLDERS)
	$(MAKE) -C $^ tests_run

.PHONY: clean-libs
clean-libs: $(LIB_FOLDERS)
	$(MAKE) -C $^ clean

.PHONY: fclean-libs
fclean-libs: $(LIB_FOLDERS)
	$(MAKE) -C $^ fclean

.PHONY: clean
clean: clean-libs
	rm -rf $(BUILD_DIR)
	rm -rf $(BUILD_DIR_TESTS)

.PHONY: fclean
fclean: fclean-libs clean
	rm -f $(TARGET_EXEC)
	rm -f $(TARGET_TESTS)

.PHONY: re
re: fclean
	$(MAKE) all

-include $(DEPS)
