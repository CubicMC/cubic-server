TARGET_EXEC ?= CubicServer

CXX	?=	gcc

BUILD_DIR := build
SRC_DIRS := cubic-server

SRCS := $(shell find $(SRC_DIRS) -name '*.cpp')

OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

DEPS := $(OBJS:.o=.d)

INC_DIRS := $(SRC_DIRS)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CPPFLAGS := $(INC_FLAGS) -MMD -MP

CXXFLAGS := -Wall
CXXFLAGS += -Wextra
CXXFLAGS += -Wconversion
CXXFLAGS += -std=c++17
CXXFLAGS += -Wp,-U_FORTIFY_SOURCE
CXXFLAGS += -Wformat=2
CXXFLAGS += -MMD -MP
# This needs to be reactivated once we know how it f****** works :3
# CXXFLAGS += -fanalyzer
CXXFLAGS += -fno-builtin
CXXFLAGS += -pipe
CXXFLAGS += -O2 -march=native -mtune=native
CXXFLAGS += -Wcast-qual
CXXFLAGS += -Wconversion
CXXFLAGS += -Wdisabled-optimization
CXXFLAGS += -Wduplicated-branches
CXXFLAGS += -Wduplicated-cond
CXXFLAGS += -Werror=return-type
CXXFLAGS += -Werror=vla-larger-than=0
CXXFLAGS += -Winit-self
CXXFLAGS += -Winline
CXXFLAGS += -Wlogical-op
CXXFLAGS += -Wredundant-decls
CXXFLAGS += -Wshadow
CXXFLAGS += -Wsuggest-attribute=pure
CXXFLAGS += -Wsuggest-attribute=const
CXXFLAGS += -Wundef
CXXFLAGS += -Wunreachable-code
CXXFLAGS += -Wwrite-strings
CXXFLAGS += -Wno-missing-field-initializers

ifeq ($(DEBUG), 1)
	CXXFLAGS	+=	-ggdb
endif

LDFLAGS	:=

$(TARGET_EXEC): $(BUILD_DIR)/$(TARGET_EXEC)
	cp $(BUILD_DIR)/$(TARGET_EXEC) $(TARGET_EXEC)

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.cpp.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)

.PHONY: fclean
fclean: clean
	rm -f $(TARGET_EXEC)
	rm -f $(TARGET_EXEC_TESTS)

.PHONY: re
re: fclean
	$(MAKE) $(TARGET_EXEC)

.PHONY: all
all: $(TARGET_EXEC)

-include $(DEPS)
