TARGET_LIB ?= libcubic-protocol.a

CXX	?=	gcc

BUILD_DIR := build
SRC_DIRS := src

SRCS := $(shell find $(SRC_DIRS) -name '*.cpp')

OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

DEPS := $(OBJS:.o=.d)

INC_DIRS := $(SRC_DIRS) include
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
CXXFLAGS += -march=native -mtune=native
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
CXXFLAGS += -fno-exceptions

AR := ar

ARFLAGS := rc

ifeq ($(DEBUG), 1)
        CXXFLAGS += -O0 -ggdb
else
        CXXFLAGS += -O3 -flto -DNDEBUG
endif

ifeq ($(ASAN), 1)
        CXXFLAGS += -fsanitize=address,leak,undefined
endif

$(TARGET_LIB): $(BUILD_DIR)/$(TARGET_LIB)
	cp $(BUILD_DIR)/$(TARGET_LIB) $(TARGET_LIB)

$(BUILD_DIR)/$(TARGET_LIB): $(OBJS)
	$(AR) $(ARFLAGS) $@ $(OBJS)

$(BUILD_DIR)/%.cpp.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)

.PHONY: fclean
fclean: clean
	rm -f $(TARGET_LIB)

.PHONY: re
re: fclean
	$(MAKE) $(TARGET_LIB)

.PHONY: all
all: $(TARGET_LIB)

-include $(DEPS)
