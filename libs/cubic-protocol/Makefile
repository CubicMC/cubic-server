TARGET_LIB ?= libcubic-protocol.a

TARGET_TESTS ?= glados

CXX	?=	gcc

BUILD_DIR := build
BUILD_DIR_TESTS := build_tests
SRC_DIRS := src

SRCS := $(shell find $(SRC_DIRS) -name '*.cpp')

OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

OBJS_TESTS := $(SRCS:%=$(BUILD_DIR_TESTS)/%.o)

DEPS := $(OBJS:.o=.d)

LIB_FOLDERS := $(shell ls -d ../../libs/*/)

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

AR := ar

ARFLAGS := rcsPv

LDFLAGS :=

ifeq ($(DEBUG), 1)
        CXXFLAGS += -Og -ggdb
else
        CXXFLAGS += -O3 -DNDEBUG
endif

ifeq ($(LTO), 1)
        CXXFLAGS += -flto
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

$(TARGET_LIB): $(BUILD_DIR)/$(TARGET_LIB)
	cp $(BUILD_DIR)/$(TARGET_LIB) $(TARGET_LIB)

$(BUILD_DIR)/$(TARGET_LIB): $(OBJS)
	$(AR) $(ARFLAGS) $@ $(OBJS)

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

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)
	rm -rf $(BUILD_DIR_TESTS)

.PHONY: fclean
fclean: clean
	rm -f $(TARGET_LIB)
	rm -f $(TARGET_TESTS)

.PHONY: re
re: fclean
	$(MAKE) $(TARGET_LIB)

.PHONY: all
all: $(TARGET_LIB)

.PHONY: tests_run
tests_run: $(TARGET_TESTS)
	./$(TARGET_TESTS)

-include $(DEPS)
